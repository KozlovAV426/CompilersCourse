#include "LVDStatement.h"

LVDStatement::LVDStatement(const std::string &type, const std::string &id)
: type(type)
, identifier(id)
{}

void LVDStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}