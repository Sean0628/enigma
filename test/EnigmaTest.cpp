#include <iostream>
#include <vector>

#include "Enigma.cpp"
#include "Reflector.cpp"
#include "Rotor.cpp"
#include "Plugboard.cpp"
#include "Keyboard.cpp"

using namespace std;

int main() {
  {
    // Enigma::set_keys()
    Reflector reflector = Reflector::create('A');
    Rotor rotor1 = Rotor::create(1);
    Rotor rotor2 = Rotor::create(2);
    Rotor rotor3 = Rotor::create(3);

    vector<pair<char, char>> mapping = {
      {'A', 'R'},
      {'G', 'K'},
      {'O', 'X'},
    };
    Plugboard plugboard(mapping);
    Keyboard keyboard;

    Enigma enigma(reflector, rotor1, rotor2, rotor3, plugboard, keyboard);

    enigma.set_keys('D', 'O', 'G');

    if (
        enigma.get_rotor1().get_left()[0] == 'D' &&
        enigma.get_rotor2().get_left()[0] == 'O' &&
        enigma.get_rotor3().get_left()[0] == 'G'
        ) {
      cout << "Test set_keys('D', 'O', 'G'): PASS" << endl;
    } else {
      cout << "Test set_keys('D', 'O', 'G'): FAIL (Expected D, O, G, got " << enigma.get_rotor1().get_left()[0] << ", " << enigma.get_rotor2().get_left()[0] << ", " << enigma.get_rotor3().get_left()[0] << ")" << endl;
    }
  }

  {
    // Enigma::encipher()
    Reflector reflector = Reflector::create('A');
    Rotor rotor1 = Rotor::create(1);
    Rotor rotor2 = Rotor::create(2);
    Rotor rotor3 = Rotor::create(3);

    vector<pair<char, char>> mapping = {
      {'A', 'R'},
      {'G', 'K'},
      {'O', 'X'},
    };
    Plugboard plugboard(mapping);
    Keyboard keyboard;

    Enigma enigma(reflector, rotor1, rotor2, rotor3, plugboard, keyboard);

    char letter = 'A';
    char encipheredResult = enigma.encipher(letter);
    if (encipheredResult == 'N') {
      cout << "Test encipher('A'): PASS" << endl;
    } else {
      cout << "Test encipher('A'): FAIL (Expected N, got " << encipheredResult << ")" << endl;
    }
  }

  {
    // Enigma::encipher() w/ set_keys(), set_rings()
    Reflector reflector = Reflector::create('B');
    Rotor rotor1 = Rotor::create(1);
    Rotor rotor2 = Rotor::create(2);
    Rotor rotor3 = Rotor::create(3);

    vector<pair<char, char>> mapping = {
      {'A', 'R'},
      {'G', 'K'},
      {'O', 'X'},
    };
    Plugboard plugboard(mapping);
    Keyboard keyboard;

    Enigma enigma(reflector, rotor1, rotor2, rotor3, plugboard, keyboard);

    enigma.set_keys('D', 'O', 'G');
    enigma.set_rings(1, 2, 3);

    char letter = 'A';
    char encipheredResult = enigma.encipher(letter);
    if (encipheredResult == 'W') {
      cout << "Test encipher('A'): PASS" << endl;
    } else {
      cout << "Test encipher('A'): FAIL (Expected W, got " << encipheredResult << ")" << endl;
    }
  }

  return 0;
}
