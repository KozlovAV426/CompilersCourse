#pragma once

#include "Expression.h"
#include <memory>

class ModuloExpression : public Expression {
public:
  ModuloExpression(std::shared_ptr<Expression> left,
      std::shared_ptr<Expression> right);
  int Eval() const override;
  void Accept(Visitor* visitor) override;

  std::shared_ptr<Expression> left;
  std::shared_ptr<Expression> right;
};