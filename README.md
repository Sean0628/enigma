# enigma simulator
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/Sean0628/enigma/blob/main/LICENSE)

## Overview
This is another Enigma Machine Simulator, a modern recreation of the historic cipher machine implemented in C++. Inspired by the JavaScript-based simulator at [mckoss/enigma-simulator-js](https://github.com/mckoss/enigma-simulator-js), this app allows users to explore the encryption and decryption processes that defined an era of secret communications. For an introduction to the Enigma machine's fascinating history and mechanics, the [Wikipedia page](https://en.wikipedia.org/wiki/Enigma_machine) provides a wealth of information.

## Usage
This demonstrates encoding the message "HELLO WORLD" to "JBETS SKLVY" and then decoding it back to "HELLO WORLD". 
```sh
$ docker-compose run app bash

root@94d9d645dfef:/# cd /enigma
root@94d9d645dfef:/enigma/src# g++ src/main.cpp -o main

// Encode
root@94d9d645dfef:/enigma/src# ./main
Default configuration: Reflector B, Rotors 1, 2, 3. Would you like to change? (y/n): n
Enter plugboard mappings (e.g., ABCDEF for A->B, C->D, E->F), or press Enter to skip: ARDKOX
Enter rotor positions (e.g., ABC): DOG
Enter ring settings (e.g., ABC): ABC
Reflector: B
Rotors: 123
Rotor positions: DOG
Ring settings: ABC
Plugboard: AR DK OX
Enter message: HELLO WORLD
Enciphered message: JBETS SKLVY

// Decode
Default configuration: Reflector B, Rotors 1, 2, 3. Would you like to change? (y/n): n
Enter plugboard mappings (e.g., ABCDEF for A->B, C->D, E->F), or press Enter to skip: ARDKOX
Enter rotor positions (e.g., ABC): DOG
Enter ring settings (e.g., ABC): ABC
Reflector: B
Rotors: 123
Rotor positions: DOG
Ring settings: ABC
Plugboard: AR DK OX
Enter message: JBETS SKLVY
Enciphered message: HELLO WORLD
```

## Copyright
Copyright (c) 2024 Sho Ito. See [LICENSE](https://github.com/Sean0628/enigma/blob/main/LICENSE) for further details.

