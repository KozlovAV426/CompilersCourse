#include "Program.h"

Program::Program(std::shared_ptr<MainClass> main,
                 std::vector<std::shared_ptr<ClassDeclaration>> classes_decl)
                 : main_class(main)
                 , classes_declarations(classes_decl)
                 {}

void Program::Accept(Visitor *visitor) {
  visitor->Visit(this);
}