#include "STIdentifier.h"

STIdentifier::STIdentifier(const std::string &id)
: identifier(id)
{}

void STIdentifier::Accept(Visitor *visitor) {
  visitor->Visit(this);
}