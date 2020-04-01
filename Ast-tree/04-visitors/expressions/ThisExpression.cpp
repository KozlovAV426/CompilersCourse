#include "ThisExpression.h"


int ThisExpression::Eval() const {

}

void ThisExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}