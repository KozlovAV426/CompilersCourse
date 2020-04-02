#include "NewExpression.h"

NewExpression::NewExpression(std::string type)
    : type(type)
{}

int NewExpression::Eval() const {
}

void NewExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}