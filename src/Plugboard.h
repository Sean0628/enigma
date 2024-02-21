#pragma once

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Plugboard
{
private:
  string left, right;

public:
  static const string ALPHABETS;

  Plugboard(vector<pair<char, char>> mapping);
  ~Plugboard();

  int forward(int signal) const;
  int backward(int signal) const;
};
