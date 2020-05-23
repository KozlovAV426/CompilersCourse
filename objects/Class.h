#pragma once

#include "Object.h"

class ClassType: public Object {
public:
  explicit ClassType(std::string type, bool array);
  Class ToClass () override;
  std::pair<std::string, bool> GetType() override;
  std::string type;
  bool is_array;
};