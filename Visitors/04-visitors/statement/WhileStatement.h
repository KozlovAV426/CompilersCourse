#pragma once

#include "Statement.h"
#include <memory>
#include "../expressions/Expression.h"

class WhileStatement : public Statement {
public:
  WhileStatement(std::shared_ptr<Expression> expr,
              std::shared_ptr<Statement> statement);
  void Accept(Visitor* visitor) override;

  std::shared_ptr<Expression> expr;
  std::shared_ptr<Statement> statement;
};