#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(const std::string &type, const std::string &id)
    : type(type)
    , identifier(id)
    {}

void VarDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}