#pragma once
#include "Expression.h"
#include <memory>

class NegExpression : public Expression {
public:
  NegExpression(std::shared_ptr<Expression> expr);
  int Eval() const override;
  void Accept(Visitor* visitor) override;
  std::shared_ptr<Expression> expr;
};