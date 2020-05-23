#include "IdentifierExpression.h"

IdentifierExpression::IdentifierExpression(const std::string& identifier)
  : identifier(identifier)
  {}

int IdentifierExpression::Eval() const {
}

void IdentifierExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}