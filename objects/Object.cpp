#include "Object.h"
#include <iostream>

int Object::ToInt() {
    std::cout << "Called from wrong type!" << std::endl;
}

bool Object::ToBoolean() {
  std::cout << "Called from wrong type!" << std::endl;
}

Class Object::ToClass() {
  std::cout << "Called from wrong type!" << std::endl;
}

Method Object::ToMethod() {
  std::cout << "Called from wrong type!" << std::endl;
}

std::pair<std::string, bool> Object::GetType() {}

