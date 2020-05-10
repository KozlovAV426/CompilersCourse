#include "Boolean.h"

Boolean::Boolean(bool value, bool array) : value_(value), is_array(array) {}

bool Boolean::ToBoolean() { return value_;
}

std::pair<std::string, bool> Boolean::GetType() { return {"boolean", is_array};
}