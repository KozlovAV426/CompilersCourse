#pragma once

#include "Object.h"
#include <declaration/VarDeclaration.h>
#include <memory>

class MethodType: public Object {
public:
  explicit MethodType(
      const std::string &t, const std::string &id,
      const std::vector<std::shared_ptr<VarDeclaration>> &input);
  MethodType() = default;
  Method ToMethod () override;
  std::pair<std::string, bool> GetType() override;
  std::vector<std::shared_ptr<VarDeclaration>> var_list;
  std::string name;
  std::string type;
  bool is_array;
};