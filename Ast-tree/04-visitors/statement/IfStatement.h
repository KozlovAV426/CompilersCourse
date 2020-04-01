#pragma once

#include "Statement.h"
#include <memory>
#include "../expressions/Expression.h"

class IfStatement : public Statement {
public:
  IfStatement(std::shared_ptr<Expression> expr,
              std::shared_ptr<Statement> statement);
  void Accept(Visitor* visitor) override;

  std::shared_ptr<Expression> expr;
  std::shared_ptr<Statement> statement;
};