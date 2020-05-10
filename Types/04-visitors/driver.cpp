#include "driver.hh"
#include "parser.hh"

#include "visitors/Printer.h"
#include "visitors/Interpreter.h"
#include "visitors/SymbolTreeVisitor.h"
#include "visitors/TypesChecker.h"
#include "visitors/Interpreter_types.h"

Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {
}


int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    std::cout << "parser " << res << std::endl;
    scan_end();
    return res;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

void Traverse(ScopeLayer* lay) {
  std::cout << "begin" << std::endl;
  for (auto s : lay->symbols_) {
    std::cout << s.GetName() << std::endl;
  }
  for (auto i : lay->values_) {
    std::cout << i.second->ToInt() << " ";
  }
  for (auto it : lay-> children_) {
    Traverse(it);
  }
  std::cout << "end" << std::endl;
}


void Driver::Execute() {
  SymbolTreeVisitor stv;
  stv.Visit(program.get());
  auto root = stv.tree_.root_;

  TypesChecker check(root);
  check.Visit(program.get());
  Interpreter_types interp(root);
  interp.Visit(program.get());

  stv.tree_.Free(root);
}

void Driver::PrintTree(const std::string &filename) {
  Printer visitor(filename);
  visitor.Visit(program.get());
}

void Driver::scan_end()
{
    stream.close();
}

