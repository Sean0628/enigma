#include <iostream>
#include "Keyboard.cpp"

using namespace std;

int main() {
  Keyboard keyboard;

  int forwardResult = keyboard.forward('A');
  if (forwardResult == 0) {
      cout << "Test forward('A'): PASS" << endl;
  } else {
      cout << "Test forward('A'): FAIL (Expected 0, got " << forwardResult << ")" << endl;
  }

  char backwardResult = keyboard.backward(0);
  if (backwardResult == 'A') {
      cout << "Test backward(0): PASS" << endl;
  } else {
      cout << "Test backward(0): FAIL (Expected 'A', got " << backwardResult << ")" << endl;
  }

  return 0;
}
