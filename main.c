#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * row,col = calloc(5, 5);
int board[10][10], player1Hit[10][10], player2Hit[10][10], mapSize = 10, numSubmarines = 10, numHits = 10;

void clearScreen() { //clears screen
  system("@cls||clear");
}

void clearBoard() { //clears the board
  int row,col;
  for (row = 0; row < mapSize; row++)
  {
    for (column = 0; column < mapSize; column++)
    {
      board[line][column] = 0;
      player1Hits[line][column] = 0;
      player2Hits[line][column] = 0;
    }
  }
}

int main() {
  return 0;
}
