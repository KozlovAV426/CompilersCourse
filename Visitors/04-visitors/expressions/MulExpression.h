#pragma once
#include "Expression.h"
#include <memory>

class MulExpression: public Expression {
 public:
    MulExpression(std::shared_ptr<Expression> lhv,
                  std::shared_ptr<Expression> rhv);
    int Eval() const override;
    void Accept(Visitor* visitor) override;

    std::shared_ptr<Expression> lhv;
    std::shared_ptr<Expression> rhv;
};