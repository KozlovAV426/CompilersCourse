#include "DivExpression.h"

DivExpression::DivExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv)
    : lhv(lhv)
    , rhv(rhv) {}

int DivExpression::Eval() const {
    return lhv->Eval() / rhv->Eval();
}

void DivExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}