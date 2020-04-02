// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 73 "parser.y"

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

#line 104 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 195 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 44: // "number"
      case 65: // signed_number
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 56: // class_declaration
        value.YY_MOVE_OR_COPY< ptr<ClassDeclaration> > (YY_MOVE (that.value));
        break;

      case 52: // declaration
      case 53: // variable_declaration
      case 54: // method_declaration
        value.YY_MOVE_OR_COPY< ptr<Declaration> > (YY_MOVE (that.value));
        break;

      case 46: // expr
        value.YY_MOVE_OR_COPY< ptr<Expression> > (YY_MOVE (that.value));
        break;

      case 64: // lvalue
        value.YY_MOVE_OR_COPY< ptr<Lvalue> > (YY_MOVE (that.value));
        break;

      case 47: // method_invocation
        value.YY_MOVE_OR_COPY< ptr<MInvExpression> > (YY_MOVE (that.value));
        break;

      case 63: // main_class
        value.YY_MOVE_OR_COPY< ptr<MainClass> > (YY_MOVE (that.value));
        break;

      case 49: // unit
      case 58: // program
        value.YY_MOVE_OR_COPY< ptr<Program> > (YY_MOVE (that.value));
        break;

      case 50: // statement
      case 59: // local_variable_declaration
        value.YY_MOVE_OR_COPY< ptr<Statement> > (YY_MOVE (that.value));
        break;

      case 60: // argument
        value.YY_MOVE_OR_COPY< ptr<VarDeclaration> > (YY_MOVE (that.value));
        break;

      case 43: // "identifier"
      case 66: // logic
      case 67: // type
      case 68: // simple_type
      case 69: // array_type
      case 70: // type_identifier
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 57: // classes_declarations
        value.YY_MOVE_OR_COPY< std::vector<ptr<ClassDeclaration>> > (YY_MOVE (that.value));
        break;

      case 55: // declarations
        value.YY_MOVE_OR_COPY< std::vector<ptr<Declaration>> > (YY_MOVE (that.value));
        break;

      case 48: // list_expr
        value.YY_MOVE_OR_COPY< std::vector<ptr<Expression>> > (YY_MOVE (that.value));
        break;

      case 51: // statements
        value.YY_MOVE_OR_COPY< std::vector<ptr<Statement>> > (YY_MOVE (that.value));
        break;

      case 61: // arguments
      case 62: // formals
        value.YY_MOVE_OR_COPY< std::vector<ptr<VarDeclaration>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 44: // "number"
      case 65: // signed_number
        value.move< int > (YY_MOVE (that.value));
        break;

      case 56: // class_declaration
        value.move< ptr<ClassDeclaration> > (YY_MOVE (that.value));
        break;

      case 52: // declaration
      case 53: // variable_declaration
      case 54: // method_declaration
        value.move< ptr<Declaration> > (YY_MOVE (that.value));
        break;

      case 46: // expr
        value.move< ptr<Expression> > (YY_MOVE (that.value));
        break;

      case 64: // lvalue
        value.move< ptr<Lvalue> > (YY_MOVE (that.value));
        break;

      case 47: // method_invocation
        value.move< ptr<MInvExpression> > (YY_MOVE (that.value));
        break;

      case 63: // main_class
        value.move< ptr<MainClass> > (YY_MOVE (that.value));
        break;

      case 49: // unit
      case 58: // program
        value.move< ptr<Program> > (YY_MOVE (that.value));
        break;

      case 50: // statement
      case 59: // local_variable_declaration
        value.move< ptr<Statement> > (YY_MOVE (that.value));
        break;

      case 60: // argument
        value.move< ptr<VarDeclaration> > (YY_MOVE (that.value));
        break;

      case 43: // "identifier"
      case 66: // logic
      case 67: // type
      case 68: // simple_type
      case 69: // array_type
      case 70: // type_identifier
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 57: // classes_declarations
        value.move< std::vector<ptr<ClassDeclaration>> > (YY_MOVE (that.value));
        break;

      case 55: // declarations
        value.move< std::vector<ptr<Declaration>> > (YY_MOVE (that.value));
        break;

      case 48: // list_expr
        value.move< std::vector<ptr<Expression>> > (YY_MOVE (that.value));
        break;

      case 51: // statements
        value.move< std::vector<ptr<Statement>> > (YY_MOVE (that.value));
        break;

      case 61: // arguments
      case 62: // formals
        value.move< std::vector<ptr<VarDeclaration>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 44: // "number"
      case 65: // signed_number
        value.copy< int > (that.value);
        break;

      case 56: // class_declaration
        value.copy< ptr<ClassDeclaration> > (that.value);
        break;

      case 52: // declaration
      case 53: // variable_declaration
      case 54: // method_declaration
        value.copy< ptr<Declaration> > (that.value);
        break;

      case 46: // expr
        value.copy< ptr<Expression> > (that.value);
        break;

      case 64: // lvalue
        value.copy< ptr<Lvalue> > (that.value);
        break;

      case 47: // method_invocation
        value.copy< ptr<MInvExpression> > (that.value);
        break;

      case 63: // main_class
        value.copy< ptr<MainClass> > (that.value);
        break;

      case 49: // unit
      case 58: // program
        value.copy< ptr<Program> > (that.value);
        break;

      case 50: // statement
      case 59: // local_variable_declaration
        value.copy< ptr<Statement> > (that.value);
        break;

      case 60: // argument
        value.copy< ptr<VarDeclaration> > (that.value);
        break;

      case 43: // "identifier"
      case 66: // logic
      case 67: // type
      case 68: // simple_type
      case 69: // array_type
      case 70: // type_identifier
        value.copy< std::string > (that.value);
        break;

      case 57: // classes_declarations
        value.copy< std::vector<ptr<ClassDeclaration>> > (that.value);
        break;

      case 55: // declarations
        value.copy< std::vector<ptr<Declaration>> > (that.value);
        break;

      case 48: // list_expr
        value.copy< std::vector<ptr<Expression>> > (that.value);
        break;

      case 51: // statements
        value.copy< std::vector<ptr<Statement>> > (that.value);
        break;

      case 61: // arguments
      case 62: // formals
        value.copy< std::vector<ptr<VarDeclaration>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 44: // "number"
      case 65: // signed_number
        value.move< int > (that.value);
        break;

      case 56: // class_declaration
        value.move< ptr<ClassDeclaration> > (that.value);
        break;

      case 52: // declaration
      case 53: // variable_declaration
      case 54: // method_declaration
        value.move< ptr<Declaration> > (that.value);
        break;

      case 46: // expr
        value.move< ptr<Expression> > (that.value);
        break;

      case 64: // lvalue
        value.move< ptr<Lvalue> > (that.value);
        break;

      case 47: // method_invocation
        value.move< ptr<MInvExpression> > (that.value);
        break;

      case 63: // main_class
        value.move< ptr<MainClass> > (that.value);
        break;

      case 49: // unit
      case 58: // program
        value.move< ptr<Program> > (that.value);
        break;

      case 50: // statement
      case 59: // local_variable_declaration
        value.move< ptr<Statement> > (that.value);
        break;

      case 60: // argument
        value.move< ptr<VarDeclaration> > (that.value);
        break;

      case 43: // "identifier"
      case 66: // logic
      case 67: // type
      case 68: // simple_type
      case 69: // array_type
      case 70: // type_identifier
        value.move< std::string > (that.value);
        break;

      case 57: // classes_declarations
        value.move< std::vector<ptr<ClassDeclaration>> > (that.value);
        break;

      case 55: // declarations
        value.move< std::vector<ptr<Declaration>> > (that.value);
        break;

      case 48: // list_expr
        value.move< std::vector<ptr<Expression>> > (that.value);
        break;

      case 51: // statements
        value.move< std::vector<ptr<Statement>> > (that.value);
        break;

      case 61: // arguments
      case 62: // formals
        value.move< std::vector<ptr<VarDeclaration>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 44: // "number"
      case 65: // signed_number
        yylhs.value.emplace< int > ();
        break;

      case 56: // class_declaration
        yylhs.value.emplace< ptr<ClassDeclaration> > ();
        break;

      case 52: // declaration
      case 53: // variable_declaration
      case 54: // method_declaration
        yylhs.value.emplace< ptr<Declaration> > ();
        break;

      case 46: // expr
        yylhs.value.emplace< ptr<Expression> > ();
        break;

      case 64: // lvalue
        yylhs.value.emplace< ptr<Lvalue> > ();
        break;

      case 47: // method_invocation
        yylhs.value.emplace< ptr<MInvExpression> > ();
        break;

      case 63: // main_class
        yylhs.value.emplace< ptr<MainClass> > ();
        break;

      case 49: // unit
      case 58: // program
        yylhs.value.emplace< ptr<Program> > ();
        break;

      case 50: // statement
      case 59: // local_variable_declaration
        yylhs.value.emplace< ptr<Statement> > ();
        break;

      case 60: // argument
        yylhs.value.emplace< ptr<VarDeclaration> > ();
        break;

      case 43: // "identifier"
      case 66: // logic
      case 67: // type
      case 68: // simple_type
      case 69: // array_type
      case 70: // type_identifier
        yylhs.value.emplace< std::string > ();
        break;

      case 57: // classes_declarations
        yylhs.value.emplace< std::vector<ptr<ClassDeclaration>> > ();
        break;

      case 55: // declarations
        yylhs.value.emplace< std::vector<ptr<Declaration>> > ();
        break;

      case 48: // list_expr
        yylhs.value.emplace< std::vector<ptr<Expression>> > ();
        break;

      case 51: // statements
        yylhs.value.emplace< std::vector<ptr<Statement>> > ();
        break;

      case 61: // arguments
      case 62: // formals
        yylhs.value.emplace< std::vector<ptr<VarDeclaration>> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 239 "parser.y"
              {yylhs.value.as < ptr<Program> > () = yystack_[0].value.as < ptr<Program> > (); driver.program = yystack_[0].value.as < ptr<Program> > ();}
