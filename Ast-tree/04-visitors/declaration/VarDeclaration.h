#pragma once
#include "Declaration.h"
#include <string>

class VarDeclaration : public Declaration {
public:
  VarDeclaration(const std::string& type, const std::string& id);
  void Accept(Visitor* visitor) override;

  std::string type;
  std::string identifier;
};