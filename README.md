# so_long - 2D Game with MiniLibX

![42 school](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-passing-success?style=flat-square)

## 📖 About

**so_long** is a small 2D game project that introduces basic game development concepts using the MiniLibX graphics library. The player controls a cow that must collect all flowers before reaching the barn. The project focuses on window management, event handling, texture rendering, and basic game logic implementation.

Through this project, I gained experience with graphics programming, event-driven programming, memory management, and map parsing/validation.

## 🎯 Project Goals

- Create a functional 2D game with graphical interface
- Implement event handling (keyboard input, window closing)
- Parse and validate game maps from `.ber` files
- Render textures and sprites using MiniLibX
- Implement collision detection and game logic
- Ensure proper memory management with no leaks

## 🎮 Game Concept

### Gameplay

You're a cow on a farm trying to collect all the flowers before entering to the barn! Navigate through the map, avoid the mountains (walls), collect every flower, and find your way to the barn's exit.

### Objective

- Collect all flowers (`C`) on the map
- Reach the barn exit (`E`) after collecting all flowers
- Complete the level in as few moves as possible

### Controls

- **W** or **↑** - Move up
- **A** or **←** - Move left
- **S** or **↓** - Move down
- **D** or **→** - Move right
- **ESC** - Exit game

## 🗺️ Map Format

Maps are stored in `.ber` files with the following specifications:

### Map Components

- `1` - Wall (Mountains) - Impassable terrain
- `0` - Empty space (Background) - Walkable terrain
- `C` - Collectible (Flower) - Must collect all
- `E` - Exit (Barn) - Goal location
- `P` - Player starting position (Cow) - Only one allowed

### Map Rules

1. **Rectangular**: Map must be rectangular (all rows same length)
2. **Surrounded by walls**: Map must be completely enclosed by `1`
3. **Valid path**: Must have a valid path from player to all collectibles and exit
4. **One player**: Exactly one player starting position (`P`)
5. **One exit**: Exactly one exit (`E`)
6. **At least one collectible**: At least one flower (`C`) to collect
7. **Valid characters**: Only `0`, `1`, `C`, `E`, `P` allowed

### Example Map

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

This map has:
- Walls forming the border and obstacles
- One player position (`P`)
- One exit (`E`)
- One collectible (`C`)
- Empty spaces to navigate (`0`)

## 🎨 Graphics

The game uses custom XPM textures located in the `Textures/` directory:

- **Background.xpm** - Grass tile background
- **Cow.xpm** - Player sprite
- **Mountains.xpm** - Wall/obstacle sprite
- **Flower.xpm** - Collectible sprite
- **Barn.xpm** - Exit sprite

Each tile is **128x128 pixels** (`TILE_SIZE` constant).

## 🛠️ Compilation

### Requirements

- **MiniLibX** - Graphics library (included in `minilibx-linux/`)
- **X11 libraries** - Required for MiniLibX on Linux
- **gcc** - C compiler
- **make** - Build automation tool

### Building the Program

To compile the program, simply run:

```bash
make
```

This creates the `so_long` executable.

### Available Commands

- `make` - Compile the program
- `make clean` - Remove object files
- `make fclean` - Remove object files and the executable
- `make re` - Recompile everything from scratch

## 🚀 Usage

### Basic Usage

```bash
./so_long [map_file.ber]
```

### Examples

```bash
# Run with a specific map
./so_long Maps/map1.ber

# Try different maps
./so_long Maps/map2.ber
./so_long Maps/map3.ber
```

### Game Display

- The game window opens automatically
- Move counter displays at the top-left corner
- Each movement increments the counter (displayed in terminal and window)
- Window size adjusts based on map dimensions

### Error Handling

The program outputs descriptive error messages for:

- **Invalid arguments**: Wrong number of command-line arguments
- **Invalid file extension**: Map file must end with `.ber`
- **Invalid map structure**: Map not rectangular or not enclosed by walls
- **Invalid characters**: Unknown characters in the map
- **Missing elements**: No player, exit, or collectibles
- **Duplicate elements**: Multiple players or exits
- **No valid path**: Impossible to reach all collectibles and exit
- **Texture loading failures**: Missing or corrupted texture files

