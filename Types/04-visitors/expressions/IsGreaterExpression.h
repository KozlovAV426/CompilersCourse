#pragma once
#include "Expression.h"
#include <memory>

class IsGreaterExpression: public Expression {
public:
  IsGreaterExpression(std::shared_ptr<Expression> lhv,
                std::shared_ptr<Expression> rhv);
  int Eval() const override;
  void Accept(Visitor* visitor) override;
  std::shared_ptr<Expression> lhv;
  std::shared_ptr<Expression> rhv;
};