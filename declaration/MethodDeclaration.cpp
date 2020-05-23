#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(
    const std::pair<std::string, bool>type, const std::string &id,
    std::vector<std::shared_ptr<VarDeclaration>> var_list,
    std::vector<std::shared_ptr<Statement>> stmnt_list)
    : type(type.first)
    , identifier(id)
    , is_array(type.second)
    , variable_list(var_list)
    , statements_list(stmnt_list)
    {}


void MethodDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}