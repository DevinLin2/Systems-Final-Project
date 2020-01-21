# Battleship
#### Devin Lin, Tyler Huang, and Jason Zheng Pd. 5

# Proposal

#### Description
A two player battleship game ran on one computer.

#### Usage
1. User will run the program with an executable
2. Player 1 will start with placing all his ships by entering coordinates in the form of [row column] (without the brackets).
3. Player 2 will then be able to guess the locations of the ships in the form of [row column] (without the brackets).
4. Once player 2 finishes, player 2 will be able to place ships and player 1 will be able to guess.
5. At the end, a winner is shown.

#### Technical Design
- We will be parsing command line arguments, using pointers, and dynamically allocating memory.
- Command line arguments will be used to play this game, which will be used to determine valid moves.
- Devin and Jason will work on networking, while Tyler will handling coding the game, such as parsing args, checking if a move is valid.

#### Timeline
- 1/8 -- have basic game and UI working on one computer
- 1/12 -- network functionality should be completed and a simple connection between two computers should be functioning
- 1/15 -- game and networking should be linked and completed. User should be able to play the game seamlessly. DEBUGGING TIME.

#### Bugs
- Coordinates must be in the form [row column] with integer inputs otherwise will result in an error
- If no coordinate is supplied, an error will be thrown
- If there is no space in the argument, an error will be thrown
