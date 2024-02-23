#pragma once

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Plugboard
{
private:
  static const string ALPHABETS;
  string left, right;

public:
  Plugboard(vector<pair<char, char>> mapping);
  ~Plugboard();

  int forward(int signal) const;
  int backward(int signal) const;
};
