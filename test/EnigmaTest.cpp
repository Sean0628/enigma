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
    // Enigma
    Reflector reflector("EJMZALYXVBWFCRQUONTSPIKHGD");
    Rotor rotor1("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');
    Rotor rotor2("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E');
    Rotor rotor3("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V');

    vector<pair<char, char>> mapping = {
      {'A', 'R'},
      {'G', 'K'},
      {'O', 'X'},
    };
    Plugboard plugboard(mapping);
    Keyboard keyboard;

    Enigma enigma(reflector, rotor1, rotor2, rotor3, plugboard, keyboard);

    char letter = 'A';
    if (enigma.encipher(letter) == 'X') {
      cout << "Test encipher('A'): PASS" << endl;
    } else {
      cout << "Test encipher('A'): FAIL (Expected X, got " << enigma.encipher(letter) << ")" << endl;
    }
  }

  return 0;

}
