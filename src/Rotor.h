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
  void roate_forward();
  void roate_backward();

public:
  static Rotor create(int type);

  Rotor(string wiring, char notch);
  ~Rotor();

  int forward(int signal) const;
  int backward(int signal) const;
  void rotate(int times = 1, bool reverse = false);
  void rotate_to(char letter);
  void set_ring(int position);
  bool is_notch() const { return this->left[0] == this->notch; }
  string get_left() const { return this->left; }
  string get_right() const { return this->right; }
};
