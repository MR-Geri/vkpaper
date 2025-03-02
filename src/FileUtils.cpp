#include <FileUtils.hpp>

#include <fstream>
#include <iostream>
#include <string>

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

  const auto fileSize = std::filesystem::file_size(path);

  std::string result(fileSize, '\0');
  f.read(result.data(), fileSize);

  return result;
}

std::optional<std::vector<char>> readBinaryFile(std::filesystem::path path) {
  if (!std::filesystem::exists(path)) {
    std::cerr << "Could not find file " << path.string() << "\n";
    return {};
  }

  std::ifstream f(path, std::ios::binary);
  if (!f.is_open() || !f.good()) {
    std::cerr << "Could not open file " << path.string() << "\n";
    return {};
  }

  const auto fileSize = std::filesystem::file_size(path);

  std::vector<char> buffer(fileSize);
  f.read(buffer.data(), fileSize);

  return buffer;
}

std::string addLineNumbers(std::string input) {
  constexpr auto delimiter = '\n';
  auto result = std::string{};

  std::string::size_type pos = 0;
  std::string::size_type prev = 0;
  int i = 1;
  while ((pos = input.find(delimiter, prev)) != std::string::npos) {
    auto line = input.substr(prev, pos - prev);
    prev = pos + 1;

    result += std::to_string(i) + "\t" + line + delimiter;
    i++;
  }

  auto lastLine = input.substr(prev);
  result += std::to_string(i) + "\t" + lastLine + delimiter;
  return result;
}
