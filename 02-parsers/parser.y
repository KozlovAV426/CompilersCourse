%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"
    #include <cassert>

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
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"

%nterm <int> exp
%nterm <int> statements
%nterm <int> program

%printer { /*yyo << $$;*/ } <*>;



%left "+" "-";
%left "*" "/";


%%
%start unit;
unit: program { driver.result = $1; }

program:
    "class" "identifier" "{"
    "public" "static" "void" "main" "(" ")" "{"
     statements "}"
    "}"

statements:
    %empty {}
    | statements statement {}


variable_declaration:
    simple_type | array_type

simple_type:
    "int" "identifier"
    { if (driver.variables.find($2) == driver.variables.end() &&
        driver.array_variables.find($2) == driver.array_variables.end()) {
      driver.variables[$2] = 0; }
     }

array_type:
    "int" "[" "]" "identifier" {
    if (driver.variables.find($4) == driver.variables.end() &&
            driver.array_variables.find($4) == driver.array_variables.end()) {
          driver.array_variables[$4] = std::vector<int>(1);
    }
    }

statement:
    ASSERT "(" exp ")" ";" { assert($3); }
    |  variable_declaration ";" {}
    | "{" statement "}" {}
    | "System.out.println" "(" exp ")" ";" { std::cout << $3 << std::endl; }
    |  assignment ";" {}


assignment:
    "identifier" "=" exp {
         if (driver.variables.find($1) != driver.variables.end()) {
                        driver.variables[$1] = $3;
                   }
                   else {
                    std::cout << "ERROR: Undeclared variable --> " << $1 << std::endl;
                    exit(1);
                   }
                   }
    |  "identifier" "=" "new" "int" "[" exp "]" {
       if (driver.array_variables.find($1) != driver.array_variables.end()) {
           driver.array_variables[$1] = std::vector<int>($6);
       }
       else {
           std::cout << "ERROR: Undeclared variable" << std::endl;
           exit(1);
       }
    }
    | "identifier" "[" exp "]" "=" exp {driver.array_variables[$1][$3] = $6;}


exp:
      exp "+" exp {$$ = $1 + $3; }
    | exp "-" exp {$$ = $1 - $3; }
    | exp "*" exp {$$ = $1 * $3; }
    | exp "/" exp {$$ = $1 / $3; }
    | exp "&&" exp {$$ = $1 && $3; }
    | exp "||" exp {$$ = $1 || $3; }
    | exp "<" exp {$$ = $1 < $3; }
    | exp ">" exp {$$ = $1 > $3; }
    | exp "==" exp {$$ = $1 == $3; }
    | exp "%" exp {$$ = $1 && $3; }
    | "identifier" "." "length" {
        if (driver.array_variables.find($1) != driver.array_variables.end()) {
            $$ = driver.array_variables[$1].size(); }
            else {
             std::cout << "ERROR: Undeclared variable --> " << $1 << std::endl;
            }
        }
    | "identifier" "[" exp "]" {$$ = driver.array_variables[$1][$3]; }
    | "!" exp {$$ = !$2; }
    | "(" exp ")" {$$ = $2; };
    |"number"
    | "identifier"
        { if (driver.variables.find($1) != driver.variables.end()) {
            $$ = driver.variables[$1]; }
          else {
            std::cout << "ERROR: Undeclared variable --> " << $1 << std::endl;
          }
        }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << "ERROR " << l << ": " << m << '\n';
  exit(1);
}
