#include "Printer.h"

#include "elements.h"

#include <iostream>

Printer::Printer(const std::string& filename) {

  file.open(filename);

  file << "digraph Tree {\nnode [shape = \"rectangle\", style = \"filled\"]" << std::endl;
}

Printer::~Printer() {
  file << "}" << std::endl;
  file.close();
}


void Printer::Visit(Program* program) {
  file << "n" << program << "[label = \"Program\"]" << std::endl;

  program->main_class->Accept(this);

  file << "n" << program << "-> n" << program->main_class.get() << std::endl;
  for (auto decl : program->classes_declarations) {
    file << "n" << program << "-> n" << decl.get() << std::endl;
    decl->Accept(this);
  }
}

void Printer::Visit(CertainType* type) {

}

void Printer::Visit(AssertStatement *statement) {
  file << "n" << statement << " [label = \"assert(...) \"]" << std::endl;
  file << "n" << statement << "-> n" << statement->expr.get() << std::endl;
  statement->expr->Accept(this);
}

void Printer::Visit(IfElseStatement* statement) {
  file << "n" << statement << " [label = \"if (...) {...} else {...} \"]" << std::endl;
  file << "n" << statement << "-> n" << statement->expr.get() << std::endl;
  file << "n" << statement << "-> n" << statement->pos_statement.get() << std::endl;
  file << "n" << statement << "-> n" << statement->neg_statement.get() << std::endl;
  statement->expr->Accept(this);
  statement->pos_statement->Accept(this);
  statement->neg_statement->Accept(this);
}

void Printer::Visit(IfStatement* statement) {
  file << "n" << statement << " [label = \"if (...)\"]" << std::endl;
  file << "n" << statement << "-> n" << statement->expr.get() << std::endl;
  file << "n" << statement << "-> n" << statement->statement.get() << std::endl;
  statement->expr->Accept(this);
  statement->statement->Accept(this);
}

void Printer::Visit(InCurlyBrStatement* statement) {
  file << "n" << statement << " [label = \"{ ... }\"]" << std::endl;

  for (auto st : statement->statement_list) {
    file << "n" << statement << "-> n" << st.get() << std::endl;
    st->Accept(this);
  }

}

void Printer::Visit(LAssignStatement* statement) {
  file << "n" << statement << " [label = \" = \"]" << std::endl;
  file << "n" << statement << "-> n" << statement->lvalue.get() << std::endl;
  file << "n" << statement << "-> n" << statement->expr.get() << std::endl;

  statement->lvalue->Accept(this);
  statement->expr->Accept(this);

}


void Printer::Visit(LVDStatement* statement) {
  file << "n" << statement << " [label = \"local variable declaration\"]" << std::endl;
  file << "n" << &statement->type << " [label = \"" << statement->type << "\"]" << std::endl;
  file << "n" << &statement->identifier << " [label = \"" << statement->identifier << "\"]" << std::endl;

  file << "n" << statement << "-> n" << &statement->type << std::endl;
  file << "n" << statement << "-> n" << &statement->identifier << std::endl;
}

void Printer::Visit(ReturnStatement* statement) {
  file << "n" << statement << " [label = \"return\"]" << std::endl;
  file << "n" << statement << "-> n" << statement->expr.get() << std::endl;
  statement->expr->Accept(this);
}

void Printer::Visit(SOPrintlnStatement* statement) {
  file << "n" << statement << " [label = \"System.out.println\"]" << std::endl;
  file << "n" << statement << "-> n" << statement->expr.get() << std::endl;
  statement->expr->Accept(this);
}

void Printer::Visit(WhileStatement* statement) {
  file << "n" << statement << " [label = \"while\"]" << std::endl;
  file << "n" << statement << "-> n" << statement->expr.get() << std::endl;
  file << "n" << statement << "-> n" << statement->statement.get() << std::endl;
  statement->expr->Accept(this);
  statement->statement->Accept(this);
}

void Printer::Visit(ClassDeclaration* declaration) {
  file << "n" << declaration << " [label =  \"class " << declaration->identifier;
  if (!declaration->extend_id.empty()) {
    file << " extends " << declaration->extend_id;
  }
  file << "\"]" << std::endl;

  for (auto decl : declaration->declarations) {
    file << "n" << declaration << "-> n" << decl.get() << std::endl;
    decl->Accept(this);
  }
}

void Printer::Visit(MethodDeclaration* declaration) {
  file << "n" << declaration << " [label =  \"public " << declaration->type
    << " " << declaration->identifier << "(...) {...}\"]" << std::endl;
  for (auto form : declaration->variable_list) {
    file << "n" << declaration << "-> n" << form.get() << std::endl;
    form->Accept(this);
  }
  for (auto st : declaration->statements_list) {
    file << "n" << declaration << "-> n" << st.get() << std::endl;
    st->Accept(this);
  }
}

