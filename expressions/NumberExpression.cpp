#include "NumberExpression.h"

NumberExpression::NumberExpression(int value) : value(value) {}

int NumberExpression::Eval() const {
    return value;
}

void NumberExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}