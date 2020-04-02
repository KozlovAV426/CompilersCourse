#include "MulExpression.h"

MulExpression::MulExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv)
    : lhv(lhv)
    , rhv(rhv) {}

int MulExpression::Eval() const {
    return lhv->Eval() * rhv->Eval();
}

void MulExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}