void Printer::Visit(VarDeclaration* declaration) {
  file << "n" << declaration << " [label =  \"" << declaration->type
      << " " << declaration->identifier << "\"]" << std::endl;
}

void Printer::Visit(ArrayIdentifier* identifier) {
  file << "n" << identifier << " [label =  \"" << identifier->identifier
      <<  "[...]\"]" << std::endl;

  file << "n" << identifier << "-> n" << identifier->expr.get() << std::endl;
  identifier->expr->Accept(this);
}

void Printer::Visit(STIdentifier* identifier) {
  file << "n" << identifier << " [label =  \"" << identifier->identifier << "\"]"
    << std::endl;
}

void Printer::Visit(MainClass* main_class) {
  file << "n" << main_class << "[label = \"Main Class\n" << "Identifier: "
  << main_class->identifier << "\"]" << std::endl;

  for (auto statement : main_class->statement_list) {
    file << "n" << main_class << "->" << "n" << statement.get() << std::endl;
    statement->Accept(this);
  }
}

void Printer::Visit(NumberExpression* expression) {
  file << "n" << expression << " [label =  \"" << expression->value << "\" ]" << std::endl;
}


void Printer::Visit(AndExpression* expression) {
  file << "n" << expression << " [label =  \" &&  \" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void Printer::Visit(OrExpression* expression) {
  file << "n" << expression << " [label =  \" || \" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void Printer::Visit(IsLessExpression* expression) {
  file << "n" << expression << " [label =  \" < \" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void Printer::Visit(IsGreaterExpression* expression) {
  file << "n" << expression << " [label =  \" > \" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void Printer::Visit(IsEqualExpression* expression) {
  file << "n" << expression << " [label =  \" ==  \"]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void Printer::Visit(ModuloExpression* expression) {
  file << "n" << expression << " [label = \"  % \" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->left.get() << std::endl;
  file << "n" << expression << "-> n" << expression->right.get() << std::endl;

  expression->left->Accept(this);
  expression->right->Accept(this);
}

void Printer::Visit(AddExpression* expression) {
  file << "n" << expression << " [label = \" + \" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void Printer::Visit(SubstractExpression* expression) {
  file << "n" << expression << " [label =  \" - \"]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void Printer::Visit(MulExpression* expression) {
  file << "n" << expression << " [label =  \" * \" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void Printer::Visit(AtExpression* expression) {
  file << "n" << expression << " [label = \"expr[ expr ]\" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}

void Printer::Visit(LengthExpression* expression) {
  file << "n" << expression << " [label = \"expr.Length\" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->expr.get() << std::endl;

  expression->expr->Accept(this);

}
void Printer::Visit(NewArrayExpression* expression) {
  file << "n" << expression << " [label =  \"new " << expression->type << " [expr]\" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->expr.get() << std::endl;

  expression->expr->Accept(this);

}

void Printer::Visit(NewExpression* expression) {
  file << "n" << expression << " [label =  \"new " << expression->type << " ()\" ]" << std::endl;
}

void Printer::Visit(NegExpression* expression) {
  file << "n" << expression << " [label =  \"!(...)\" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->expr.get() << std::endl;

  expression->expr->Accept(this);
}

void Printer::Visit(InBrExpression* expression) {
  file << "n" << expression << " [label =  \"(...)\" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->expr.get() << std::endl;

  expression->expr->Accept(this);
}

void Printer::Visit(ThisExpression* expression) {
  file << "n" << expression << " [label =  \"this\" ]" << std::endl;
}

void Printer::Visit(LogicExpression* expression) {
  file << "n" << expression << " [label =  \"" << expression->value << "\" ]" << std::endl;
}

void Printer::Visit(MInvExpression* expression) {
  file << "n" << expression << " [label =  \"expr." << expression->identifier
       << "( expr )\" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->expr.get() << std::endl;
  expression->expr->Accept(this);

  for (auto st : expression->expr_list) {
    file << "n" << expression << "-> n" << st.get() << std::endl;
    st->Accept(this);
  }
}

void Printer::Visit(IdentifierExpression* expression) {
  file << "n" << expression << " [label =  \" " << expression->identifier
       << "\"]" << std::endl;
}

void Printer::Visit(DivExpression* expression) {
  file << "n" << expression << " [label =  \" / \" ]" << std::endl;
  file << "n" << expression << "-> n" << expression->lhv.get() << std::endl;
  file << "n" << expression << "-> n" << expression->rhv.get() << std::endl;

  expression->lhv->Accept(this);
  expression->rhv->Accept(this);
}



void Printer::SetTosValue(int value) {
    tos_value_ = value;
    is_tos_expression_ = true;
}

void Printer::UnsetTosValue() {
    tos_value_ = 0;
    is_tos_expression_ = false;
}

int Printer::GetResult(Program *program) {
    UnsetTosValue();
    return tos_value_;
}
