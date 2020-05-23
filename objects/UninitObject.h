#pragma once

#include "Object.h"


class UninitObject: public Object {
 public:
    // explicit Integer(int value);
    UninitObject(std::string types, bool array);
    int ToInt() override;
  std::pair<std::string, bool> GetType() override;
    // int value_;
    std::string type;
    bool is_array;
};