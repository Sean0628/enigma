#pragma once

#include <string>

using namespace std;

class Keyboard
{
public:
  static const string ALPHABETS;

  Keyboard();
  ~Keyboard();

  int forward(char letter);
  char backward(int signal);
};
