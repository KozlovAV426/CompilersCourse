#include "InCurlyBrStatement.h"

InCurlyBrStatement::InCurlyBrStatement(
    std::vector<std::shared_ptr<Statement>> statements)
    : statement_list(statements)
    {}

void InCurlyBrStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}