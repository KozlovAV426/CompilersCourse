#pragma once
#include "Expression.h"

class NumberExpression: public Expression {
public:
    explicit NumberExpression(int value);
    int Eval() const override;
    void Accept(Visitor* visit) override;

    int value;
};