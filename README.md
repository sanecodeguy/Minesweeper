# Minesweeper | C++ with SFML

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-8CC03F?style=for-the-badge&logo=sfml&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)

A classic Minesweeper game built with C++ and SFML, featuring multiple difficulty levels, score tracking, and a sleek graphical interface.

![Minesweeper Demo](demo.gif) 
![Demo](https://github.com/user-attachments/assets/610db764-469f-45f5-943b-9c039c06becb)


## Features

- 🎮 Three difficulty levels: Easy, Intermediate, and Advanced
- ⏱️ Game timer with visual countdown
- 🏆 Score tracking and high score system
- 🎨 Customizable player name
- 💾 Save game functionality
- 💡 Hint system to help players

## Installation

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- CMake (version 3.15 or higher)
- SFML (version 2.5 or higher)

### Building from Source

```bash
# Clone the repository
git clone https://github.com/sanecodeguy/Minesweeper.git
cd Minesweeper

# Create build directory and compile
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .

# Run the game
./Minesweeper
```

## How to Play

1. **Select Difficulty**:
   - Easy: 9x9 grid with 10 mines
   - Intermediate: 16x16 grid with 40 mines
   - Advanced: 30x16 grid with 100 mines

2. **Controls**:
   - Left-click to reveal a tile
   - Right-click to place/remove a flag
   - Use the hint button (when available) to reveal a safe tile

3. **Objective**:
   - Reveal all tiles without hitting any mines
   - Flag all mines to win

## Project Structure

```
minesweeper/
├── CMakeLists.txt       # Build configuration
├── src/                 # Source files
│   ├── game.cpp         # Main game logic
│   ├── Menu.h           # Menu system
│   ├── canvas.h         # Game board rendering
│   ├── setmine.h        # Mine placement logic
│   └── savefile.h       # Save/load functionality
├── images/              # Game assets (textures)
├── time/                # Timer display assets
└── README.md            # This file
```

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License 

## Acknowledgments

- SFML development team for the excellent multimedia library
- Microsoft for the original Minesweeper concept
- All contributors and testers

---

Made with ❤️ by Raham & sanecodeguy
