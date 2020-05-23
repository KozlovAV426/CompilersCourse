#pragma once
#include "Expression.h"
#include <memory>

class LengthExpression: public Expression {
public:
  LengthExpression(std::shared_ptr<Expression> expr);
  int Eval() const override;
  void Accept(Visitor* visitor) override;
  std::shared_ptr<Expression> expr;
};