#line 998 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 3:
#line 242 "parser.y"
                                    {yylhs.value.as < ptr<Program> > () = std::make_shared<Program>(yystack_[1].value.as < ptr<MainClass> > (), yystack_[0].value.as < std::vector<ptr<ClassDeclaration>> > ());}
#line 1004 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 4:
#line 245 "parser.y"
           {yylhs.value.as < std::vector<ptr<ClassDeclaration>> > () = std::vector<ptr<ClassDeclaration>>(); }
#line 1010 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 5:
#line 246 "parser.y"
                                             {yystack_[1].value.as < std::vector<ptr<ClassDeclaration>> > ().push_back(yystack_[0].value.as < ptr<ClassDeclaration> > ()); yylhs.value.as < std::vector<ptr<ClassDeclaration>> > () = yystack_[1].value.as < std::vector<ptr<ClassDeclaration>> > ();}
#line 1016 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 6:
#line 250 "parser.y"
    {yylhs.value.as < ptr<MainClass> > () = std::make_shared<MainClass>(yystack_[11].value.as < std::string > (), yystack_[2].value.as < std::vector<ptr<Statement>> > ());}
#line 1022 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 7:
#line 254 "parser.y"
           {yylhs.value.as < std::vector<ptr<Statement>> > () = std::vector<ptr<Statement>>();}
