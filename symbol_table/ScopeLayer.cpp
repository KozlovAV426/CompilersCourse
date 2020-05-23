#include "ScopeLayer.h"

#include "objects/UninitObject.h"

#include <iostream>

ScopeLayer::ScopeLayer(ScopeLayer *parent) : parent_(parent) {

  parent_->AddChild(this);
  classes_.insert("int");
  classes_.insert("boolean");
  classes_.insert("void");
}

void ScopeLayer::DeclareFieldInClass(std::string cl, std::string t,
                                     std::string id) {
  ScopeLayer *current_layer = this;

  while (current_layer->defined_classes.find(cl) ==
             current_layer->defined_classes.end() &&
         current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->defined_classes.find(cl) !=
      current_layer->defined_classes.end()) {
    current_layer->defined_classes[cl].fields.emplace_back(t, id);
  } else {
    throw std::runtime_error("Class not declared");
  }
}

void ScopeLayer::DeclareMethodInClass(
    std::string cl, std::string t, std::string id,
    std::vector<std::pair<std::string, std::string>> args) {
  ScopeLayer *current_layer = this;

  while (current_layer->defined_classes.find(cl) ==
             current_layer->defined_classes.end() &&
         current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->defined_classes.find(cl) !=
      current_layer->defined_classes.end()) {
    current_layer->defined_classes[cl].methods.emplace_back(t, id, args);
  } else {
    throw std::runtime_error("Class not declared");
  }
}

void ScopeLayer::AttachParent() {}

void ScopeLayer::DeclareClass(std::string name) { classes_.insert(name); }

void ScopeLayer::DeclareMethod(const std::string &id, MethodType meth) {
  methods_[id] = MethodType(meth.type, meth.name, meth.var_list);
}

ScopeLayer::ScopeLayer() : parent_(nullptr) {}

std::pair<std::string, bool> ScopeLayer::GetType(std::string symbol) {
  ScopeLayer *current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->Has(symbol)) {
    return current_layer->Get(symbol)->GetType();
  } else {
    throw std::runtime_error("Variable not declared");
  }
}

void ScopeLayer::DeclareVariable(Symbol symbol,
                                 std::pair<std::string, bool> type) {
  if (values_.find(symbol) != values_.end()) {
    throw std::runtime_error("Variable has declared");
  }
  auto current_layer = this;
  while (current_layer->classes_.find(type.first) ==
             current_layer->classes_.end() &&
         current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->classes_.find(type.first) !=
      current_layer->classes_.end()) {
    values_[symbol] = std::make_shared<UninitObject>(type.first, type.second);
    offsets_[symbol] = symbols_.size();
    symbols_.push_back(symbol);
  } else {
    throw std::runtime_error("Initialization variable of undeclared class");
  }
}

void ScopeLayer::Put(Symbol symbol, std::shared_ptr<Object> value) {

  ScopeLayer *current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->Has(symbol)) {
    current_layer->values_.find(symbol)->second = value;
  } else {
    throw std::runtime_error("Variable not declared");
  }
}

bool ScopeLayer::Has(Symbol symbol) {
  return values_.find(symbol) != values_.end();
}

std::shared_ptr<Object> ScopeLayer::Get(Symbol symbol) {
  ScopeLayer *current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->Has(symbol)) {
    return current_layer->values_.find(symbol)->second;
  } else {
    throw std::runtime_error("Variable not declared");
  }
}

ScopeLayer *ScopeLayer::GetChild(size_t index) {
//  std::cout << "Children of scope: " << children_.size() << std::endl;
  return children_[index];
}

void ScopeLayer::AddChild(ScopeLayer *child) { children_.push_back(child); }

ScopeLayer *ScopeLayer::GetParent() const { return parent_; }