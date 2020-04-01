#include "CertainType.h"

CertainType::CertainType(const std::string &type, bool is_array)
: type(type)
, is_array(is_array)
{}


void CertainType::Accept(Visitor *visitor) {
  visitor->Visit(this);
}