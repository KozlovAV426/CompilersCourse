#include "IsGreaterExpression.h"


IsGreaterExpression::IsGreaterExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv)
    : lhv(lhv)
    , rhv(rhv)
{}

int IsGreaterExpression::Eval() const {
  return lhv->Eval() > rhv->Eval();
}

void IsGreaterExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}