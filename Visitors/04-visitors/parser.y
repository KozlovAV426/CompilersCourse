%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <memory>
    class Scanner;
    class Driver;

    class Declaration;
    class ClassDeclaration;
    class MethodDeclaration;
    class VarDeclaration;

    class AddExpression;
    class AndExpression;
    class AtExpression;
    class DivExpression;
    class Expression;
    class IdentifierExpression;
    class InBrExpression;
    class IsEqualExpression;
    class IsGreaterExpression;
    class IsLessExpression;
    class LengthExpression;
    class LogicExpression;
    class MInvExpression;
    class ModuloExpression;
    class MulExpression;
    class NegExpression;
    class NewArrayExpression;
    class NewExpression;
    class NumberExpression;
    class OrExpression;
    class SubstractExpression;
    class ThisExpression;

    class Lvalue;
    class STIdentifier;
    class ArrayIdentifier;

    class Program;
    class MainClass;

    class AssertStatement;
    class IfElseStatement;
    class IfStatement;
    class InCurlyBrStatement;
    class LAssignStatement;
    class LVDStatement;
    class ReturnStatement;
    class SOPrintlnStatement;
    class Statement;
    class WhileStatement;

    class Type;
    class CertainType;

    template <typename T>
    using ptr = std::shared_ptr<T>;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "declaration/Declaration.h"
    #include "declaration/ClassDeclaration.h"
    #include "declaration/MethodDeclaration.h"
    #include "declaration/VarDeclaration.h"

    #include "expressions/AddExpression.h"
    #include "expressions/AndExpression.h"
    #include "expressions/AtExpression.h"
    #include "expressions/DivExpression.h"
    #include "expressions/Expression.h"
    #include "expressions/IdentifierExpression.h"
    #include "expressions/InBrExpression.h"
    #include "expressions/IsEqualExpression.h"
    #include "expressions/IsGreaterExpression.h"
    #include "expressions/IsLessExpression.h"
    #include "expressions/LengthExpression.h"
    #include "expressions/LogicExpression.h"
    #include "expressions/MInvExpression.h"
    #include "expressions/ModuloExpression.h"
    #include "expressions/MulExpression.h"
    #include "expressions/NegExpression.h"
    #include "expressions/NewArrayExpression.h"
    #include "expressions/NewExpression.h"
    #include "expressions/NumberExpression.h"
    #include "expressions/OrExpression.h"
    #include "expressions/SubstractExpression.h"
    #include "expressions/ThisExpression.h"

    #include "lvalue/Lvalue.h"
    #include "lvalue/STIdentifier.h"
    #include "lvalue/ArrayIdentifier.h"

    #include "program/Program.h"
    #include "program/MainClass.h"

    #include "statement/AssertStatement.h"
    #include "statement/IfElseStatement.h"
    #include "statement/IfStatement.h"
    #include "statement/InCurlyBrStatement.h"
    #include "statement/LAssignStatement.h"
    #include "statement/LVDStatement.h"
    #include "statement/ReturnStatement.h"
    #include "statement/SOPrintlnStatement.h"
    #include "statement/Statement.h"
    #include "statement/WhileStatement.h"

    #include "type/Type.h"
    #include "type/CertainType.h"


    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
    ISEQUAL "=="
    AND "&&"
    OR "||"
    MODULO "%"
    LESS "<"
    GREATER ">"
    SEMICOLON ";"
    TYPEINT "int"
    ASSERT "assert"
    SOPRINTLN "System.out.println"
    CLBRACKET "{"
    CRBRACKET "}"
    SLBRACKET "["
    SRBRACKET "]"
    CLASS "class"
    PUBLIC "public"
    STATIC "static"
    VOID "void"
    MAIN "main"
    NEW "new"
    DOT "."
    LENGTH "length"
    EXTENDS "extends"
    BOOLEAN "boolean"
    IF "if"
    ELSE "else"
    WHILE "while"
    RETURN "return"
    COLON  ","
    NEGATION "!"
    THIS "this"
    TRUE "true"
    FALSE "false"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <ptr<Expression>> expr
