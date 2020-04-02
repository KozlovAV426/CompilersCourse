#include "InBrExpression.h"

InBrExpression::InBrExpression(std::shared_ptr<Expression> expr)
    : expr(expr)
{}

int InBrExpression::Eval() const {
}

void InBrExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}