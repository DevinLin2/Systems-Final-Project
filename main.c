#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int board[10][10], player1Hits[10][10], player2Hits[10][10], boardSize = 10, numSubmarines = 10, numHits = 10;

void clearScreen() { //clears screen
  system("@cls||clear");
}

void clearBoard() { //clears the board
  int row,col;
  for (row = 0; row < boardSize; row++)
  {
    for (col = 0; col < boardSize; col++)
    {
      board[row][col] = 0;
      player1Hits[row][col] = 0;
      player2Hits[row][col] = 0;
    }
  }
}

void setSubmarines() { //takes user input as coords and places a submarine there on the board
  int i;
  for (i = 0; i < numSubmarines; i++) {
    int row, col;
    printf("Enter a row (0-9) of submarine %i: ", i);
    fgets("%d", &row, stdin);
    printf("Enter a column (0-9) of submarine %i: ", i);
    fgets("%d", &col, stdin);
    board[row][col] = 1;
  }
}

void display() { //shows board and submarines
  printf("\nCurrent board and game status:\n");
  int row,col,i;
  for (row = 0; row < boardSize; row++) {
    if (row == 0) {
      for (i = 0; i <= boardSize; i++) {
        if (i == 0) printf("   ");
        else printf(" %d ", i - 1);
      }
      printf("\n\n");
    }
    for (col = 0; col < boardSize; col++) {
      if (col == 0) printf("%d  ", row);
      printf(" %d ", board[row][col]);
    }
    printf("\n");
  }
  printf("\nPress enter to start the game...");
  int enter = 0;
  while (enter != '\r' && enter != '\n') {
    fgets("%d",enter,stdin);
  }
}

void setPlayerHits(player) { //records players' attempts
  printf("\nWelcome player %d, you have %i tries to find %i submarines, good luck!\n", player, numHits, numSubmarines);
  int i;
  switch (player) {
  case 1:
    for (i = 0; i < numHits; i++) {
      int row, col;
      printf("Enter a row (0-9) for submarine %d: ", i);
      fgets(" %d", row, stdin);
      printf("Enter a column (0-9) for submarine %d: ", i);
      fgets(" %d", col, stdin);
      player1Hits[row][col] = 1;
    }
    break;
  case 2:
    for (i = 0; i < numHits; i++) {
      int row, col;
      printf("Enter a row (0-9) for submarine %d: ", i);
      fgets(" %d", row, stdin);
      printf("Enter a column (0-9) for submarine %d: ", i);
      fgets(" %d", col, stdin);
      player2Hits[row][col] = 1;
    }
    break;
  default:
    break;
  }
}

void checkShots(player) { //checks to see if a player sunk a ship

}

int main() {
  clearMap();
  setSubmarines();
  display();
  clearScreen();
  setPlayerHits(2)
  return 0;
}
