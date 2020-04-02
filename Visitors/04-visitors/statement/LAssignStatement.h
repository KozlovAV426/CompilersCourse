#pragma once

#include "Statement.h"
#include <memory>
#include "../expressions/Expression.h"
#include "../lvalue/Lvalue.h"

class LAssignStatement : public Statement {
public:
  LAssignStatement(std::shared_ptr<Lvalue> lval,
      std::shared_ptr<Expression> expr);
  void Accept(Visitor* visitor) override;

  std::shared_ptr<Lvalue> lvalue;
  std::shared_ptr<Expression> expr;
};