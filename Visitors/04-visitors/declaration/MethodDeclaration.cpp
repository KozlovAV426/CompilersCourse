#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(
    const std::string &type, const std::string &id,
    std::vector<std::shared_ptr<VarDeclaration>> var_list,
    std::vector<std::shared_ptr<Statement>> stmnt_list)
    : type(type)
    , identifier(id)
    , variable_list(var_list)
    , statements_list(stmnt_list)
    {}


void MethodDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}