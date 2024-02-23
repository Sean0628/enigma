#pragma once

#include <string>
#include <map>
#include <stdexcept>

using namespace std;

class Reflector
{
private:
  static const string ALPHABETS;
  static const map<char, string> CONFIG;

  string left, right;

public:
  static Reflector create(char type);

  Reflector(string wiring);
  ~Reflector();

  int reflect(int signal) const;
};
