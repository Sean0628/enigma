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
  void rotate(int times = 1);
  void rotate_to(char letter);
  bool is_notch() const { return this->left[0] == this->notch; }
  string get_left() const { return this->left; }
  string get_right() const { return this->right; }
};
