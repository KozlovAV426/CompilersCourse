#include "AssertStatement.h"

AssertStatement::AssertStatement(std::shared_ptr<Expression> expr)
      : expr(expr)
      {}

void AssertStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}