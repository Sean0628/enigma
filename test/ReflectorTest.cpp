#include <iostream>
#include "Reflector.cpp"

using namespace std;

int main() {
  {
    // Reflector A
    Reflector reflector("EJMZALYXVBWFCRQUONTSPIKHGD");

    int reflectResult1 = reflector.reflect(0);
    if (reflectResult1 == 4) {
        cout << "Test reflect(0): PASS" << endl;
    } else {
        cout << "Test reflect(0): FAIL (Expected 4, got " << reflectResult1 << ")" << endl;
    }
  }

  {
    // Reflector B
    Reflector reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    int reflectResult2 = reflector.reflect(0);
    if (reflectResult2 == 24) {
        cout << "Test reflect(0): PASS" << endl;
    } else {
        cout << "Test reflect(0): FAIL (Expected 24, got " << reflectResult2 << ")" << endl;
    }
  }

  {
    // Reflector C
    Reflector reflector("FVPJIAOYEDRZXWGCTKUQSBNMHL");

    int reflectResult3 = reflector.reflect(0);
    if (reflectResult3 == 5) {
        cout << "Test reflect(0): PASS" << endl;
    } else {
        cout << "Test reflect(0): FAIL (Expected 5, got " << reflectResult3 << ")" << endl;
    }
  }

  return 0;
}
