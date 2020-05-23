#pragma once

#include "Object.h"

class Integer: public Object {
 public:
    explicit Integer(int value, bool array);
    int ToInt() override;
  std::pair<std::string, bool> GetType() override;
  bool is_array;
 private:
    int value_;
};