#include "MethodType.h"

Method MethodType::ToMethod() { return {};
}

MethodType::MethodType(const std::string &t, const std::string &id,
                       const std::vector<std::shared_ptr<VarDeclaration>> &input)
                       : type(t), name(id), var_list(input), is_array(false) {}

std::pair<std::string, bool> MethodType::GetType() { return {type, false};
}