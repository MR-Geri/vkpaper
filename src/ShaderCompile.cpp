#include <ShaderCompile.hpp>

#include <DefaultShaders.hpp>
#include <FileUtils.hpp>

#include <shaderc/shaderc.h>
#include <shaderc/shaderc.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>

bool compileShaderToSpirV(std::string shaderName, std::string shaderSource,
                          std::filesystem::path dstPath, bool isFragment) {
  std::cout << "Compiling shader " << shaderName << "...\n";

  auto compiler = shaderc::Compiler{};
  auto compileOptions = shaderc::CompileOptions{};
  compileOptions.SetOptimizationLevel(
      shaderc_optimization_level::shaderc_optimization_level_performance);

  const auto shaderType =
      isFragment ? shaderc_fragment_shader : shaderc_vertex_shader;
  const auto result = compiler.CompileGlslToSpv(
      shaderSource.data(), shaderSource.size(), shaderType, shaderName.c_str());

  if (result.GetCompilationStatus() !=
      shaderc_compilation_status::shaderc_compilation_status_success) {

    const auto sourceWithLineNumbers = addLineNumbers(shaderSource);
    std::cout << "Shader compilation failed for " << shaderName << "\n"
              << "Shader source:\n"
              << sourceWithLineNumbers << "\n"
              << "Error message:\n"
              << result.GetErrorMessage();
    return false;
  }

  std::ofstream f(dstPath, std::ios::binary);
  for (auto it = result.begin(); it != result.end(); ++it) {
    f.write(reinterpret_cast<const char *>(it), sizeof(*it));
  }

  return true;
}

bool compileShaderToySnippetToSpirVFragment(std::filesystem::path srcPath,
                                            std::filesystem::path dstPath) {

  const auto shaderToySource = readFile(srcPath);
  if (!shaderToySource.has_value()) {
    return false;
  }
  const auto compositedShaderSrc =
      fragmentPre + *shaderToySource + fragmentPost;
  const auto shaderName = srcPath.filename().string();

  return compileShaderToSpirV(srcPath.string(), compositedShaderSrc, dstPath,
                              true);
}
