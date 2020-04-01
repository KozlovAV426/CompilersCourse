#include "driver.hh"
#include "parser.hh"

#include "visitors/Printer.h"

Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {
    variables["one"] = 1;
    variables["two"] = 2;
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

/*int Driver::Evaluate() {
  Printer interpreter;
    return interpreter.GetResult(program);
}*/

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

void Driver::PrintTree(const std::string &filename) {
  Printer visitor(filename);
  visitor.Visit(program.get());
}

void Driver::scan_end()
{
    stream.close();
}

