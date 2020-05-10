#include "IfElseStatement.h"

IfElseStatement::IfElseStatement(std::shared_ptr<Expression> expr,
                                 std::shared_ptr<Statement> pos_statement,
                                 std::shared_ptr<Statement> neg_statement)
               : expr(expr)
               , pos_statement(pos_statement)
               , neg_statement(neg_statement)
               {}

void IfElseStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}