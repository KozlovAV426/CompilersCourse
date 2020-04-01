#pragma once
#include "Expression.h"
#include <memory>

class OrExpression: public Expression {
public:
  OrExpression(std::shared_ptr<Expression> lhv,
                std::shared_ptr<Expression> rhv);
  int Eval() const override;
  void Accept(Visitor* visitor) override;
  std::shared_ptr<Expression> lhv;
  std::shared_ptr<Expression> rhv;
};