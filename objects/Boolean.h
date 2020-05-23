#pragma once

#include "Object.h"

class Boolean : public Object {
public:
  explicit Boolean(bool value, bool array);
  bool ToBoolean() override;
  std::pair<std::string, bool> GetType() override;
  bool is_array;
private:
  bool value_;
};