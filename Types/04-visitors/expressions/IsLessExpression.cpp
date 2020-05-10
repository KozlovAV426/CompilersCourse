#include "IsLessExpression.h"


IsLessExpression::IsLessExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv)
    : lhv(lhv)
    , rhv(rhv)
{}

int IsLessExpression::Eval() const {
  return lhv->Eval() < rhv->Eval();
}

void IsLessExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}