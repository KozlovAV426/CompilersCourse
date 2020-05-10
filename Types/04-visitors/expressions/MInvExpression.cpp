#include "MInvExpression.h"

MInvExpression::MInvExpression(
    std::shared_ptr<Expression> expr, const std::string& identifier,
    const std::vector<std::shared_ptr<Expression>> &expr_list)
    : expr(std::move(expr))
    , identifier(identifier)
    , expr_list(expr_list)
    {}

int MInvExpression::Eval() const {

}

void MInvExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}