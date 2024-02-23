#include <iostream>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <limits>

#include "Enigma.cpp"
#include "Reflector.cpp"
#include "Rotor.cpp"
#include "Plugboard.cpp"
#include "Keyboard.cpp"

using namespace std;

int main() {
  char reflectorType = 'B';
  string rotorSettings = "123";
  vector<pair<char, char>> plugboardMappings = {};

  cout << "Default configuration: Reflector B, Rotors 1, 2, 3. Would you like to change? (y/n): ";
  char changeConfig;
  cin >> changeConfig;

  if (tolower(changeConfig) == 'y') {
    // Reflector type
    cout << "Enter reflector type (A/B/C): ";
    cin >> reflectorType;

    if (reflectorType != 'A' && reflectorType != 'B' && reflectorType != 'C') {
        throw invalid_argument("Invalid reflector type");
    }

    // Rotor settings
    cout << "Enter rotor settings 1-5 (e.g., 123): ";
    cin >> rotorSettings;

    if (rotorSettings.length() != 3) {
        throw invalid_argument("Invalid rotor settings");
    }
  }

  // Plugboard mappings
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter plugboard mappings (e.g., ABCDEF for A->B, C->D, E->F), or press Enter to skip: ";
  string plugboardInput;
  getline(cin, plugboardInput); // Use getline to allow empty input

  for (size_t i = 0; i < plugboardInput.length(); i += 2) {
      char first = plugboardInput[i];
      char second = plugboardInput[i + 1];
      plugboardMappings.push_back(make_pair(toupper(first), toupper(second)));
  }

  if (plugboardMappings.size() > 10) {
      throw invalid_argument("Maximum allowed plugboard pairs is 10");
  }

  for (auto mapping : plugboardMappings) {
      if (!isalpha(mapping.first) || !isalpha(mapping.second)) {
          throw invalid_argument("Invalid plugboard mapping");
      }
  }

  // Position of rotors
  cout << "Enter rotor positions (e.g., ABC): ";
  string rotorPositions;
  cin >> rotorPositions;

  if (rotorPositions.length() != 3) {
      throw invalid_argument("Invalid rotor positions");
  }

  // Ring settings
  cout << "Enter ring settings 1-26 (e.g., 123): ";
  string ringSettings;
  cin >> ringSettings;

  if (ringSettings.length() != 3) {
      throw invalid_argument("Invalid ring settings");
  }

  // Print the configuration
  cout << "Reflector: " << reflectorType << endl;
  cout << "Rotors: " << rotorSettings << endl;
  cout << "Rotor positions: " << rotorPositions << endl;
  cout << "Ring settings: " << ringSettings << endl;
  cout << "Plugboard: ";
  for (auto mapping : plugboardMappings) {
      cout << mapping.first << mapping.second << " ";
  }
  cout << endl;

  Reflector reflector = Reflector::create(reflectorType);
  Rotor rotor1 = Rotor::create(rotorSettings[0] - '0');
  Rotor rotor2 = Rotor::create(rotorSettings[1] - '0');
  Rotor rotor3 = Rotor::create(rotorSettings[2] - '0');
  Plugboard plugboard(plugboardMappings);
  Keyboard keyboard;

  Enigma enigma(reflector, rotor1, rotor2, rotor3, plugboard, keyboard);

  enigma.set_keys(
      toupper(rotorPositions[0]),
      toupper(rotorPositions[1]),
      toupper(rotorPositions[2])
      );

  enigma.set_rings(
      ringSettings[0] - '0',
      ringSettings[1] - '0',
      ringSettings[2] - '0'
      );

  string message;
  cout << "Enter message: ";

  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
  getline(cin, message);

  cout << "Enciphered message: ";
  cout << enigma.encipher(message) << endl;

  return 0;
}
