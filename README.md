# Battleship
#### Devin Lin and Tyler Huang Pd. 5

# Proposal

#### Description
A two player battleship game ran on two computers. The first user will act as the host and store all of the data.

#### Usage
1. User will run the program with an executable
2. User will be given the options to start a new game or to join an existing one
3. If the user chooses to start a new game:
    - User must enter a password and name for the game room
    - They will wait for a second player to connect
4. If the user chooses to join a game:
    - User will enter the IP, port, game name, and password to connect to an existing game
    - They then will be able to play along with the first user in a game of battleship

#### Technical Design
- We will be using networking, command line arguments, reading and writing to files, structs, and pointers.
- Networking will be used to connect the two computers together so the game can be played.
- A text file will store the board and the ships.
- If a ship is taken out, the text file will be edited to reflect that change.
- Structs will be used to store a player’s info such as points and ships remaining.
- Command line arguments will be used to play this game, which will be used to determine valid moves.
- Devin will work on networking and creating the structs, while Tyler will handling coding the game, such as parsing args, checking if a move is valid, and reading and writing to files.

#### Timeline
- 1/8 -- have basic game and UI working on one computer
- 1/12 -- network functionality should be completed and a simple connection between two computers should be functioning
- 1/15 -- game and networking should be linked and completed. User should be able to play the game seamlessly. DEBUGGING TIME. 
