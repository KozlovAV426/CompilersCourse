#pragma once
#include "Expression.h"
#include <memory>

class IdentifierExpression : public Expression {
public:
  IdentifierExpression(const std::string& identifier);
  int Eval() const override;
  void Accept(Visitor* visitor) override;
  std::string identifier;
};