%nterm <ptr<MInvExpression>> method_invocation

%nterm <std::vector<ptr<Expression>>> list_expr

%nterm <ptr<Program>> unit

%nterm <ptr<Statement>> statement
%nterm <std::vector<ptr<Statement>>> statements

%nterm <ptr<Declaration>> declaration
%nterm <ptr<Declaration>> variable_declaration
%nterm <ptr<Declaration>> method_declaration
%nterm <std::vector<ptr<Declaration>>> declarations

%nterm <ptr<ClassDeclaration>> class_declaration
%nterm <std::vector<ptr<ClassDeclaration>>> classes_declarations

%nterm <ptr<Program>> program

%nterm <ptr<Statement>> local_variable_declaration

%nterm <ptr<VarDeclaration>> argument
%nterm <std::vector<ptr<VarDeclaration>>> arguments
%nterm <std::vector<ptr<VarDeclaration>>> formals

%nterm <ptr<MainClass>> main_class


%nterm <ptr<Lvalue>> lvalue

%nterm <int> signed_number
%nterm <std::string> logic



%nterm <std::string> type
%nterm <std::string> simple_type
%nterm <std::string> array_type
%nterm <std::string> type_identifier

// %printer { yyo << $$; } <*>;

%left "+" "-";
%left "*" "/";
%precedence ".";
%precedence ")";
%precedence "else";

%%
%start unit;

unit: program {$$ = $1; driver.program = $1;}

program:
    main_class classes_declarations {$$ = std::make_shared<Program>($1, $2);}

classes_declarations:
    %empty {$$ = std::vector<ptr<ClassDeclaration>>(); }
    | classes_declarations class_declaration {$1.push_back($2); $$ = $1;}

main_class:
    "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statements "}" "}"
    {$$ = std::make_shared<MainClass>($2, $11);}


statements:
    %empty {$$ = std::vector<ptr<Statement>>();}
    | statements statement {$1.push_back($2); $$ = $1;}

class_declaration:
    "class" "identifier"  "{" declarations "}" {
        $$ = std::make_shared<ClassDeclaration>($2, "", $4);}

    | "class" "identifier" "extends" "identifier" "{" declarations "}" {
        $$ = std::make_shared<ClassDeclaration>($2, $4, $6);}


declarations:
    %empty {$$ = std::vector<ptr<Declaration>>();}
    | declarations declaration {$1.push_back($2); $$ = $1;}

declaration:
    variable_declaration {$$ = $1;}
    | method_declaration {$$ = $1;}

method_declaration:
    "public" type "identifier" "(" ")" "{" statements "}" {
            $$ = std::make_shared<MethodDeclaration>
            ($2, $3, std::vector<ptr<VarDeclaration>>(), $7); }

    | "public" type "identifier" "(" formals ")" "{" statements "}" {
        $$ = std::make_shared<MethodDeclaration>($2, $3, $5, $8);
    }


variable_declaration:
    type "identifier" ";" {$$ = std::make_shared<VarDeclaration>($1, $2);}

arguments:
    %empty {$$ = std::vector<ptr<VarDeclaration>>();}
    | argument {$$.push_back($1);}
    | arguments "," argument {$1.push_back($3); $$ = $1; }

argument:
    type "identifier" {$$ = std::make_shared<VarDeclaration>($1, $2);}

formals:
    type "identifier" arguments {$3.insert($3.begin(), std::make_shared<VarDeclaration>($1, $2));
                                   $$ = $3;}

type:
    simple_type {$$ = $1;}
    | array_type {$$ = $1;}

simple_type:
    "int" {$$ = "int"; }
    | "boolean" {$$ = "boolean";}
    | "void" {$$ = "void";}
    | type_identifier {$$ = $1;}

array_type:
    simple_type "[" "]" {$$ = $1;}

