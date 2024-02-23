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

void Enigma::set_keys(char key1, char key2, char key3)
{
  this->rotor1.rotate_to(key1);
  this->rotor2.rotate_to(key2);
  this->rotor3.rotate_to(key3);
}

void Enigma::set_rings(int ring1, int ring2, int ring3)
{
  this->rotor1.set_ring(ring1);
  this->rotor2.set_ring(ring2);
  this->rotor3.set_ring(ring3);
}

char Enigma::encipher(char letter)
{
  int signal = this->keyboard.forward(letter);
  if (signal == -1)
  {
    return letter;
  }

  this->rotate_rotors();

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

void Enigma::rotate_rotors()
{
  if (
      (this->rotor2.is_notch() && this->rotor3.is_notch()) ||
      this->rotor2.is_notch()
      )
  {
    this->rotor1.rotate();
    this->rotor2.rotate();
    this->rotor3.rotate();
  }
  else if (this->rotor3.is_notch())
  {
    this->rotor2.rotate();
    this->rotor3.rotate();
  }
  else
  {
    this->rotor3.rotate();
  }
}
