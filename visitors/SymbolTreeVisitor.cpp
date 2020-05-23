#include "SymbolTreeVisitor.h"
#include "elements.h"
#include <iostream>
#include "objects/Integer.h"
#include "elements.h"
#include <utility>


SymbolTreeVisitor::SymbolTreeVisitor() : tree_(new ScopeLayer) {
  current_layer_ = tree_.root_;

}

void SymbolTreeVisitor::Visit(Program *program) {
  current_layer_->defined_classes[program->main_class->identifier] = Class();
  cur_class.push(program->main_class->identifier);

  current_layer_->classes_.insert(program->main_class->identifier);
  auto new_layer = new ScopeLayer(current_layer_);
  current_layer_ = new_layer;
  program->main_class->Accept(this);
  current_layer_ = current_layer_->GetParent();

  cur_class.pop();

  for (auto cl_decl : program->classes_declarations) {
    current_layer_->defined_classes[cl_decl->identifier] = Class();
    cur_class.push(cl_decl->identifier);

    current_layer_->classes_.insert(cl_decl->identifier);
    auto new_layer = new ScopeLayer(current_layer_);
    current_layer_ = new_layer;
    cl_decl->Accept(this);
    current_layer_ = current_layer_->GetParent();

    cur_class.pop();
  }
}


void SymbolTreeVisitor::Visit(CertainType* type) {

}

void SymbolTreeVisitor::Visit(AssertStatement *statement) {

}

void SymbolTreeVisitor::Visit(IfElseStatement* statement) {
  statement->pos_statement->Accept(this);
  statement->neg_statement->Accept(this);
}

void SymbolTreeVisitor::Visit(IfStatement* statement) {
  statement->statement->Accept(this);
}

void SymbolTreeVisitor::Visit(InCurlyBrStatement* statement) {
  auto new_layer = new ScopeLayer(current_layer_);
  current_layer_ = new_layer;
  for (size_t i = 0; i < statement->statement_list.size(); ++i) {
    statement->statement_list[i]->Accept(this);
  }
  current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(LAssignStatement* statement) {

}

void SymbolTreeVisitor::Visit(LVDStatement* statement) {
  current_layer_ ->DeclareVariable(statement->identifier, {statement->type, statement->is_array});
}

void SymbolTreeVisitor::Visit(ReturnStatement* statement) {

}

void SymbolTreeVisitor::Visit(SOPrintlnStatement* statement) {

}

void SymbolTreeVisitor::Visit(WhileStatement* statement) {
  statement->statement->Accept(this);
}

void SymbolTreeVisitor::Visit(ClassDeclaration* declaration) {
  for (auto decl : declaration->declarations) {
    decl->Accept(this);
  }
}

void SymbolTreeVisitor::Visit(MethodDeclaration* declaration) {
  current_layer_->DeclareMethod(declaration->identifier,
                                MethodType(declaration->type,
                                           declaration->identifier,
                                           declaration->variable_list));

  current_layer_->DeclareMethodInClass(cur_class.top(), declaration->type,
                                       declaration->identifier, {});

  auto new_layer = new ScopeLayer(current_layer_);
  current_layer_ = new_layer;
  for (auto st : declaration->statements_list) {
    st->Accept(this);
  }
  current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(VarDeclaration* declaration) {
  current_layer_->DeclareVariable(declaration->identifier, {declaration->type, declaration->is_array});
}

void SymbolTreeVisitor::Visit(ArrayIdentifier* identifier) {

}

void SymbolTreeVisitor::Visit(STIdentifier* identifier) {

}

void SymbolTreeVisitor::Visit(MainClass* main_class) {
  auto new_layer = new ScopeLayer(current_layer_);
  current_layer_->DeclareMethodInClass(cur_class.top(), "void", "main", {});

  current_layer_->DeclareMethod("main", MethodType("void", "main", {}));
  current_layer_ = new_layer;

  for (auto st : main_class->statement_list) {
    st->Accept(this);
  }

  current_layer_ = current_layer_->GetParent();

}

void SymbolTreeVisitor::Visit(OrExpression* expression) {

}

void SymbolTreeVisitor::Visit(AndExpression* expression) {

}

void SymbolTreeVisitor::Visit(IsLessExpression* expression) {

}

void SymbolTreeVisitor::Visit(IsGreaterExpression* expression) {

}

void SymbolTreeVisitor::Visit(IsEqualExpression* expression) {

}

void SymbolTreeVisitor::Visit(AddExpression* expression) {

}

void SymbolTreeVisitor::Visit(SubstractExpression* expression) {

}

void SymbolTreeVisitor::Visit(MulExpression* expression) {

}

void SymbolTreeVisitor::Visit(DivExpression* expression) {

}

void SymbolTreeVisitor::Visit(ModuloExpression* expression) {
}

void SymbolTreeVisitor::Visit(AtExpression* expression) {
}

void SymbolTreeVisitor::Visit(LengthExpression* expression) {
}

void SymbolTreeVisitor::Visit(NewArrayExpression* expression) {

}

void SymbolTreeVisitor::Visit(NewExpression* expression) {

}

void SymbolTreeVisitor::Visit(NegExpression* expression) {

}

void SymbolTreeVisitor::Visit(InBrExpression* expression) {

}

void SymbolTreeVisitor::Visit(IdentifierExpression* expression) {

}

void SymbolTreeVisitor::Visit(NumberExpression* expression) {
}

void SymbolTreeVisitor::Visit(ThisExpression* expression) {

}

void SymbolTreeVisitor::Visit(LogicExpression* expression) {

}

void SymbolTreeVisitor::Visit(MInvExpression* expression) {

}
