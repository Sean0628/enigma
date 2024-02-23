#pragma once

#include <string>
#include <map>
#include <stdexcept>

using namespace std;

class Rotor
{
private:
  static const string ALPHABETS;
  static const map<int, pair<string, char>> CONFIG;

  string left, right;
  char notch;

public:
  static Rotor create(int type);

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
