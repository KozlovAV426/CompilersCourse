#include "MainClass.h"

MainClass::MainClass(const std::string &id,
                     std::vector<std::shared_ptr<Statement>> stmnt_list)
                     : identifier(id)
                     , statement_list(stmnt_list)
                     {}

void MainClass::Accept(Visitor *visitor) {
  visitor->Visit(this);
}