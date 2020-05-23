#include "UninitObject.h"

#include <stdexcept>

UninitObject::UninitObject(std::string types, bool array)
    : type(std::move(types))
    , is_array(array) {}

int UninitObject::ToInt() {
  throw std::runtime_error("Variable not initialized");
}
std::pair<std::string, bool> UninitObject::GetType() { return {type, is_array};
}