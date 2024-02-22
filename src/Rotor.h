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
  void rotate();
  void rotate_to(char letter);
  string get_left() const { return this->left; }
  string get_right() const { return this->right; }
};
