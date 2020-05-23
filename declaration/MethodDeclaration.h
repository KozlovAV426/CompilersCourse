#pragma once

#include "VarDeclaration.h"
#include "../statement/Statement.h"
#include <memory>
#include <string>
#include <vector>

class MethodDeclaration : public Declaration {
public:
  MethodDeclaration(std::pair<std::string, bool> type, const std::string &id,
                    std::vector<std::shared_ptr<VarDeclaration>> var_list,
                    std::vector<std::shared_ptr<Statement>> stmnt_list);
  void Accept(Visitor *visitor) override;

  std::string type;
  std::string identifier;
  bool is_array;
  std::vector<std::shared_ptr<VarDeclaration>> variable_list;
  std::vector<std::shared_ptr<Statement>> statements_list;
};