#pragma once

#include <string>

using namespace std;

class Rotor
{
private:
  string left, right;
  char notch;

public:
  static const string ALPHABETS;

  Rotor(string wiring, char notch);
  ~Rotor();

  int forward(int signal) const;
  int backward(int signal) const;
};
