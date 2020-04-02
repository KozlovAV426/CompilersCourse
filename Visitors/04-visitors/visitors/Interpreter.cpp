#include "Interpreter.h"
#include <iostream>

#include "elements.h"

void Interpreter::SetTosValue(int value) {
  tos_value_ = value;
}

void Interpreter::UnsetTosValue() {
  tos_value_ = 0;
}

Interpreter::Interpreter()
    : declared_ids_(std::set<std::string>()),
      variables_(std::map<std::string, int>()),
      array_variables_(std::map<std::string, std::vector<int>>()),
      is_tos_expression_(false), id_index_({}), is_new_(false),
      tos_value_(0) {}

void Interpreter::Visit(Program *program) {
  program->main_class->Accept(this);
}


void Interpreter::Visit(CertainType* type) {

}

void Interpreter::Visit(AssertStatement *statement) {
  statement->expr->Accept(this);
  std::cout << tos_value_ << std::endl;
  if (!tos_value_) {
    std::cout << "Assertion Failed" << std::endl;
    exit(1);
  }
  UnsetTosValue();
}

void Interpreter::Visit(IfElseStatement* statement) {
  statement->expr->Accept(this);
  if (tos_value_) {
    statement->pos_statement->Accept(this);
  }
  else {
    statement->neg_statement->Accept(this);
  }
}

void Interpreter::Visit(IfStatement* statement) {
  statement->expr->Accept(this);
  if (tos_value_) {
    statement->statement->Accept(this);
  }
}

void Interpreter::Visit(InCurlyBrStatement* statement) {
  for (size_t i = 0; i < statement->statement_list.size(); ++i) {
    statement->statement_list[i]->Accept(this);
  }
}

void Interpreter::Visit(LAssignStatement* statement) {
  statement->lvalue->Accept(this);
  auto lval = id_index_;
  statement->expr->Accept(this);
  if (lval.second != -1) {
    array_variables_[lval.first][lval.second] = tos_value_;
  }
  if (is_new_) {
    array_variables_[lval.first] = std::vector<int>(tos_value_);
    is_new_ = false;
  }
  else {
    variables_[lval.first] = tos_value_;
  }
}

void Interpreter::Visit(LVDStatement* statement) {
  declared_ids_.emplace(statement->identifier);
}

void Interpreter::Visit(ReturnStatement* statement) {
  statement->expr->Accept(this);
  std::cout << tos_value_ << std::endl;
  exit(0);
}

void Interpreter::Visit(SOPrintlnStatement* statement) {
  statement->expr->Accept(this);
  std::cout << tos_value_ << std::endl;
}

void Interpreter::Visit(WhileStatement* statement) {
  statement->expr->Accept(this);
  while (tos_value_) {
    statement->statement->Accept(this);
    statement->expr->Accept(this);
  }
}

void Interpreter::Visit(ClassDeclaration* declaration) {

}

void Interpreter::Visit(MethodDeclaration* declaration) {

}

void Interpreter::Visit(VarDeclaration* declaration) {
  declared_ids_.emplace(declaration->identifier);
}

void Interpreter::Visit(ArrayIdentifier* identifier) {
  identifier->expr->Accept(this);
  id_index_.first = identifier->identifier;
  id_index_.second = tos_value_;
  UnsetTosValue();
}

void Interpreter::Visit(STIdentifier* identifier) {
  id_index_.first = identifier->identifier;
  id_index_.second = -1;
  UnsetTosValue();
}

void Interpreter::Visit(MainClass* main_class) {
  for (auto st : main_class->statement_list) {
    st->Accept(this);
  }
}

void Interpreter::Visit(OrExpression* expression) {
  expression->lhv->Accept(this);
  int val = tos_value_;
  expression->rhv->Accept(this);
  SetTosValue(val || tos_value_);
}

void Interpreter::Visit(AndExpression* expression) {
  expression->lhv->Accept(this);
  int val = tos_value_;
  expression->rhv->Accept(this);
  SetTosValue(val && tos_value_);
}

void Interpreter::Visit(IsLessExpression* expression) {
  expression->lhv->Accept(this);
  int val = tos_value_;
  expression->rhv->Accept(this);
  SetTosValue(val < tos_value_);
}

void Interpreter::Visit(IsGreaterExpression* expression) {
  expression->lhv->Accept(this);
  int val = tos_value_;
  expression->rhv->Accept(this);
  SetTosValue(val > tos_value_);
}

void Interpreter::Visit(IsEqualExpression* expression) {
  expression->lhv->Accept(this);
  int val = tos_value_;
  expression->rhv->Accept(this);
  SetTosValue(val == tos_value_);
}

void Interpreter::Visit(AddExpression* expression) {
  expression->lhv->Accept(this);
  int val = tos_value_;
  expression->rhv->Accept(this);
  SetTosValue(val + tos_value_);
}

void Interpreter::Visit(SubstractExpression* expression) {
  expression->lhv->Accept(this);
  int val = tos_value_;
  expression->rhv->Accept(this);
  SetTosValue(val - tos_value_);
}

void Interpreter::Visit(MulExpression* expression) {
  expression->lhv->Accept(this);
  int val = tos_value_;
  expression->rhv->Accept(this);
  SetTosValue(val * tos_value_);
}

void Interpreter::Visit(DivExpression* expression) {
  expression->lhv->Accept(this);
  int val = tos_value_;
  expression->rhv->Accept(this);
  SetTosValue(val / tos_value_);
}

void Interpreter::Visit(ModuloExpression* expression) {
  expression->left->Accept(this);
  int val = tos_value_;
  expression->right->Accept(this);
  SetTosValue(val % tos_value_);
}

void Interpreter::Visit(AtExpression* expression) {
  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
  if (array_variables_.find(id_index_.first) == array_variables_.end()) {
    std::cout << "Undeclared variable" << std::endl;
    exit(1);
  }
  SetTosValue(array_variables_[id_index_.first][tos_value_]);
}

void Interpreter::Visit(LengthExpression* expression) {
  expression->expr->Accept(this);
  if (array_variables_.find(id_index_.first) == array_variables_.end()) {
    std::cout << "Undeclared variable" << std::endl;
    exit(1);
  }
  SetTosValue(array_variables_[id_index_.first].size());
}

void Interpreter::Visit(NewArrayExpression* expression) {
  // Assuming that there are only integers
  expression->expr->Accept(this);
  is_new_ = true;
}

void Interpreter::Visit(NewExpression* expression) {
  // Assuming that there are only integers
  is_new_ = true;
  SetTosValue(0);
}

void Interpreter::Visit(NegExpression* expression) {
  expression->expr->Accept(this);
  std::cout << tos_value_ << std::endl;
  SetTosValue(!tos_value_);
}

void Interpreter::Visit(InBrExpression* expression) {
  expression->expr->Accept(this);
  SetTosValue(tos_value_);
}

void Interpreter::Visit(IdentifierExpression* expression) {
  id_index_.first = expression->identifier;
  SetTosValue(variables_[expression->identifier]);
}

void Interpreter::Visit(NumberExpression* expression) {
  SetTosValue(expression->value);
}

void Interpreter::Visit(ThisExpression* expression) {

}

void Interpreter::Visit(LogicExpression* expression) {
  SetTosValue(expression->value);
  std::cout << "logic" << std::endl;
}

void Interpreter::Visit(MInvExpression* expression) {

}