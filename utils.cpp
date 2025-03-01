#include "utils.h"

#include <fstream>
#include <iostream>

std::optional<std::string> readFile(std::filesystem::path path) {

  if (!std::filesystem::exists(path)) {
    std::cerr << "Could not find file " << path.string() << "\n";
    return {};
  }

  std::ifstream f(path, std::ios::in);
  if (!f.is_open() || !f.good()) {
    std::cerr << "Could not open file " << path.string() << "\n";
    return {};
  }

  const auto sz = std::filesystem::file_size(path);

  std::string result(sz, '\0');
  f.read(result.data(), sz);

  return result;
}

std::optional<std::vector<char>> readBinaryFile(std::filesystem::path path) {

  if (!std::filesystem::exists(path)) {
    std::cerr << "Could not find file " << path.string() << "\n";
    return {};
  }

  std::ifstream file(path, std::ios::ate | std::ios::binary);

  size_t fileSize = (size_t)file.tellg();
  std::vector<char> buffer(fileSize);

  file.seekg(0);
  file.read(buffer.data(), fileSize);
  file.close();

  return buffer;
}
