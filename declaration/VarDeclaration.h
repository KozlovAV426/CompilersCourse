#pragma once
#include "Declaration.h"
#include <string>

class VarDeclaration : public Declaration {
public:
  VarDeclaration(const std::pair<std::string, bool> type, const std::string& id);
  void Accept(Visitor* visitor) override;

  std::string type;
  std::string identifier;
  bool is_array;
};