#include "LAssignStatement.h"

LAssignStatement::LAssignStatement(std::shared_ptr<Lvalue> lval,
                                   std::shared_ptr<Expression> expr)
                                   : lvalue(lval)
                                   , expr(expr)
                                   {}


void LAssignStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}