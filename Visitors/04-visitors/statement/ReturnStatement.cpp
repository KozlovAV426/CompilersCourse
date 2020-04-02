#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(std::shared_ptr<Expression> expr)
                : expr(expr)
                {}

void ReturnStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}