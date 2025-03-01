#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

std::optional<std::string> readFile(std::filesystem::path path);
std::optional<std::vector<char>> readBinaryFile(std::filesystem::path path);
