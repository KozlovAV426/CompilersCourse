#pragma once

#include <map>
#include <string>
#include <fstream>
#include "scanner.h"
#include "parser.hh"
#include <memory>



class Driver {
 public:
    Driver();
    int result;
    int parse(const std::string& f);

    void Execute();
    void PrintTree(const std::string& filename);
    std::string file;
    bool trace_parsing;

    void scan_begin();
    void scan_end();

    bool trace_scanning;
    yy::location location;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;
    std::shared_ptr<Program> program;
    //Program* program;
 private:
    std::ifstream stream;

};
