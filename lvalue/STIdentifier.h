#pragma once

#include "Lvalue.h"
#include <string>

class STIdentifier : public Lvalue {
public:
  STIdentifier(const std::string& id);
  void Accept(Visitor* visitor) override;

  std::string identifier;
};