#include "SubstractExpression.h"

SubstractExpression::SubstractExpression(std::shared_ptr<Expression> lhv,
      std::shared_ptr<Expression> rhv)
      : lhv(lhv)
      , rhv(rhv)
      {}

int SubstractExpression::Eval() const {
    return lhv->Eval() - rhv->Eval();
}

void SubstractExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}