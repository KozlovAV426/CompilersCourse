#pragma once


#include "Statement.h"
#include <memory>
#include "../expressions/Expression.h"

class SOPrintlnStatement : public Statement {
public:
  SOPrintlnStatement(std::shared_ptr<Expression> expr);
  void Accept(Visitor* visitor) override;

  std::shared_ptr<Expression> expr;
};