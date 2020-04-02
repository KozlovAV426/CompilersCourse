#pragma once
#include "Expression.h"
#include <memory>

class NewArrayExpression : public Expression {
public:
  NewArrayExpression(std::string type,
                std::shared_ptr<Expression> expr);
  int Eval() const override;
  void Accept(Visitor* visitor) override;
  std::string type;
  std::shared_ptr<Expression> expr;
};