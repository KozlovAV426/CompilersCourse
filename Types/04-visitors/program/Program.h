#pragma once

#include "../base_elements/BaseElement.h"
#include "MainClass.h"
#include "../declaration/ClassDeclaration.h"

#include <vector>
#include <memory>

class Program : public BaseElement {
public:
  Program(std::shared_ptr<MainClass> main,
          std::vector<std::shared_ptr<ClassDeclaration>> classes_decl);
  void Accept(Visitor* visitor);

  std::shared_ptr<MainClass> main_class;
  std::vector<std::shared_ptr<ClassDeclaration>> classes_declarations;
};