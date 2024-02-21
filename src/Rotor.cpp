#include "Rotor.h"

const string Rotor::ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

Rotor::Rotor(string wiring, char notch)
{
  this->left = ALPHABETS;
  this->right = wiring;
  this->notch = notch;
}

Rotor::~Rotor()
{
}

int Rotor::forward(int signal) const
{
  char letter = this->right[signal];
  size_t forwardSignal = this->left.find(letter);

  if (forwardSignal == string::npos)
  {
    return -1;
  } else {
    return static_cast<int>(forwardSignal);
  }
}

int Rotor::backward(int signal) const
{
  char letter = this->left[signal];
  size_t backwardSignal = this->right.find(letter);

  if (backwardSignal == string::npos)
  {
    return -1;
  } else {
    return static_cast<int>(backwardSignal);
  }
}
