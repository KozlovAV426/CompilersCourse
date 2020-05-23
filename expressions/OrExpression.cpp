#include "OrExpression.h"


OrExpression::OrExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv)
    : lhv(lhv)
    , rhv(rhv)
{}

int OrExpression::Eval() const {
  return lhv->Eval() || rhv->Eval();
}

void OrExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}