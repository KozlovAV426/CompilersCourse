project(Visitor)
set(
    HEADERS
    driver.hh
    parser.hh
    )

BISON_TARGET(
    ParserVisitor
    parser.y
    ${Visitor_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${Visitor_SOURCE_DIR}/parser.hh
    COMPILE_FLAGS "--warnings=all --report=all --verbose"
)

FLEX_TARGET(
    ScannerVisitor
    scanner.l
    ${Visitor_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(ScannerVisitor ParserVisitor)

add_executable(
    VisitorExecutable
    main.cpp
    driver.cpp
    ${BISON_ParserVisitor_OUTPUTS}
    ${FLEX_ScannerVisitor_OUTPUTS}
    expressions/NumberExpression.cpp
    expressions/MulExpression.cpp
    expressions/AddExpression.cpp
    expressions/SubstractExpression.cpp
    expressions/DivExpression.cpp
        visitors/Printer.cpp
        expressions/ModuloExpression.h expressions/ModuloExpression.cpp expressions/AndExpression.h expressions/AndExpression.cpp expressions/OrExpression.h expressions/OrExpression.cpp expressions/IsLessExpression.h expressions/IsLessExpression.cpp expressions/IsGreaterExpression.h expressions/IsGreaterExpression.cpp expressions/IsEqualExpression.h expressions/IsEqualExpression.cpp expressions/AtExpression.h expressions/AtExpression.cpp expressions/LengthExpression.h expressions/LengthExpression.cpp expressions/NewArrayExpression.h expressions/NewArrayExpression.cpp expressions/NewExpression.h expressions/NewExpression.cpp expressions/NegExpression.h expressions/NegExpression.cpp expressions/InBrExpression.cpp expressions/InBrExpression.h expressions/IdentifierExpression.cpp expressions/IdentifierExpression.h expressions/ThisExpression.h expressions/ThisExpression.cpp expressions/LogicExpression.h expressions/LogicExpression.cpp expressions/MInvExpression.h expressions/MInvExpression.cpp statement/Statement.h statement/AssertStatement.h statement/AssertStatement.cpp statement/InCurlyBrStatement.h statement/InCurlyBrStatement.cpp statement/IfStatement.h statement/IfStatement.cpp statement/IfElseStatement.h statement/IfElseStatement.cpp statement/WhileStatement.h statement/WhileStatement.cpp statement/SOPrintlnStatement.h statement/SOPrintlnStatement.cpp statement/ReturnStatement.cpp statement/ReturnStatement.h statement/LVDStatement.h statement/LVDStatement.cpp lvalue/STIdentifier.h lvalue/Lvalue.h lvalue/STIdentifier.cpp lvalue/ArrayIdentifier.h lvalue/ArrayIdentifier.cpp statement/LAssignStatement.h statement/LAssignStatement.cpp type/Type.h type/CertainType.h type/CertainType.cpp declaration/Declaration.h declaration/VarDeclaration.h declaration/VarDeclaration.cpp declaration/MethodDeclaration.h declaration/MethodDeclaration.cpp program/Program.h declaration/ClassDeclaration.h declaration/ClassDeclaration.cpp program/MainClass.h program/MainClass.cpp program/Program.cpp visitors/Interpreter.h visitors/Interpreter.cpp)

target_include_directories(
    VisitorExecutable PRIVATE ${Visitor_SOURCE_DIR}
)



