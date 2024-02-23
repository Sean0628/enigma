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

void Rotor::rotate(int times, bool reverse)
{
  for (int i = 0; i < times; i++)
  {
    if (reverse)
    {
      this->roate_backward();
    } else {
      this->roate_forward();
    }
  }
}

void Rotor::rotate_to(char letter)
{
  size_t index = this->left.find(letter);
  this->rotate(index);
}

void Rotor::set_ring(int position)
{
  this->rotate(position, true);

  int notchIndex = ALPHABETS.find(this->notch);
  this->notch = ALPHABETS[(notchIndex - position) % ALPHABETS.size()];
}

void Rotor::roate_forward()
{
  char firstLeft = this->left[0];
  this->left.erase(0, 1);
  this->left += firstLeft;

  char firstRight = this->right[0];
  this->right.erase(0, 1);
  this->right += firstRight;
}

void Rotor::roate_backward()
{
  char lastLeft = this->left[this->left.size()-1];
  this->left.erase(this->left.size()-1, 1);
  this->left = lastLeft + this->left;

  char lastRight = this->right[this->right.size()-1];
  this->right.erase(this->right.size()-1, 1);
  this->right = lastRight + this->right;
}
