#pragma once

#include "VarDeclaration.h"
#include "../statement/Statement.h"
#include <memory>
#include <string>
#include <vector>

class ClassDeclaration : public Declaration {
public:
  ClassDeclaration(const std::string &id, const std::string &extra_id,
                    std::vector<std::shared_ptr<Declaration>> declarations);
  void Accept(Visitor *visitor) override;

  std::string identifier;
  std::string extend_id;
  std::vector<std::shared_ptr<Declaration>> declarations;
};