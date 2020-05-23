#include "LogicExpression.h"

LogicExpression::LogicExpression(const std::string &val) {
  if (val == "true") {
    value = true;
  }
  else value = false;
}

int LogicExpression::Eval() const {
}

void LogicExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}