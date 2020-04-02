#pragma once

#include "Statement.h"
#include <memory>
#include "../expressions/Expression.h"

class IfElseStatement : public Statement {
public:
  IfElseStatement(std::shared_ptr<Expression> expr,
              std::shared_ptr<Statement> pos_statement,
              std::shared_ptr<Statement> neg_statement);
  void Accept(Visitor* visitor) override;

  std::shared_ptr<Expression> expr;
  std::shared_ptr<Statement> pos_statement;
  std::shared_ptr<Statement> neg_statement;
};