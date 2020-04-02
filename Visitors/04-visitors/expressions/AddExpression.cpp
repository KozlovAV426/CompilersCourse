#include "AddExpression.h"

AddExpression::AddExpression(std::shared_ptr<Expression> lhv,
                             std::shared_ptr<Expression> rhv)
                             : lhv(lhv)
                             , rhv(rhv) {}

int AddExpression::Eval() const {
    return lhv->Eval() + rhv->Eval();
}

void AddExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}