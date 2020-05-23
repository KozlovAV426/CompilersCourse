#pragma once

#include "Lvalue.h"
#include "../expressions/Expression.h"
#include <string>
#include <memory>

class ArrayIdentifier : public Lvalue {
public:
  ArrayIdentifier(const std::string& id, std::shared_ptr<Expression> expr);
  void Accept(Visitor* visitor);

  std::string identifier;
  std::shared_ptr<Expression> expr;
};