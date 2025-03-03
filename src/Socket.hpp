#pragma once

#include <filesystem>
#include <functional>
#include <iostream>
#include <thread>

#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

void initializeSocket(std::function<std::string(std::string)> callback) {
  std::thread([callback]() {
    const auto vkpaperSocket = socket(AF_UNIX, SOCK_STREAM, 0);

    if (vkpaperSocket < 0) {
      std::cerr << "Could not initialized socket. Disabling IPC...\n";
      return;
    }

    sockaddr_un addr = {.sun_family = AF_UNIX};
    const auto runtimeDir = getenv("XDG_RUNTIME_DIR");

    if (!runtimeDir) {
      std::cerr << "$XDG_RUNTIME_DIR is not set. Disabling IPC...\n";
      return;
    }

    const auto socketDir = std::filesystem::path{runtimeDir};
    const auto socketFile = socketDir / "vkpaper.sock";
    unlink(socketFile.c_str());
    strcpy(addr.sun_path, socketFile.c_str());

    bind(vkpaperSocket, (sockaddr *)&addr, SUN_LEN(&addr));
    listen(vkpaperSocket, 10);

    char readBuffer[1024] = {0};
    std::cout << "Started vkpaper socket at " << socketFile << ", "
              << vkpaperSocket << "\n";
    for (;;) {
      sockaddr clientAddress = {};
      socklen_t clientSize = sizeof(clientAddress);
      const auto connection =
          accept(vkpaperSocket, &clientAddress, &clientSize);

      if (connection < 0) {
        std::cerr << "Reading from socket failed. Aborting IPC thread...";
        break;
      } else {
        do {
          //   std::cout << "Accepted incoming IPC connection...\n";

          auto messageSize = read(connection, readBuffer, 1024);
          readBuffer[messageSize == 1024 ? 1023 : messageSize] = '\0';
          if (messageSize == 0)
            break;

          const auto request = std::string{readBuffer};
          const auto response = callback(request);

          write(connection, response.c_str(), response.length());
        } while (1);
        // std::cout << "Closing IPC connection...\n";
        close(connection);
      }
    }
  }).detach();
}
