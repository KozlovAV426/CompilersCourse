#include "ClassDeclaration.h"

ClassDeclaration::ClassDeclaration(
    const std::string &id, const std::string &extra_id,
    std::vector<std::shared_ptr<Declaration>> declarations)
    : identifier(id)
    , extend_id(extra_id)
    , declarations(declarations)
    {}

void ClassDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}