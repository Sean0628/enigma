#include "Keyboard.h"

const string Keyboard::ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

int Keyboard::forward(char letter)
{
  size_t signal = ALPHABETS.find(letter);

  if (signal == string::npos)
  {
    return -1;
  } else {
    return static_cast<int>(signal);
  }
}

char Keyboard::backward(int signal)
{
  if (signal < 0 || signal >= ALPHABETS.size())
  {
    return '\0';
  } else {
    return ALPHABETS[signal];
  }
}
