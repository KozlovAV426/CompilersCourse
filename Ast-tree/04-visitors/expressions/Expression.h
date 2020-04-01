#pragma once
#include "base_elements/BaseElement.h"

class Expression : public BaseElement {
public:
    virtual int Eval() const = 0;
};