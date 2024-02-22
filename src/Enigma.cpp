#include "Enigma.h"

Enigma::Enigma(
    Reflector reflector,
    Rotor rotor1,
    Rotor rotor2,
    Rotor rotor3,
    Plugboard plugboard,
    Keyboard keyboard
    )
  :
    reflector(reflector),
    rotor1(rotor1),
    rotor2(rotor2),
    rotor3(rotor3),
    plugboard(plugboard),
    keyboard(keyboard)
{
  this->reflector = reflector;
  this->rotor1 = rotor1;
  this->rotor2 = rotor2;
  this->rotor3 = rotor3;
  this->plugboard = plugboard;
  this->keyboard = keyboard;
}

Enigma::~Enigma()
{
}

char Enigma::encipher(char letter)
{
  int signal = this->keyboard.forward(letter);
  if (signal == -1)
  {
    return letter;
  }

  signal = this->plugboard.forward(signal);
  signal = this->rotor3.forward(signal);
  signal = this->rotor2.forward(signal);
  signal = this->rotor1.forward(signal);
  signal = this->reflector.reflect(signal);
  signal = this->rotor1.backward(signal);
  signal = this->rotor2.backward(signal);
  signal = this->rotor3.backward(signal);
  signal = this->plugboard.backward(signal);
  letter = this->keyboard.backward(signal);

  return letter;
}