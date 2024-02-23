#include <iostream>
#include "Rotor.cpp"

using namespace std;

int main() {
  {
    // Rotor I
    Rotor rotor = Rotor::create(1);

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

    // Rotor.rotate()
    rotor.rotate();
    if (rotor.get_left() == "BCDEFGHIJKLMNOPQRSTUVWXYZA") {
        cout << "Test rotate(): PASS" << endl;
    } else {
        cout << "Test rotate(): FAIL (Expected BCDEFGHIJKLMNOPQRSTUVWXYZA, got " << rotor.get_left() << ")" << endl;
    }

    if (rotor.get_right() == "KMFLGDQVZNTOWYHXUSPAIBRCJE") {
        cout << "Test rotate(): PASS" << endl;
    } else {
        cout << "Test rotate(): FAIL (Expected KMFLGDQVZNTOWYHXUSPAIBRCJE, got " << rotor.get_right() << ")" << endl;
    }

    // Rotor.rotate_to()
    rotor.rotate_to('G');
    if (rotor.get_left() == "GHIJKLMNOPQRSTUVWXYZABCDEF") {
        cout << "Test rotate_to('G'): PASS" << endl;
    } else {
        cout << "Test rotate_to('G'): FAIL (Expected GHIJKLMNOPQRSTUVWXYZABCDEF, got " << rotor.get_left() << ")" << endl;
    }

    if (rotor.get_right() == "DQVZNTOWYHXUSPAIBRCJEKMFLG") {
        cout << "Test rotate_to('G'): PASS" << endl;
    } else {
        cout << "Test rotate_to('G'): FAIL (Expected DQVZNTOWYHXUSPAIBRCJEKMFLG, got " << rotor.get_right() << ")" << endl;
    }
  }

  {
    // Rotor II
    Rotor rotor = Rotor::create(2);

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
    Rotor rotor = Rotor::create(3);

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
    Rotor rotor = Rotor::create(4);

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
    Rotor rotor = Rotor::create(5);

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