type_identifier:
    "identifier" {$$ = $1;}

statement:
    "assert" "(" expr ")" ";" {$$ =  std::make_shared<AssertStatement>($3);}
    | local_variable_declaration {$$ = $1;}
    | "{" statements "}" {$$ = std::make_shared<InCurlyBrStatement>($2);}
    | "if"  "(" expr ")" statement  {$$ = std::make_shared<IfStatement>($3, $5);}
    | "if"  "(" expr ")" statement "else" statement {$$ = std::make_shared<IfElseStatement>($3, $5, $7);}
    | "while" "(" expr ")" statement {$$ = std::make_shared<WhileStatement>($3, $5);}
    | "System.out.println" "(" expr ")" ";" {$$ = std::make_shared<SOPrintlnStatement>($3);}
    | lvalue "=" expr ";" {$$ = std::make_shared<LAssignStatement>($1, $3);}
    | "return" expr ";" {$$ = std::make_shared<ReturnStatement>($2);}
    | method_invocation ";" {$$ = $1;}

local_variable_declaration:
    variable_declaration {
        auto vd = static_cast<VarDeclaration*>($1.get());
        $$ = std::make_shared<LVDStatement>(vd->type, vd->identifier);
    }


list_expr:
    %empty {$$ = std::vector<ptr<Expression>>();}
    | expr {$$.push_back($1);}
    | list_expr "," expr {$1.push_back($3); $$ = $1; }

method_invocation:
    expr "." "identifier" "(" ")" {$$ = std::make_shared<MInvExpression>
                        ($1, $3, std::vector<ptr<Expression>>()); }
    | expr "." "identifier" "(" list_expr ")" {$$ = std::make_shared<MInvExpression>
                                 ($1, $3, $5);}

lvalue:
    "identifier" {$$ = std::make_shared<STIdentifier>($1);}
    | "identifier" "[" expr "]" {$$ = std::make_shared<ArrayIdentifier>($1, $3);}

expr:
    expr "&&" expr {$$ = std::make_shared<AndExpression>($1, $3);}
    | expr "||" expr {$$ = std::make_shared<OrExpression>($1, $3);}
    | expr "<" expr {$$ = std::make_shared<IsLessExpression>($1, $3);}
    | expr ">" expr {$$ = std::make_shared<IsGreaterExpression>($1, $3);}
    | expr "==" expr {$$ = std::make_shared<IsEqualExpression>($1, $3);}
    | expr "+" expr {$$ = std::make_shared<AddExpression>($1, $3);}
    | expr "-" expr {$$ = std::make_shared<SubstractExpression>($1, $3);}
    | expr "*" expr {$$ = std::make_shared<MulExpression>($1, $3);}
    | expr "/" expr {$$ = std::make_shared<DivExpression>($1, $3);}
    | expr "%" expr {$$ = std::make_shared<ModuloExpression>($1, $3);}
    | expr "[" expr "]"  {$$ = std::make_shared<AtExpression>($1, $3);}
    | expr "." "length"  {$$ = std::make_shared<LengthExpression>($1);}
    | "new" simple_type "[" expr "]" {$$ = std::make_shared<NewArrayExpression>($2, $4);}
    | "new" type_identifier "(" ")" {$$ = std::make_shared<NewExpression>($2);}
    | "!" expr {$$ = std::make_shared<NegExpression>($2);}
    | "(" expr ")"  {$$ = std::make_shared<InBrExpression>($2);}
    | "identifier" {$$ = std::make_shared<IdentifierExpression>($1);}
    |  signed_number {$$ = std::make_shared<NumberExpression>($1);}
    | "this" {$$ = std::make_shared<ThisExpression>();}
    | logic {$$ = std::make_shared<LogicExpression>($1);}
    | method_invocation {$$ = $1;}

logic:
    "false" {$$ = "false";}
    | "true" {$$ = "true";}

signed_number:
    "-" "number" {$$ = -$2;}
    | "number" {$$ = $1;}
 %%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
