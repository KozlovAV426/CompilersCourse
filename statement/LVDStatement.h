#pragma once

#include "Statement.h"
#include <memory>
#include "../expressions/Expression.h"

class LVDStatement : public Statement {
public:
  LVDStatement(std::string type, bool array, const std::string& id);
  void Accept(Visitor* visitor) override;

  std::string type;
  std::string identifier;
  bool is_array;
};