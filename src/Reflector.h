#pragma once

#include <string>

using namespace std;

class Reflector
{
private:
  static const string ALPHABETS;

  string left, right;

public:
  Reflector(string wiring);
  ~Reflector();

  int reflect(int signal) const;
};