## 📊 Implementation Structure

The project is organized with a modular approach:

### Core Files

- **so_long.c** - Main program, initialization, and event loop
- **so_long.h** - Header file with structure definitions and function prototypes

### Validation & Parsing

- **so_long_check.c** - Map validation (path finding, element counting)
- **so_long_check_utils.c** - Helper functions for map validation

### Game Logic & Utilities

- **so_long_utils.c** - Game logic, movement, collision detection
- **so_long_utils_utils.c** - Additional utility functions
- **so_long_utils_x3.c** - Extended utility functions

### Helper Libraries

- **so_long_libft.c** - Custom C library functions
- **so_long_libft_utils.c** - Additional libft utilities
- **get_next_line/** - File reading utility for map parsing
- **ft_printf/** - Custom printf implementation for output

### Data Structure

```c
typedef struct s_data
{
    void    *mlx;                    // MiniLibX connection
    void    *window;                 // Game window

    // Textures
    void    *background;             // Background tile
    void    *mountain;               // Wall sprite
    void    *flower;                 // Collectible sprite
    void    *barn;                   // Exit sprite
    void    *player;                 // Player sprite

    // Dimensions
    int     number_of_tiles_x;       // Map width in tiles
    int     number_of_tiles_y;       // Map height in tiles

    // Player state
    int     player_x;                // Player X position
    int     player_y;                // Player Y position

    // Game state
    char    **objects_position;      // 2D map array
    int     number_of_movements;     // Move counter
    int     flowers_exist;           // Remaining collectibles

    char    *file_name;              // Map file name
} t_data;
```

## ⚙️ Technical Details

- **Language**: C
- **Compiler**: gcc
- **Flags**: `-Wall -Wextra -Werror`
- **Graphics Library**: MiniLibX (X11)
- **Norm**: 42 Norminette
- **Data Structure**: 2D array for map representation
- **Dependencies**: MiniLibX, X11, Xext, ft_printf, get_next_line

## 🧪 Algorithm Features

### Flood Fill Algorithm

The `fill_v()` function implements a recursive flood fill to validate path accessibility:

- Marks visited positions as `'V'`
- Recursively explores all reachable positions
- Ensures player can reach all collectibles and the exit

### Movement System

- Tracks player position in tile coordinates
- Checks collisions before allowing movement
- Updates collectible count when flowers are picked up
- Only allows exit when all flowers are collected
- Displays move count in real-time

## 🎮 Testing

### Test Maps

The project includes various test maps in the `Maps/` directory:

```bash
# Valid maps
./so_long Maps/map1.ber   # Basic valid map
./so_long Maps/map2.ber   # Different layout
./so_long Maps/map3.ber   # More complex

# Test edge cases
./so_long Maps/map10.ber  # Large map
./so_long Maps/map11.ber  # Narrow corridors
```

### Creating Custom Maps

Create your own `.ber` map files following these rules:

1. Use only `0`, `1`, `C`, `E`, `P` characters
2. Surround the map with `1` (walls)
3. Include exactly one `P` (player)
4. Include exactly one `E` (exit)
5. Include at least one `C` (collectible)
6. Ensure all rows have the same length
7. Make sure there's a valid path to all elements

Example:
```
11111
1P0C1
1E001
11111
```

## 📝 Notes

- All functions follow the 42 Norminette coding standards
- Memory is properly managed with no leaks
- The program handles window closing gracefully (X button and ESC key)
- Textures are loaded dynamically and validated
- Move counter is displayed both in the window and terminal
- The game prevents invalid moves (walking through walls)
- Exit only works after collecting all flowers

## 🐛 Known Limitations

- Window size is fixed based on map dimensions (no scaling)
- No animations for player movement
- Single texture per entity type
- No sound effects or music

## 👤 Author

**opopov**
