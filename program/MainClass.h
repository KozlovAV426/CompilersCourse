#pragma once

#include "../statement/Statement.h"
#include "../base_elements/BaseElement.h"

#include <string>
#include <memory>
#include <vector>

class MainClass : public BaseElement {
public:
  MainClass(const std::string &id,
            std::vector<std::shared_ptr<Statement>> stmnt_list);
  void Accept(Visitor* visitor) override;

  std::string identifier;
  std::vector<std::shared_ptr<Statement>> statement_list;
};