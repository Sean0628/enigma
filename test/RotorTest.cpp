#include <iostream>
#include "Rotor.cpp"

using namespace std;

int main() {
  {
    // Rotor I
    Rotor rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');

    int forwardResult1 = rotor.forward(0);
    if (forwardResult1 == 4) {
        cout << "Test forward(0): PASS" << endl;
    } else {
        cout << "Test forward(0): FAIL (Expected 4, got " << forwardResult1 << ")" << endl;
    }

    int backwardResult1 = rotor.backward(4);
    if (backwardResult1 == 0) {
        cout << "Test backward(4): PASS" << endl;
    } else {
        cout << "Test backward(4): FAIL (Expected 0, got " << backwardResult1 << ")" << endl;
    }
  }

  {
    // Rotor II
    Rotor rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E');

    int forwardResult2 = rotor.forward(0);
    if (forwardResult2 == 0) {
        cout << "Test forward(0): PASS" << endl;
    } else {
        cout << "Test forward(0): FAIL (Expected 0, got " << forwardResult2 << ")" << endl;
    }

    int backwardResult2 = rotor.backward(0);
    if (backwardResult2 == 0) {
        cout << "Test backward(0): PASS" << endl;
    } else {
        cout << "Test backward(0): FAIL (Expected 0, got " << backwardResult2 << ")" << endl;
    }
  }

  {
    // Rotor III
    Rotor rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V');

    int forwardResult3 = rotor.forward(0);
    if (forwardResult3 == 1) {
        cout << "Test forward(0): PASS" << endl;
    } else {
        cout << "Test forward(0): FAIL (Expected 1, got " << forwardResult3 << ")" << endl;
    }

    int backwardResult3 = rotor.backward(1);
    if (backwardResult3 == 0) {
        cout << "Test backward(1): PASS" << endl;
    } else {
        cout << "Test backward(1): FAIL (Expected 0, got " << backwardResult3 << ")" << endl;
    }
  }

  {
    // Rotor IV
    Rotor rotor("ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J');

    int forwardResult4 = rotor.forward(0);
    if (forwardResult4 == 4) {
        cout << "Test forward(0): PASS" << endl;
    } else {
        cout << "Test forward(0): FAIL (Expected 4, got " << forwardResult4 << ")" << endl;
    }

    int backwardResult4 = rotor.backward(4);
    if (backwardResult4 == 0) {
        cout << "Test backward(4): PASS" << endl;
    } else {
        cout << "Test backward(4): FAIL (Expected 0, got " << backwardResult4 << ")" << endl;
    }
  }

  {
    // Rotor V
    Rotor rotor("VZBRGITYUPSDNHLXAWMJQOFECK", 'Z');

    int forwardResult5 = rotor.forward(0);
    if (forwardResult5 == 21) {
        cout << "Test forward(0): PASS" << endl;
    } else {
        cout << "Test forward(0): FAIL (Expected 21, got " << forwardResult5 << ")" << endl;
    }

    int backwardResult5 = rotor.backward(21);
    if (backwardResult5 == 0) {
        cout << "Test backward(21): PASS" << endl;
    } else {
        cout << "Test backward(21): FAIL (Expected 0, got " << backwardResult5 << ")" << endl;
    }
  }

  return 0;

}