#line 1028 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 8:
#line 255 "parser.y"
                           {yystack_[1].value.as < std::vector<ptr<Statement>> > ().push_back(yystack_[0].value.as < ptr<Statement> > ()); yylhs.value.as < std::vector<ptr<Statement>> > () = yystack_[1].value.as < std::vector<ptr<Statement>> > ();}
#line 1034 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 9:
#line 258 "parser.y"
                                               {
        yylhs.value.as < ptr<ClassDeclaration> > () = std::make_shared<ClassDeclaration>(yystack_[3].value.as < std::string > (), "", yystack_[1].value.as < std::vector<ptr<Declaration>> > ());}
#line 1041 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 10:
#line 261 "parser.y"
                                                                       {
        yylhs.value.as < ptr<ClassDeclaration> > () = std::make_shared<ClassDeclaration>(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptr<Declaration>> > ());}
#line 1048 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 11:
#line 266 "parser.y"
           {yylhs.value.as < std::vector<ptr<Declaration>> > () = std::vector<ptr<Declaration>>();}
#line 1054 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 12:
#line 267 "parser.y"
                               {yystack_[1].value.as < std::vector<ptr<Declaration>> > ().push_back(yystack_[0].value.as < ptr<Declaration> > ()); yylhs.value.as < std::vector<ptr<Declaration>> > () = yystack_[1].value.as < std::vector<ptr<Declaration>> > ();}
#line 1060 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 13:
#line 270 "parser.y"
                         {yylhs.value.as < ptr<Declaration> > () = yystack_[0].value.as < ptr<Declaration> > ();}
#line 1066 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 14:
#line 271 "parser.y"
                         {yylhs.value.as < ptr<Declaration> > () = yystack_[0].value.as < ptr<Declaration> > ();}
#line 1072 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 15:
#line 274 "parser.y"
                                                          {
            yylhs.value.as < ptr<Declaration> > () = std::make_shared<MethodDeclaration>
            (yystack_[6].value.as < std::string > (), yystack_[5].value.as < std::string > (), std::vector<ptr<VarDeclaration>>(), yystack_[1].value.as < std::vector<ptr<Statement>> > ()); }
#line 1080 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 16:
#line 278 "parser.y"
                                                                    {
        yylhs.value.as < ptr<Declaration> > () = std::make_shared<MethodDeclaration>(yystack_[7].value.as < std::string > (), yystack_[6].value.as < std::string > (), yystack_[4].value.as < std::vector<ptr<VarDeclaration>> > (), yystack_[1].value.as < std::vector<ptr<Statement>> > ());
    }
#line 1088 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 17:
#line 284 "parser.y"
                          {yylhs.value.as < ptr<Declaration> > () = std::make_shared<VarDeclaration>(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ());}
