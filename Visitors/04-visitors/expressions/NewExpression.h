#pragma once
#include "Expression.h"
#include <memory>

class NewExpression : public Expression {
public:
  NewExpression(std::string type);
  int Eval() const override;
  void Accept(Visitor* visitor) override;
  std::string type;
};