#pragma once

#include <string>

using namespace std;

class Keyboard
{
private:
  static const string ALPHABETS;

public:
  Keyboard();
  ~Keyboard();

  int forward(char letter);
  char backward(int signal);
};
