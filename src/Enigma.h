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

    char encipher(char message);
};
