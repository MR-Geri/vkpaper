#pragma once

#include <filesystem>

bool compileShaderToSpirV(std::string shaderName, std::string shaderSource,
                          std::filesystem::path spirvOutputPath,
                          bool isFragment);
bool compileShaderToySnippetToSpirVFragment(
    std::filesystem::path srcPath, std::filesystem::path spirvOutputPath);
bool compileTransitionShaderToSpirVFragment(
    std::filesystem::path transitionShader, std::filesystem::path srcShader,
    std::filesystem::path targetShader, std::filesystem::path spirvOutputPath);