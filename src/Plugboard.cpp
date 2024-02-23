#include "Plugboard.h"

const string Plugboard::ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

Plugboard::Plugboard(vector<pair<char, char>> mapping)
{
  if (mapping.size() > 10) {
      throw invalid_argument("Mapping exceeds the maximum allowed pairs of 10");
  }

  this->left = ALPHABETS;
  this->right = ALPHABETS;

  for (const auto& pair : mapping)
  {
    size_t leftIndex = this->left.find(pair.first);
    size_t rightIndex = this->right.find(pair.second);

    if (leftIndex != string::npos && rightIndex != string::npos)
    {
      swap(this->left[leftIndex], this->left[rightIndex]);
    }
  }
}

Plugboard::~Plugboard()
{
}

int Plugboard::forward(int signal) const
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

int Plugboard::backward(int signal) const
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
