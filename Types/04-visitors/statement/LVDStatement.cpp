#include "LVDStatement.h"

LVDStatement::LVDStatement(std::string type, bool array, const std::string &id)
: type(type)
, identifier(id)
, is_array(array)
{}

void LVDStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}