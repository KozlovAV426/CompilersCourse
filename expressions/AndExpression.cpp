#include "AndExpression.h"


AndExpression::AndExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv)
                             : lhv(lhv)
                             , rhv(rhv)
                             {}

int AndExpression::Eval() const {
  return lhv->Eval() && rhv->Eval();
}

void AndExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}