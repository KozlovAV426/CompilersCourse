#include "LengthExpression.h"


LengthExpression::LengthExpression(std::shared_ptr<Expression> expr)
    : expr (expr)
{}

int LengthExpression::Eval() const {
}

void LengthExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}