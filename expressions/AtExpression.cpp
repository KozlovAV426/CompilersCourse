#include "AtExpression.h"


AtExpression::AtExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv)
    : lhv(lhv)
    , rhv(rhv)
{}

int AtExpression::Eval() const {
}

void AtExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}