#include "NewArrayExpression.h"

NewArrayExpression::NewArrayExpression(std::string type,
    std::shared_ptr<Expression> expr)
    : type(type)
    , expr(expr)
{}

int NewArrayExpression::Eval() const {
}

void NewArrayExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}