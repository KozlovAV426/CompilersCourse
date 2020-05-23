#include "NegExpression.h"

NegExpression::NegExpression(std::shared_ptr<Expression> expr)
  : expr(expr)
  {}

int NegExpression::Eval() const {
}

void NegExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}