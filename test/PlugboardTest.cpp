#include <iostream>
#include <vector>
#include "Plugboard.cpp"

using namespace std;

int main() {
  vector<pair<char, char>> mapping = {
    {'A', 'B'},
    {'E', 'H'},
  };

  Plugboard plugboard(mapping);

  // {'A', 'B'} -> {'B', 'A'}
  int forwardResult1 = plugboard.forward(1);
  if (forwardResult1 == 0) {
      cout << "Test forward(1): PASS" << endl;
  } else {
      cout << "Test forward(1): FAIL (Expected 0, got " << forwardResult1 << ")" << endl;
  }

  int backwardResult1 = plugboard.backward(0);
  if (backwardResult1 == 1) {
      cout << "Test backward(0): PASS" << endl;
  } else {
      cout << "Test backward(0): FAIL (Expected 1, got " << backwardResult1 << ")" << endl;
  }

  // {'E', 'H'} -> {'H', 'E'}
  int forwardResult2 = plugboard.forward(4);
  if (forwardResult2 == 7) {
      cout << "Test forward(4): PASS" << endl;
  } else {
      cout << "Test forward(4): FAIL (Expected 7, got " << forwardResult2 << ")" << endl;
  }

  int backwardResult2 = plugboard.backward(7);
  if (backwardResult2 == 4) {
      cout << "Test backward(4): PASS" << endl;
  } else {
      cout << "Test backward(4): FAIL (Expected 4, got " << backwardResult2 << ")" << endl;
  }

  // {'C', 'C'} -> {'C', 'C'}
  int forwardResult3 = plugboard.forward(2);
  if (forwardResult3 == 2) {
      cout << "Test forward(2): PASS" << endl;
  } else {
      cout << "Test forward(2): FAIL (Expected 2, got " << forwardResult3 << ")" << endl;
  }

  int backwardResult3 = plugboard.backward(2);
  if (backwardResult3 == 2) {
      cout << "Test backward(2): PASS" << endl;
  } else {
      cout << "Test backward(2): FAIL (Expected 2, got " << backwardResult3 << ")" << endl;
  }

  // validate maximum allowed pairs
  // 11 pairs
  try {
    vector<pair<char, char>> mapping = {
      {'A', 'B'},
      {'C', 'D'},
      {'E', 'F'},
      {'G', 'H'},
      {'I', 'J'},
      {'K', 'L'},
      {'M', 'N'},
      {'O', 'P'},
      {'Q', 'R'},
      {'S', 'T'},
      {'U', 'V'},
    };

    Plugboard plugboard(mapping);
  } catch (const std::invalid_argument& e) {
    cout << "Test maximum allowed pairs: PASS" << endl;
  }

  // 10 pairs
  try {
    vector<pair<char, char>> mapping = {
      {'A', 'B'},
      {'C', 'D'},
      {'E', 'F'},
      {'G', 'H'},
      {'I', 'J'},
      {'K', 'L'},
      {'M', 'N'},
      {'O', 'P'},
      {'Q', 'R'},
      {'S', 'T'},
    };

    Plugboard plugboard(mapping);
    cout << "Test maximum allowed pairs: PASS" << endl;
  } catch (const std::invalid_argument& e) {
    cout << "Test maximum allowed pairs: FAIL" << endl;
  }

  return 0;
}
