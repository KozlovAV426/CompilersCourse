#include "IsEqualExpression.h"


IsEqualExpression::IsEqualExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv)
    : lhv(lhv)
    , rhv(rhv)
{}

int IsEqualExpression::Eval() const {
  return lhv->Eval() == rhv->Eval();
}

void IsEqualExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}