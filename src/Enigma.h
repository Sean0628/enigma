#pragma once

#include <string>
#include "Reflector.h"
#include "Rotor.h"
#include "Plugboard.h"
#include "Keyboard.h"

using namespace std;

class Enigma
{
  private:
    Reflector reflector;
    Rotor rotor1, rotor2, rotor3;
    Plugboard plugboard;
    Keyboard keyboard;

    void rotate_rotors();

  public:
    Enigma(
        Reflector reflector,
        Rotor rotor1,
        Rotor rotor2,
        Rotor rotor3,
        Plugboard plugboard,
        Keyboard keyboard
        );
    ~Enigma();

    void set_keys(char key1, char key2, char key3);
    char encipher(char message);
    Rotor get_rotor1() const { return this->rotor1; }
    Rotor get_rotor2() const { return this->rotor2; }
    Rotor get_rotor3() const { return this->rotor3; }
};
