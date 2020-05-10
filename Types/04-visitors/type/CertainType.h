#pragma once

#include "Type.h"
#include <string>

class CertainType : public Type {
public:
  CertainType(const std::string& type, bool is_array);
  void Accept(Visitor* visitor) override;

  std::string type;
  bool is_array;
};