#pragma once

#include <string>

using namespace std;

class Reflector
{
private:
  string left, right;

public:
  static const string ALPHABETS;

  Reflector(string wiring);
  ~Reflector();

  int reflect(int signal) const;
};
