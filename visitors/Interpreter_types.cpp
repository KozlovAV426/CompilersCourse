#include "Interpreter_types.h"
#include "TypesChecker.h"
#include "elements.h"
#include "objects/Boolean.h"
#include "objects/Class.h"
#include "objects/Integer.h"
#include <iostream>

Interpreter_types::Interpreter_types(ScopeLayer *tree) : tree_(tree) {
  current_layer_ = tree_.root_;
}

void Interpreter_types::Visit(Program *program) {

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

void Interpreter_types::Visit(CertainType *type) {}

void Interpreter_types::Visit(AssertStatement *statement) {
  statement->expr->Accept(this);
  std::cout << tos_value->ToBoolean() << std::endl;
  if (!tos_value->ToBoolean()) {
    throw std::runtime_error("Assertion failed!");
  }
}

void Interpreter_types::Visit(IfElseStatement *statement) {
  statement->expr->Accept(this);
  if (tos_value->ToBoolean()) {
    statement->pos_statement->Accept(this);
  } else {
    statement->neg_statement->Accept(this);
  }
}

void Interpreter_types::Visit(IfStatement *statement) {
  statement->expr->Accept(this);
  if (tos_value->ToBoolean()) {
    statement->statement->Accept(this);
  }
}

void Interpreter_types::Visit(InCurlyBrStatement *statement) {
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

void Interpreter_types::Visit(LAssignStatement *statement) {
  statement->lvalue->Accept(this);
  auto name = id;
  statement->expr->Accept(this);
  current_layer_->Put(name, tos_value);
}

void Interpreter_types::Visit(LVDStatement *statement) {}

void Interpreter_types::Visit(ReturnStatement *statement) {}

void Interpreter_types::Visit(SOPrintlnStatement *statement) {
  statement->expr->Accept(this);
  std::cout << tos_value->ToInt() << std::endl;
}

void Interpreter_types::Visit(WhileStatement *statement) {
  statement->statement->Accept(this);
}

void Interpreter_types::Visit(ClassDeclaration *declaration) {
  for (auto decl : declaration->declarations) {
    decl->Accept(this);
  }
}

void Interpreter_types::Visit(MethodDeclaration *declaration) {
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

void Interpreter_types::Visit(VarDeclaration *declaration) {}

void Interpreter_types::Visit(ArrayIdentifier *identifier) {
  id = identifier->identifier;
  identifier->expr->Accept(this);
  sz = tos_value->ToInt();
}

void Interpreter_types::Visit(STIdentifier *identifier) {
  id = identifier->identifier;
  sz = 0;
}

void Interpreter_types::Visit(MainClass *main_class) {
  offsets.push(0);
  current_layer_ = current_layer_->GetChild(offsets.top());

  for (auto decl : main_class->statement_list) {
    decl->Accept(this);
  }
  offsets.pop();
  current_layer_ = current_layer_->GetParent();
}

void Interpreter_types::Visit(OrExpression *expression) {}

void Interpreter_types::Visit(AndExpression *expression) {}

void Interpreter_types::Visit(IsLessExpression *expression) {}

void Interpreter_types::Visit(IsGreaterExpression *expression) {}

void Interpreter_types::Visit(IsEqualExpression *expression) {
  expression->lhv->Accept(this);
  auto left = tos_value;
  expression->rhv->Accept(this);
  if (tos_value->GetType().first == "int") {
    tos_value =
        std::make_shared<Boolean>(left->ToInt() == tos_value->ToInt(), false);
  } else {
    tos_value = std::make_shared<Boolean>(left == tos_value, false);
  }
}

void Interpreter_types::Visit(AddExpression *expression) {
  expression->lhv->Accept(this);
  auto left = tos_value;
  expression->rhv->Accept(this);
  tos_value =
      std::make_shared<Integer>(left->ToInt() + tos_value->ToInt(), false);
}

void Interpreter_types::Visit(SubstractExpression *expression) {
  expression->lhv->Accept(this);
  auto left = tos_value;
  expression->rhv->Accept(this);
  tos_value =
      std::make_shared<Integer>(left->ToInt() - tos_value->ToInt(), false);
}

void Interpreter_types::Visit(MulExpression *expression) {
  expression->lhv->Accept(this);
  auto left = tos_value;
  expression->rhv->Accept(this);
  tos_value =
      std::make_shared<Integer>(left->ToInt() * tos_value->ToInt(), false);
}

void Interpreter_types::Visit(DivExpression *expression) {
  expression->lhv->Accept(this);
  auto left = tos_value;
  expression->rhv->Accept(this);
  tos_value =
      std::make_shared<Integer>(left->ToInt() / tos_value->ToInt(), false);
}

void Interpreter_types::Visit(ModuloExpression *expression) {
  expression->left->Accept(this);
  auto left = tos_value;
  expression->right->Accept(this);
  tos_value =
      std::make_shared<Integer>(left->ToInt() % tos_value->ToInt(), false);
}

void Interpreter_types::Visit(AtExpression *expression) {}

void Interpreter_types::Visit(LengthExpression *expression) {}

void Interpreter_types::Visit(NewArrayExpression *expression) {}

void Interpreter_types::Visit(NewExpression *expression) {
  if (expression->type == "boolean") {
    tos_value = std::make_shared<Boolean>(false, false);
  } else if (expression->type == "int") {
    tos_value = std::make_shared<Integer>(0, false);
  } else {
    tos_value = std::make_shared<ClassType>(expression->type, false);
  }
}

void Interpreter_types::Visit(NegExpression *expression) {}

void Interpreter_types::Visit(InBrExpression *expression) {
  expression->expr->Accept(this);
}

void Interpreter_types::Visit(IdentifierExpression *expression) {
  id = expression->identifier;
  tos_value = current_layer_->Get(expression->identifier);
}

void Interpreter_types::Visit(NumberExpression *expression) {
  tos_value = std::make_shared<Integer>(expression->value, false);
}

void Interpreter_types::Visit(ThisExpression *expression) {}

void Interpreter_types::Visit(LogicExpression *expression) {
  tos_value = std::make_shared<Boolean>(expression->value, false);
}

void Interpreter_types::Visit(MInvExpression *expression) {}
