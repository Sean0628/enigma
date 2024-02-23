#include "Rotor.h"

const string Rotor::ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const map<int, pair<string, char>> Rotor::CONFIG = {
    {1, {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q'}}, // Rotor I
    {2, {"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E'}}, // Rotor II
    {3, {"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V'}}, // Rotor III
    {4, {"ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J'}}, // Rotor IV
    {5, {"VZBRGITYUPSDNHLXAWMJQOFECK", 'Z'}}  // Rotor V
};

Rotor::Rotor(string wiring, char notch)
{
  this->left = ALPHABETS;
  this->right = wiring;
  this->notch = notch;
}

Rotor::~Rotor()
{
}

Rotor Rotor::create(int type)
{
  auto it = CONFIG.find(type);

  if (it == CONFIG.end())
  {
    throw invalid_argument("Invalid rotor type");
  } else {
    return Rotor(it->second.first, it->second.second);
  }
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

void Rotor::rotate(int times)
{
  for (int i = 0; i < times; i++)
  {
    char firstLeft = this->left[0];
    this->left.erase(0, 1);
    this->left += firstLeft;

    char firstRight = this->right[0];
    this->right.erase(0, 1);
    this->right += firstRight;
  }
}

void Rotor::rotate_to(char letter)
{
  size_t index = this->left.find(letter);
  this->rotate(index);
}
