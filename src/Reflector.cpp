#include "Reflector.h"

const string Reflector::ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const map<char, string> Reflector::CONFIG = {
  {'A', "EJMZALYXVBWFCRQUONTSPIKHGD"}, // A
  {'B', "YRUHQSLDPXNGOKMIEBFZCWVJAT"}, // B
  {'C', "FVPJIAOYEDRZXWGCTKUQSBNMHL"}  // C
};

Reflector::Reflector(string wiring)
{
  this->left = ALPHABETS;
  this->right = wiring;
}

Reflector::~Reflector()
{
}

Reflector Reflector::create(char type)
{
  string wiring = Reflector::CONFIG.at(type);

  if (wiring.empty())
  {
    throw invalid_argument("Invalid reflector type");
  } else {
    return Reflector(wiring);
  }
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
