#include "TypesChecker.h"
#include "elements.h"
#include <iostream>
#include "objects/Integer.h"
#include "elements.h"



TypesChecker::TypesChecker(ScopeLayer* tree) : tree_(tree) {
  current_layer_ = tree_.root_;
}

void TypesChecker::Visit(Program *program) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());
  program->main_class->Accept(this);
  current_layer_ = current_layer_->GetParent();
  offsets.pop();
  for (size_t i = 0; i < program->classes_declarations.size(); ++i) {
    offsets.push(i + 1);
    current_layer_ = current_layer_->GetChild(offsets.top());
    program->classes_declarations[i]->Accept(this);
    current_layer_ = current_layer_->GetParent();
    offsets.pop();
  }
}


void TypesChecker::Visit(CertainType* type) {

}

void TypesChecker::Visit(AssertStatement *statement) {
  statement->expr->Accept(this);
  if (tos_type.first != "boolean" || tos_type.second != false) {
    throw std::runtime_error("Not boolean in expr in assert");
  }
}

void TypesChecker::Visit(IfElseStatement* statement) {

  statement->pos_statement->Accept(this);

  statement->neg_statement->Accept(this);

}

void TypesChecker::Visit(IfStatement* statement) {
  statement->statement->Accept(this);
}

void TypesChecker::Visit(InCurlyBrStatement* statement) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());
  for (size_t i = 0; i < statement->statement_list.size(); ++i) {
    statement->statement_list[i]->Accept(this);
  }
  size_t index = offsets.top() + 1;
  offsets.pop();
  offsets.push(index);
  current_layer_ = current_layer_->GetParent();
}

void TypesChecker::Visit(LAssignStatement* statement) {
  statement->lvalue->Accept(this);
  auto left = tos_type;
  statement->expr->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types in assigning");
  }
}

void TypesChecker::Visit(LVDStatement* statement) {
}

void TypesChecker::Visit(ReturnStatement* statement) {

}

void TypesChecker::Visit(SOPrintlnStatement* statement) {
  tos_type = {"void", false};
}

void TypesChecker::Visit(WhileStatement* statement) {
  statement->statement->Accept(this);
}

void TypesChecker::Visit(ClassDeclaration* declaration) {
  for (auto decl : declaration->declarations) {
    decl->Accept(this);
  }
}

void TypesChecker::Visit(MethodDeclaration* declaration) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());
  for (auto st : declaration->statements_list) {
    st->Accept(this);
  }
  size_t index = offsets.top() + 1;
  offsets.pop();
  offsets.push(index);
  current_layer_ = current_layer_->GetParent();
}

void TypesChecker::Visit(VarDeclaration* declaration) {
}

void TypesChecker::Visit(ArrayIdentifier* identifier) {
  tos_type = current_layer_->GetType(identifier->identifier);
}

void TypesChecker::Visit(STIdentifier* identifier) {
  tos_type = current_layer_->GetType(identifier->identifier);
}

void TypesChecker::Visit(MainClass* main_class) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());

  for (auto decl : main_class->statement_list) {
    decl->Accept(this);
  }
  offsets.pop();
  current_layer_ = current_layer_->GetParent();
}

void TypesChecker::Visit(OrExpression* expression) {
  expression->lhv->Accept(this);
  auto left = tos_type;
  expression->rhv->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void TypesChecker::Visit(AndExpression* expression) {
  expression->lhv->Accept(this);
  auto left = tos_type;
  expression->rhv->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void TypesChecker::Visit(IsLessExpression* expression) {
  expression->lhv->Accept(this);
  auto left = tos_type;
  expression->rhv->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Check Types Failed!");
  }
}

void TypesChecker::Visit(IsGreaterExpression* expression) {
  expression->lhv->Accept(this);
  auto left = tos_type;
  expression->rhv->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void TypesChecker::Visit(IsEqualExpression* expression) {
  expression->lhv->Accept(this);
  auto left = tos_type;
  expression->rhv->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
  tos_type = {"boolean", false};
}

void TypesChecker::Visit(AddExpression* expression) {
  expression->lhv->Accept(this);
  auto left = tos_type;
  expression->rhv->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void TypesChecker::Visit(SubstractExpression* expression) {
  expression->lhv->Accept(this);
  auto left = tos_type;
  expression->rhv->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void TypesChecker::Visit(MulExpression* expression) {
  expression->lhv->Accept(this);
  auto left = tos_type;
  expression->rhv->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void TypesChecker::Visit(DivExpression* expression) {
  expression->lhv->Accept(this);
  auto left = tos_type;
  expression->rhv->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void TypesChecker::Visit(ModuloExpression* expression) {
  expression->left->Accept(this);
  auto left = tos_type;
  expression->right->Accept(this);
  if (left != tos_type) {
    throw std::runtime_error("Different types of operands!");
  }
}

void TypesChecker::Visit(AtExpression* expression) {
  expression->lhv->Accept(this);
  auto res_type = tos_type;
  expression->rhv->Accept(this);
  if (tos_type.first != "int" || tos_type.second != false) {
    throw std::runtime_error("Bad index in *.[] expression");
  }
  tos_type = {res_type.first, false};
}

void TypesChecker::Visit(LengthExpression* expression) {
  tos_type = {"int", false};
}

void TypesChecker::Visit(NewArrayExpression* expression) {
  expression->expr->Accept(this);
  if (tos_type.first != "int" || tos_type.second != false) {
    throw std::runtime_error("Bad size in new type [] expression");
  }
  tos_type = {expression->type, true};
}

void TypesChecker::Visit(NewExpression* expression) {
  tos_type = {expression->type, false};
}

void TypesChecker::Visit(NegExpression* expression) {
  tos_type = {"boolean", false};
}

void TypesChecker::Visit(InBrExpression* expression) {
  expression->expr->Accept(this);
}

void TypesChecker::Visit(IdentifierExpression* expression) {
  auto id = current_layer_->Get(expression->identifier);
  tos_type = id->GetType();
}

void TypesChecker::Visit(NumberExpression* expression) {
  tos_type = {"int", false};
}

void TypesChecker::Visit(ThisExpression* expression) {

}

void TypesChecker::Visit(LogicExpression* expression) {
  tos_type = {"boolean", false};
}

void TypesChecker::Visit(MInvExpression* expression) {
  expression->expr->Accept(this);
  auto left = tos_type;

  ScopeLayer* cur = current_layer_;
  while (cur->defined_classes.find(left.first) == cur->defined_classes.end() && cur->parent_ != nullptr) {
    cur = cur->parent_;
  }
  if (cur->defined_classes.find(left.first) != cur->defined_classes.end()) {
    auto it = cur->defined_classes.find(left.first);
    for (auto m : it->second.methods) {
      if (m.name == expression->identifier) {
        tos_type = {m.type, false};
      }
    }
  } else {
    throw std::runtime_error("No class");
  }
}
