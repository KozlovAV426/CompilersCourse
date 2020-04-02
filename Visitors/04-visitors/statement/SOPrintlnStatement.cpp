#include "SOPrintlnStatement.h"

SOPrintlnStatement::SOPrintlnStatement(std::shared_ptr<Expression> expr)
                    : expr(expr)
                    {}


void SOPrintlnStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}