#include "Reflector.h"

const string Reflector::ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

Reflector::Reflector(string wiring)
{
  this->left = ALPHABETS;
  this->right = wiring;
}

Reflector::~Reflector()
{
}

int Reflector::reflect(int signal) const
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