#line 1094 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 18:
#line 287 "parser.y"
           {yylhs.value.as < std::vector<ptr<VarDeclaration>> > () = std::vector<ptr<VarDeclaration>>();}
#line 1100 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 19:
#line 288 "parser.y"
               {yylhs.value.as < std::vector<ptr<VarDeclaration>> > ().push_back(yystack_[0].value.as < ptr<VarDeclaration> > ());}
#line 1106 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 20:
#line 289 "parser.y"
                             {yystack_[2].value.as < std::vector<ptr<VarDeclaration>> > ().push_back(yystack_[0].value.as < ptr<VarDeclaration> > ()); yylhs.value.as < std::vector<ptr<VarDeclaration>> > () = yystack_[2].value.as < std::vector<ptr<VarDeclaration>> > (); }
#line 1112 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 21:
#line 292 "parser.y"
                      {yylhs.value.as < ptr<VarDeclaration> > () = std::make_shared<VarDeclaration>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());}
#line 1118 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 22:
#line 295 "parser.y"
                                {yystack_[0].value.as < std::vector<ptr<VarDeclaration>> > ().insert(yystack_[0].value.as < std::vector<ptr<VarDeclaration>> > ().begin(), std::make_shared<VarDeclaration>(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ()));
                                   yylhs.value.as < std::vector<ptr<VarDeclaration>> > () = yystack_[0].value.as < std::vector<ptr<VarDeclaration>> > ();}
