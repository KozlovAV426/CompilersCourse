#pragma once


#include "Statement.h"
#include <memory>
#include "../expressions/Expression.h"

class ReturnStatement : public Statement {
public:
  ReturnStatement(std::shared_ptr<Expression> expr);
  void Accept(Visitor* visitor) override;

  std::shared_ptr<Expression> expr;
};