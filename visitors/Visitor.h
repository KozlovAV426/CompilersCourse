#pragma once

#include "forward_decl.h"

class Visitor {
 public:

    virtual void Visit(AssertStatement* statement) = 0;
    virtual void Visit(IfElseStatement* statement) = 0;
    virtual void Visit(IfStatement* statement) = 0;
    virtual void Visit(InCurlyBrStatement* statement) = 0;
    virtual void Visit(LAssignStatement* statement) = 0;
    virtual void Visit(LVDStatement* statement) = 0;
    virtual void Visit(ReturnStatement* statement) = 0;
    virtual void Visit(SOPrintlnStatement* statement) = 0;
    virtual void Visit(WhileStatement* statement) = 0;

    virtual void Visit(ClassDeclaration* declaration) = 0;
    virtual void Visit(MethodDeclaration* declaration) = 0;
    virtual void Visit(VarDeclaration* declaration) = 0;

    virtual void Visit(ArrayIdentifier* identifier) = 0;
    virtual void Visit(STIdentifier* identifier) = 0;

    virtual void Visit(MainClass* main_class) = 0;
    virtual void Visit(Program* program) = 0;

    virtual void Visit(CertainType* type) = 0;


    virtual void Visit(OrExpression* expression) = 0;
    virtual void Visit(IsLessExpression* expression) = 0;
    virtual void Visit(AndExpression* expression) = 0;
    virtual void Visit(IsGreaterExpression* expression) = 0;
    virtual void Visit(IsEqualExpression* expression) = 0;
    virtual void Visit(AddExpression* expression) = 0;
    virtual void Visit(SubstractExpression* expression) = 0;
    virtual void Visit(MulExpression* expression) = 0;
    virtual void Visit(DivExpression* expression) = 0;
    virtual void Visit(ModuloExpression* expression) = 0;
    virtual void Visit(AtExpression* expression) = 0;
    virtual void Visit(LengthExpression* expression) = 0;
    virtual void Visit(NewArrayExpression* expression) = 0;
    virtual void Visit(NewExpression* expression) = 0;
    virtual void Visit(NegExpression* expression) = 0;
    virtual void Visit(InBrExpression* expression)= 0;
    virtual void Visit(IdentifierExpression* expression) = 0;
    virtual void Visit(NumberExpression* expression) = 0;
    virtual void Visit(ThisExpression* expression) = 0;
    virtual void Visit(LogicExpression* expression) = 0;
    virtual void Visit(MInvExpression* expression) = 0;

};
