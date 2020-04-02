#pragma once

#include "Statement.h"
#include <memory>
#include "../expressions/Expression.h"

class LVDStatement : public Statement {
public:
  LVDStatement(const std::string& type, const std::string& id);
  void Accept(Visitor* visitor) override;

  std::string type;
  std::string identifier;
};