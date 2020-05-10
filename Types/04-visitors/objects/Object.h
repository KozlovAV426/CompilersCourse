#pragma once

#include <string>
#include <vector>

class Field {
public:
  Field() = default;
  Field(std::string type, std::string id) : type(type), id(id) {}
  std::string id;
  std::string type;
};


class Method {
public:
  Method() = default;
  Method(std::string t, std::string id,
         std::vector<std::pair<std::string, std::string>> a) : name(id), type(t), args(a) {}
  std::string name;
  std::string type;
  std::vector<std::pair<std::string, std::string>> args;
};


class Class {
public:
  std::vector<Field> fields;
  std::vector<Method> methods;
};



class Object {
 public:
    virtual int ToInt();
    virtual bool ToBoolean();
    virtual Class ToClass();
    virtual Method ToMethod();
    virtual std::pair<std::string, bool> GetType();

    virtual ~Object() = default;
};