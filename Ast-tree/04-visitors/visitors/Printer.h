#include "Visitor.h"

#include <expressions/AndExpression.h>
#include <map>
#include <fstream>

class Printer : public Visitor {
 public:
  Printer(const std::string& filename);
  ~Printer();


  void Visit(Program* program) override;

  void Visit(CertainType* type) override;
  void Visit(AssertStatement *statement) override;
  void Visit(IfElseStatement* statement) override;
  void Visit(IfStatement* statement) override;
  void Visit(InCurlyBrStatement* statement) override;
  void Visit(LAssignStatement* statement) override;
  void Visit(LVDStatement* statement) override;
  void Visit(ReturnStatement* statement) override;
  void Visit(SOPrintlnStatement* statement) override;
  void Visit(WhileStatement* statement) override;

  void Visit(ClassDeclaration* declaration) override;
  void Visit(MethodDeclaration* declaration) override;
  void Visit(VarDeclaration* declaration) override;

  void Visit(ArrayIdentifier* identifier) override;
  void Visit(STIdentifier* identifier) override;

  void Visit(MainClass* main_class) override;


  void Visit(OrExpression* expression) override;
  void Visit(AndExpression* expression) override;
  void Visit(IsLessExpression* expression) override;
  void Visit(IsGreaterExpression* expression) override;
  void Visit(IsEqualExpression* expression) override;
  void Visit(AddExpression* expression) override;
  void Visit(SubstractExpression* expression) override;
  void Visit(MulExpression* expression) override;
  void Visit(DivExpression* expression) override;
  void Visit(ModuloExpression* expression) override;
  void Visit(AtExpression* expression) override;
  void Visit(LengthExpression* expression) override;
  void Visit(NewArrayExpression* expression) override;
  void Visit(NewExpression* expression) override;
  void Visit(NegExpression* expression) override;
  void Visit(InBrExpression* expression)override;
  void Visit(IdentifierExpression* expression) override;
  void Visit(NumberExpression* expression) override;
  void Visit(ThisExpression* expression) override;
  void Visit(LogicExpression* expression) override;
  void Visit(MInvExpression* expression) override;


  void Visit(IdentExpression* expression) override;

  int GetResult(Program* program);

 private:
    std::ofstream file;
    std::map<std::string, int> variables_;
    bool is_tos_expression_;
    int tos_value_;

    void SetTosValue(int value);
    void UnsetTosValue();

};