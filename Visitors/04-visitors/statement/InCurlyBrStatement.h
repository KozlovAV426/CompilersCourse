#pragma once

#include "Statement.h"
#include <memory>
#include <vector>
#include "../expressions/Expression.h"

class InCurlyBrStatement : public Statement {
public:
  InCurlyBrStatement(std::vector<std::shared_ptr<Statement>> statements);
  void Accept(Visitor* visitor) override;

  std::vector<std::shared_ptr<Statement>> statement_list;
};