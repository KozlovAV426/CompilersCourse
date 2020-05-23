#pragma once
#include "Expression.h"
#include <memory>

class ThisExpression : public Expression {
public:
  ThisExpression() = default;
  int Eval() const override;
  void Accept(Visitor* visitor) override;
};