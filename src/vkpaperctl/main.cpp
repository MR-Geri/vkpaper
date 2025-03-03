#include <args.hxx>

#include <filesystem>
#include <iostream>

#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

int main(int argc, char **argv) {
  args::ArgumentParser parser("vkpaperctl");
  args::Group commands(parser, "commands");

  args::Command switchTo(commands, "switch",
                         "switch to a new effect immediately");
  args::Command transitionTo(
      commands, "transition",
      "transition to a new effect using a transition shader");
  args::Group arguments(parser, "arguments", args::Group::Validators::DontCare,
                        args::Options::Global);
  args::Positional<std::string> effectFile(
      arguments, "effect",
      "The shader file (Shadertoy format) to set as the background");
  args::ValueFlag<std::string> transitionShader(
      arguments, "transition shader",
      "The transition shader file to use for animating the new shader",
      {'t', "transition-shader"});
  args::ValueFlag<std::string> iChannel0{arguments,
                                         "iChannel0",
                                         "Input image to use as iChannel0",
                                         {'0', "iChannel0"}};
  args::ValueFlag<std::string> iChannel1{arguments,
                                         "iChannel1",
                                         "Input image to use as iChannel1",
                                         {'1', "iChannel1"}};
  args::ValueFlag<std::string> iChannel2{arguments,
                                         "iChannel2",
                                         "Input image to use as iChannel2",
                                         {'2', "iChannel2"}};
  args::ValueFlag<std::string> iChannel3{arguments,
                                         "iChannel3",
                                         "Input image to use as iChannel3",
                                         {'3', "iChannel3"}};
  args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});

  try {
    parser.ParseCLI(argc, argv);
  } catch (const args::Completion &e) {
    std::cout << e.what();
    return 0;
  } catch (const args::Help &) {
    std::cout << parser;
    return 0;
  } catch (const args::ParseError &e) {
    std::cerr << e.what() << std::endl;
    std::cerr << parser;
    return 1;
  }

  if (!effectFile) {
    std::cout << parser;
    return 0;
  }

  const auto vkpaperSocket = socket(AF_UNIX, SOCK_STREAM, 0);

  if (vkpaperSocket < 0) {
    std::cerr << "Could not initialized socket. Disabling IPC...\n";
    return 1;
  }

  sockaddr_un addr = {.sun_family = AF_UNIX};
  const auto runtimeDir = getenv("XDG_RUNTIME_DIR");

  if (!runtimeDir) {
    std::cerr << "$XDG_RUNTIME_DIR is not set. Disabling IPC...\n";
    return 1;
  }

  const auto socketDir = std::filesystem::path{runtimeDir};
  const auto socketFile = socketDir / "vkpaper.sock";

  strcpy(addr.sun_path, socketFile.c_str());

  if (connect(vkpaperSocket, (sockaddr *)&addr, sizeof(addr)) == -1) {
    std::cerr << "Could not connect to socket " << socketFile << std::endl;
    return 1;
  }

  auto ipcCommand = std::string{};
  if (switchTo) {
    ipcCommand = "switch ";
  } else if (transitionTo) {
    if (!transitionShader) {
      std::cerr << "No transition shader given for transition command"
                << std::endl;
      exit(1);
    }
    const auto absoluteTransitionShaderPath = std::filesystem::canonical(
        std::filesystem::absolute(*transitionShader));

    ipcCommand = "transition ";
    ipcCommand += absoluteTransitionShaderPath.string();
    ipcCommand += " ";
  }

  const auto absoluteEffectPath =
      std::filesystem::canonical(std::filesystem::absolute(*effectFile));
  ipcCommand += absoluteEffectPath;
  ipcCommand += " ";
  ipcCommand += iChannel0 ? *iChannel0 : "x";
  ipcCommand += " ";
  ipcCommand += iChannel1 ? *iChannel1 : "x";
  ipcCommand += " ";
  ipcCommand += iChannel2 ? *iChannel2 : "x";
  ipcCommand += " ";
  ipcCommand += iChannel3 ? *iChannel3 : "x";
  ipcCommand += "\n";

  if (write(vkpaperSocket, ipcCommand.c_str(), ipcCommand.size()) < 0) {
    std::cerr << "Failed to write to socket " << socketFile << std::endl;
    return 1;
  }

  const size_t buflen = 1024;
  int n;
  char response[buflen + 1];

  n = read(vkpaperSocket, response, buflen);
  if (n < 0) {
    return 1;
  } else {
    response[n] = 0;
  }

  if (strcmp(response, "Ok") == 0) {
    return 0;
  } else {
    std::cerr << response << std::endl;
    return 1;
  }
}
