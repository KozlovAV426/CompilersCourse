#include "ArrayIdentifier.h"//
// Created by anatoly on 11.03.2020.
//


ArrayIdentifier::ArrayIdentifier(const std::string &id,
                                 std::shared_ptr<Expression> expr)
                                 : identifier(id)
                                 , expr(expr)
                                 {}

void ArrayIdentifier::Accept(Visitor *visitor) {
  visitor->Visit(this);
}