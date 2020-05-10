#pragma once
#include "Expression.h"
#include "../statement/Statement.h"
#include <memory>
#include <vector>

class MInvExpression : public Expression, public Statement {
public:
  MInvExpression(std::shared_ptr<Expression> expr, const std::string& identifier,
      const std::vector<std::shared_ptr<Expression>>& expr_list);
  int Eval() const override;
  void Accept(Visitor* visitor) override;
  std::shared_ptr<Expression> expr;
  std::string identifier;
  std::vector<std::shared_ptr<Expression>> expr_list;
};