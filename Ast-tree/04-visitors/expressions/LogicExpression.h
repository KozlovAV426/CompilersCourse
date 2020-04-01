#pragma once
#include "Expression.h"
#include <memory>

class LogicExpression : public Expression {
public:
  LogicExpression(const std::string& val);
  int Eval() const override;
  void Accept(Visitor* visitor) override;
  bool value;
};