#line 1125 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 23:
#line 299 "parser.y"
                {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1131 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 24:
#line 300 "parser.y"
                 {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1137 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 25:
#line 303 "parser.y"
          {yylhs.value.as < std::string > () = "int"; }
#line 1143 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 26:
#line 304 "parser.y"
                {yylhs.value.as < std::string > () = "boolean";}
#line 1149 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 27:
#line 305 "parser.y"
             {yylhs.value.as < std::string > () = "void";}
#line 1155 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 28:
#line 306 "parser.y"
                      {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1161 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 29:
#line 309 "parser.y"
                        {yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();}
#line 1167 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 30:
#line 312 "parser.y"
                 {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1173 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 31:
#line 315 "parser.y"
                              {yylhs.value.as < ptr<Statement> > () =  std::make_shared<AssertStatement>(yystack_[2].value.as < ptr<Expression> > ());}
#line 1179 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 32:
#line 316 "parser.y"
                                 {yylhs.value.as < ptr<Statement> > () = yystack_[0].value.as < ptr<Statement> > ();}
#line 1185 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 33:
#line 317 "parser.y"
                         {yylhs.value.as < ptr<Statement> > () = std::make_shared<InCurlyBrStatement>(yystack_[1].value.as < std::vector<ptr<Statement>> > ());}
#line 1191 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 34:
#line 318 "parser.y"
                                    {yylhs.value.as < ptr<Statement> > () = std::make_shared<IfStatement>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Statement> > ());}
#line 1197 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 35:
#line 319 "parser.y"
                                                    {yylhs.value.as < ptr<Statement> > () = std::make_shared<IfElseStatement>(yystack_[4].value.as < ptr<Expression> > (), yystack_[2].value.as < ptr<Statement> > (), yystack_[0].value.as < ptr<Statement> > ());}
#line 1203 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 36:
#line 320 "parser.y"
                                     {yylhs.value.as < ptr<Statement> > () = std::make_shared<WhileStatement>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Statement> > ());}
#line 1209 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 37:
#line 321 "parser.y"
                                            {yylhs.value.as < ptr<Statement> > () = std::make_shared<SOPrintlnStatement>(yystack_[2].value.as < ptr<Expression> > ());}
#line 1215 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 38:
#line 322 "parser.y"
                          {yylhs.value.as < ptr<Statement> > () = std::make_shared<LAssignStatement>(yystack_[3].value.as < ptr<Lvalue> > (), yystack_[1].value.as < ptr<Expression> > ());}
#line 1221 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 39:
#line 323 "parser.y"
                        {yylhs.value.as < ptr<Statement> > () = std::make_shared<ReturnStatement>(yystack_[1].value.as < ptr<Expression> > ());}
#line 1227 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 40:
#line 324 "parser.y"
                            {yylhs.value.as < ptr<Statement> > () = yystack_[1].value.as < ptr<MInvExpression> > ();}
#line 1233 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 41:
#line 327 "parser.y"
                         {
        auto vd = static_cast<VarDeclaration*>(yystack_[0].value.as < ptr<Declaration> > ().get());
        yylhs.value.as < ptr<Statement> > () = std::make_shared<LVDStatement>(vd->type, vd->identifier);
    }
#line 1242 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 42:
#line 334 "parser.y"
           {yylhs.value.as < std::vector<ptr<Expression>> > () = std::vector<ptr<Expression>>();}
#line 1248 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 43:
#line 335 "parser.y"
           {yylhs.value.as < std::vector<ptr<Expression>> > ().push_back(yystack_[0].value.as < ptr<Expression> > ());}
#line 1254 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 44:
#line 336 "parser.y"
                         {yystack_[2].value.as < std::vector<ptr<Expression>> > ().push_back(yystack_[0].value.as < ptr<Expression> > ()); yylhs.value.as < std::vector<ptr<Expression>> > () = yystack_[2].value.as < std::vector<ptr<Expression>> > (); }
#line 1260 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 45:
#line 339 "parser.y"
                                  {yylhs.value.as < ptr<MInvExpression> > () = std::make_shared<MInvExpression>
                        (yystack_[4].value.as < ptr<Expression> > (), yystack_[2].value.as < std::string > (), std::vector<ptr<Expression>>()); }
#line 1267 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 46:
#line 341 "parser.y"
                                              {yylhs.value.as < ptr<MInvExpression> > () = std::make_shared<MInvExpression>
                                 (yystack_[5].value.as < ptr<Expression> > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<ptr<Expression>> > ());}
#line 1274 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 47:
#line 345 "parser.y"
                 {yylhs.value.as < ptr<Lvalue> > () = std::make_shared<STIdentifier>(yystack_[0].value.as < std::string > ());}
#line 1280 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 48:
#line 346 "parser.y"
                                {yylhs.value.as < ptr<Lvalue> > () = std::make_shared<ArrayIdentifier>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < ptr<Expression> > ());}
#line 1286 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 49:
#line 349 "parser.y"
                   {yylhs.value.as < ptr<Expression> > () = std::make_shared<AndExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1292 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 50:
#line 350 "parser.y"
                     {yylhs.value.as < ptr<Expression> > () = std::make_shared<OrExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1298 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 51:
#line 351 "parser.y"
                    {yylhs.value.as < ptr<Expression> > () = std::make_shared<IsLessExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1304 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 52:
#line 352 "parser.y"
                    {yylhs.value.as < ptr<Expression> > () = std::make_shared<IsGreaterExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1310 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 53:
#line 353 "parser.y"
                     {yylhs.value.as < ptr<Expression> > () = std::make_shared<IsEqualExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1316 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 54:
#line 354 "parser.y"
                    {yylhs.value.as < ptr<Expression> > () = std::make_shared<AddExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1322 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 55:
#line 355 "parser.y"
                    {yylhs.value.as < ptr<Expression> > () = std::make_shared<SubstractExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1328 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 56:
#line 356 "parser.y"
                    {yylhs.value.as < ptr<Expression> > () = std::make_shared<MulExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1334 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 57:
#line 357 "parser.y"
                    {yylhs.value.as < ptr<Expression> > () = std::make_shared<DivExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1340 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 58:
#line 358 "parser.y"
                    {yylhs.value.as < ptr<Expression> > () = std::make_shared<ModuloExpression>(yystack_[2].value.as < ptr<Expression> > (), yystack_[0].value.as < ptr<Expression> > ());}
#line 1346 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 59:
#line 359 "parser.y"
                         {yylhs.value.as < ptr<Expression> > () = std::make_shared<AtExpression>(yystack_[3].value.as < ptr<Expression> > (), yystack_[1].value.as < ptr<Expression> > ());}
#line 1352 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 60:
#line 360 "parser.y"
                         {yylhs.value.as < ptr<Expression> > () = std::make_shared<LengthExpression>(yystack_[2].value.as < ptr<Expression> > ());}
#line 1358 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 61:
#line 361 "parser.y"
                                     {yylhs.value.as < ptr<Expression> > () = std::make_shared<NewArrayExpression>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < ptr<Expression> > ());}
#line 1364 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 62:
#line 362 "parser.y"
                                    {yylhs.value.as < ptr<Expression> > () = std::make_shared<NewExpression>(yystack_[2].value.as < std::string > ());}
#line 1370 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 63:
#line 363 "parser.y"
               {yylhs.value.as < ptr<Expression> > () = std::make_shared<NegExpression>(yystack_[0].value.as < ptr<Expression> > ());}
#line 1376 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 64:
#line 364 "parser.y"
                    {yylhs.value.as < ptr<Expression> > () = std::make_shared<InBrExpression>(yystack_[1].value.as < ptr<Expression> > ());}
#line 1382 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 65:
#line 365 "parser.y"
                   {yylhs.value.as < ptr<Expression> > () = std::make_shared<IdentifierExpression>(yystack_[0].value.as < std::string > ());}
#line 1388 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 66:
#line 366 "parser.y"
                     {yylhs.value.as < ptr<Expression> > () = std::make_shared<NumberExpression>(yystack_[0].value.as < int > ());}
#line 1394 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 67:
#line 367 "parser.y"
             {yylhs.value.as < ptr<Expression> > () = std::make_shared<ThisExpression>();}
#line 1400 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 68:
#line 368 "parser.y"
            {yylhs.value.as < ptr<Expression> > () = std::make_shared<LogicExpression>(yystack_[0].value.as < std::string > ());}
#line 1406 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 69:
#line 369 "parser.y"
                        {yylhs.value.as < ptr<Expression> > () = yystack_[0].value.as < ptr<MInvExpression> > ();}
#line 1412 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 70:
#line 372 "parser.y"
            {yylhs.value.as < std::string > () = "false";}
#line 1418 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 71:
#line 373 "parser.y"
             {yylhs.value.as < std::string > () = "true";}
#line 1424 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 72:
#line 376 "parser.y"
                 {yylhs.value.as < int > () = -yystack_[0].value.as < int > ();}
#line 1430 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;

  case 73:
#line 377 "parser.y"
               {yylhs.value.as < int > () = yystack_[0].value.as < int > ();}
#line 1436 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"
    break;


#line 1440 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -105;

  const signed char parser::yytable_ninf_ = -48;

  const short
  parser::yypact_[] =
  {
     -10,   -15,    21,  -105,  -105,     9,  -105,    17,     8,     6,
    -105,    24,   -17,    29,  -105,    32,    23,    -8,    40,    71,
    -105,  -105,    60,  -105,  -105,  -105,  -105,  -105,  -105,    37,
      59,  -105,  -105,  -105,    74,    42,    72,    66,    57,    75,
      84,  -105,  -105,  -105,  -105,    -7,   102,    76,    85,    54,
      58,   272,    93,    96,  -105,    86,    60,    97,   100,   272,
     272,  -105,  -105,  -105,     5,  -105,   457,    95,  -105,  -105,
    -105,   106,  -105,  -105,  -105,    92,    60,  -105,  -105,   313,
    -105,   272,   272,   143,  -105,    91,   108,   272,   272,   326,
     457,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   -25,  -105,   272,   184,  -105,  -105,    79,
      81,  -105,   340,   354,  -105,   272,   116,   368,   382,  -105,
     395,   470,   470,   144,   144,   457,   457,   457,   457,   457,
     457,   409,  -105,   118,   430,  -105,   225,    60,  -105,   111,
     112,   443,  -105,   266,   266,  -105,  -105,     3,  -105,  -105,
    -105,  -105,  -105,  -105,    98,  -105,  -105,   457,    -4,   266,
    -105,   272,  -105,   457
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     4,     0,     1,     3,     0,     0,
       5,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      25,     9,     0,    27,    26,    30,    12,    13,    14,     0,
      23,    24,    28,    11,     0,     0,     0,     0,     0,     0,
       0,    17,    29,    10,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     0,     0,     0,     0,
       0,    67,    71,    70,    65,    73,     0,    69,     8,    41,
      32,     0,    66,    68,     7,     0,    18,    72,    65,     0,
      69,     0,     0,     0,     6,     0,    28,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     7,    19,    22,
       0,    64,     0,     0,    33,     0,     0,     0,     0,    39,
       0,    55,    54,    56,    57,    53,    49,    50,    58,    51,
      52,     0,    60,     0,     0,    15,     0,     0,    21,     0,
       0,     0,    62,     0,     0,    48,    59,    42,    38,    16,
      20,    31,    37,    61,    34,    36,    45,    43,     0,     0,
      46,     0,    35,    44
  };

  const signed char
  parser::yypgoto_[] =
  {
    -105,   -29,   -45,  -105,  -105,  -104,   -50,  -105,    -1,  -105,
     101,  -105,  -105,  -105,  -105,     0,  -105,  -105,  -105,  -105,
    -105,  -105,   -22,    94,  -105,   109
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    66,    80,   158,     2,    68,    46,    26,    69,    28,
      17,    10,     7,     3,    70,   108,   109,    48,     4,    71,
      72,    73,    29,    30,    31,    32
  };

  const short
  parser::yytable_[] =
  {
      35,    67,    47,    14,    83,   160,   132,    50,   -47,    20,
      20,    51,   156,    21,     1,    15,    27,    22,   133,    23,
      23,     6,    79,    49,   106,    24,    24,    91,     5,     8,
      89,    90,    56,    11,   161,    25,    25,    27,    67,   154,
     155,     9,    60,    61,    62,    63,    78,    65,   -30,    12,
      13,    19,   112,   113,   110,   162,    16,   136,   117,   118,
      33,    67,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    20,    18,   134,    20,    43,    34,
      36,    37,    22,    39,    23,    40,   141,    23,    41,    42,
      24,    67,    45,    24,    75,    44,    74,    76,    67,    67,
      25,    81,    77,    25,    82,    87,    50,    84,    88,   105,
      51,   104,   107,   115,    67,   110,   116,   137,   157,    20,
      52,    53,    54,    55,   138,   142,   147,   151,   152,    23,
       0,    56,   163,   159,    38,    24,    57,   150,    58,    59,
       0,    60,    61,    62,    63,    64,    65,    50,     0,     0,
      85,    51,     0,     0,    96,    97,    98,    99,   100,   101,
      20,    52,    53,    54,   114,    86,   102,     0,     0,     0,
      23,     0,    56,     0,   103,     0,    24,    57,     0,    58,
      59,     0,    60,    61,    62,    63,    64,    65,    50,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    52,    53,    54,   135,     0,     0,     0,     0,
       0,    23,     0,    56,     0,     0,     0,    24,    57,     0,
      58,    59,     0,    60,    61,    62,    63,    64,    65,    50,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    52,    53,    54,   149,     0,     0,     0,
       0,     0,    23,     0,    56,     0,     0,     0,    24,    57,
       0,    58,    59,     0,    60,    61,    62,    63,    64,    65,
      50,     0,     0,     0,    51,     0,    50,     0,     0,     0,
      51,     0,     0,    20,    52,    53,    54,     0,     0,     0,
       0,     0,     0,    23,     0,    56,     0,     0,     0,    24,
      57,    56,    58,    59,     0,    60,    61,    62,    63,    64,
      65,    60,    61,    62,    63,    78,    65,    92,    93,    94,
      95,     0,   111,    96,    97,    98,    99,   100,   101,     0,
      92,    93,    94,    95,     0,   102,    96,    97,    98,    99,
     100,   101,   119,   103,    92,    93,    94,    95,   102,   139,
      96,    97,    98,    99,   100,   101,   103,     0,    92,    93,
      94,    95,   102,   140,    96,    97,    98,    99,   100,   101,
     103,     0,    92,    93,    94,    95,   102,   143,    96,    97,
      98,    99,   100,   101,   103,     0,    92,    93,    94,    95,
     102,   144,    96,    97,    98,    99,   100,   101,   103,    92,
      93,    94,    95,     0,   102,    96,    97,    98,    99,   100,
     101,     0,   103,    92,    93,    94,    95,   102,   145,    96,
      97,    98,    99,   100,   101,   103,     0,     0,     0,     0,
       0,   102,   146,     0,    92,    93,    94,    95,     0,   103,
      96,    97,    98,    99,   100,   101,   148,    92,    93,    94,
      95,     0,   102,    96,    97,    98,    99,   100,   101,     0,
     103,    92,    93,    94,    95,   102,   153,    96,    97,    98,
      99,   100,   101,   103,     0,     0,    94,    95,     0,   102,
      96,    97,    98,    99,   100,   101,     0,   103,     0,     0,
       0,     0,   102,     0,     0,     0,     0,     0,     0,     0,
     103
  };

  const short
  parser::yycheck_[] =
  {
      22,    46,     9,    20,    54,     9,    31,     4,     3,    17,
      17,     8,     9,    21,    24,    32,    17,    25,    43,    27,
      27,     0,    51,    45,    74,    33,    33,    22,    43,    20,
      59,    60,    29,    25,    38,    43,    43,    38,    83,   143,
     144,    24,    39,    40,    41,    42,    43,    44,    43,    43,
      26,    28,    81,    82,    76,   159,    27,   107,    87,    88,
      20,   106,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    17,    43,   105,    17,    21,     8,
      43,    22,    25,     9,    27,    43,   115,    27,    16,    23,
      33,   136,     8,    33,     9,    20,    20,    43,   143,   144,
      43,     8,    44,    43,     8,     8,     4,    21,     8,     3,
       8,    16,    20,    22,   159,   137,     8,    38,   147,    17,
      18,    19,    20,    21,    43,     9,     8,    16,    16,    27,
      -1,    29,   161,    35,    33,    33,    34,   137,    36,    37,
      -1,    39,    40,    41,    42,    43,    44,     4,    -1,    -1,
      56,     8,    -1,    -1,    10,    11,    12,    13,    14,    15,
      17,    18,    19,    20,    21,    56,    22,    -1,    -1,    -1,
      27,    -1,    29,    -1,    30,    -1,    33,    34,    -1,    36,
      37,    -1,    39,    40,    41,    42,    43,    44,     4,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,     4,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
       4,    -1,    -1,    -1,     8,    -1,     4,    -1,    -1,    -1,
       8,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    29,    36,    37,    -1,    39,    40,    41,    42,    43,
      44,    39,    40,    41,    42,    43,    44,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    -1,
       4,     5,     6,     7,    -1,    22,    10,    11,    12,    13,
      14,    15,    16,    30,     4,     5,     6,     7,    22,     9,
      10,    11,    12,    13,    14,    15,    30,    -1,     4,     5,
       6,     7,    22,     9,    10,    11,    12,    13,    14,    15,
      30,    -1,     4,     5,     6,     7,    22,     9,    10,    11,
      12,    13,    14,    15,    30,    -1,     4,     5,     6,     7,
      22,     9,    10,    11,    12,    13,    14,    15,    30,     4,
       5,     6,     7,    -1,    22,    10,    11,    12,    13,    14,
      15,    -1,    30,     4,     5,     6,     7,    22,    23,    10,
      11,    12,    13,    14,    15,    30,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,     4,     5,     6,     7,    -1,    30,
      10,    11,    12,    13,    14,    15,    16,     4,     5,     6,
       7,    -1,    22,    10,    11,    12,    13,    14,    15,    -1,
      30,     4,     5,     6,     7,    22,    23,    10,    11,    12,
      13,    14,    15,    30,    -1,    -1,     6,     7,    -1,    22,
      10,    11,    12,    13,    14,    15,    -1,    30,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30
  };

  const signed char
  parser::yystos_[] =
  {
       0,    24,    49,    58,    63,    43,     0,    57,    20,    24,
      56,    25,    43,    26,    20,    32,    27,    55,    43,    28,
      17,    21,    25,    27,    33,    43,    52,    53,    54,    67,
      68,    69,    70,    20,     8,    67,    43,    22,    55,     9,
      43,    16,    23,    21,    20,     8,    51,     9,    62,    67,
       4,     8,    18,    19,    20,    21,    29,    34,    36,    37,
      39,    40,    41,    42,    43,    44,    46,    47,    50,    53,
      59,    64,    65,    66,    20,     9,    43,    44,    43,    46,
      47,     8,     8,    51,    21,    68,    70,     8,     8,    46,
      46,    22,     4,     5,     6,     7,    10,    11,    12,    13,
      14,    15,    22,    30,    16,     3,    51,    20,    60,    61,
      67,     9,    46,    46,    21,    22,     8,    46,    46,    16,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    31,    43,    46,    21,    51,    38,    43,     9,
       9,    46,     9,     9,     9,    23,    23,     8,    16,    21,
      60,    16,    16,    23,    50,    50,     9,    46,    48,    35,
       9,    38,    50,    46
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    49,    58,    57,    57,    63,    51,    51,    56,
      56,    55,    55,    52,    52,    54,    54,    53,    61,    61,
      61,    60,    62,    67,    67,    68,    68,    68,    68,    69,
      70,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    59,    48,    48,    48,    47,    47,    64,    64,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      66,    66,    65,    65
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     2,    13,     0,     2,     5,
       7,     0,     2,     1,     1,     8,     9,     3,     0,     1,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     3,
       1,     5,     1,     3,     5,     7,     5,     5,     4,     3,
       2,     1,     0,     1,     3,     5,     6,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     5,     4,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"=\"", "\"-\"", "\"+\"",
  "\"*\"", "\"/\"", "\"(\"", "\")\"", "\"==\"", "\"&&\"", "\"||\"",
  "\"%\"", "\"<\"", "\">\"", "\";\"", "\"int\"", "\"assert\"",
  "\"System.out.println\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"",
  "\"class\"", "\"public\"", "\"static\"", "\"void\"", "\"main\"",
  "\"new\"", "\".\"", "\"length\"", "\"extends\"", "\"boolean\"", "\"if\"",
  "\"else\"", "\"while\"", "\"return\"", "\",\"", "\"!\"", "\"this\"",
  "\"true\"", "\"false\"", "\"identifier\"", "\"number\"", "$accept",
  "expr", "method_invocation", "list_expr", "unit", "statement",
  "statements", "declaration", "variable_declaration",
  "method_declaration", "declarations", "class_declaration",
  "classes_declarations", "program", "local_variable_declaration",
  "argument", "arguments", "formals", "main_class", "lvalue",
  "signed_number", "logic", "type", "simple_type", "array_type",
  "type_identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   239,   239,   242,   245,   246,   249,   254,   255,   258,
     261,   266,   267,   270,   271,   274,   278,   284,   287,   288,
     289,   292,   295,   299,   300,   303,   304,   305,   306,   309,
     312,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   327,   334,   335,   336,   339,   341,   345,   346,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     372,   373,   376,   377
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2004 "/home/anatoly/CLionProjects/MyCompiler/04-visitors/parser.cpp"

#line 378 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
