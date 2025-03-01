#pragma once

#include <filesystem>

bool compileShaderToSpirV(std::string shaderName, std::string shaderSource,
                          std::filesystem::path dstPath, bool isFragment);
bool compileShaderToySnippetToSpirVFragment(std::filesystem::path srcPath,
                                            std::filesystem::path dstPath);
