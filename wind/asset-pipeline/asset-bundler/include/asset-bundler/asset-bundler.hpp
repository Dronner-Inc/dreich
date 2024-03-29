#pragma once
#define WIND_PIPE_WRITE

#include <utils/utils.h>
#include <utils/yaml-utils.h>

#include <filesystem>

#include <yaml-cpp/node/node.h>
#include <yaml-cpp/yaml.h>

#include "pipes/pipe.hpp"
#include "pipes/pipes-register.hpp"

namespace wind {
namespace asset_pipeline {

class AssetPipeline {
public:
  void linkDirectory(const fs::path& source, const fs::path& destination);
  void compileDirectory(const fs::path& source, const fs::path& destination);
  void compileFile(const fs::path& source, const fs::path& destination, AssetPipe* pipe);
  void clearUnusedCache(const fs::path& source, const fs::path& cache);
  void setConfig(const fs::path& config);

  void build(const fs::path& source);

private:
  void preprocessing(const fs::path& path, YAML::Node& options);
  fs::recursive_directory_iterator createRecursiveIterator(const fs::path& path);
  YAML::Node findConfigForPath(const fs::path& path);

  YAML::Node m_importConfig;
};

} // namespace asset_pipeline
} // namespace wind