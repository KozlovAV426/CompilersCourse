#include "ModuloExpression.h"

ModuloExpression::ModuloExpression(std::shared_ptr<Expression> left,
                                   std::shared_ptr<Expression> right)
                                   : left(left)
                                   , right(right) {}


int ModuloExpression::Eval() const {
  return left->Eval() % right->Eval();
}

void ModuloExpression::Accept(Visitor *visitor) {
  //visitor->Visit(this);
}