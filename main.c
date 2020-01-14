#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 512

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
    char inputr[SIZE], inputc[SIZE];
    char * row;
    char * col;
    printf("Enter a row (0-9) of submarine %i: ", i);
    fgets(inputr,SIZE,stdin);
    row = inputr;
    printf("Enter a col (0-9) of submarine %i: ", i);
    fgets(inputc,SIZE,stdin);
    col = inputc;
    //printf("ROW: %d\n", r);
    board[atoi(row)][atoi(col)] = 1;
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
    fgets(&enter,25,stdin);
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
      fgets(&row,25,stdin);
      printf("Enter a col (0-9) for submarine %d: ", i);
      fgets(&col,25,stdin);
      player1Hits[row][col] = 1;
    }
    break;
  case 2:
    for (i = 0; i < numHits; i++) {
      int row, col;
      printf("Enter a row (0-9) for submarine %d: ", i);
      fgets(&row,25,stdin);
      printf("Enter a col (0-9) for submarine %d: ", i);
      fgets(&col,25,stdin);
      player2Hits[row][col] = 1;
    }
    break;
  default:
    break;
  }
}

void checkHits(player) { //checks to see if a player sunk a ship
  int missed = 0;
  int hits = 0;
  int row,col;
  for (row = 0; row < boardSize; row++) {
    for (col = 0; col < boardSize; col++) {
      switch (player) {
      case 1:
        if (board[row][col] == 1 && player1Hits[row][col] == 1) {
          printf("\nPlayer %d sunk the submarine at row %d, col %d", player, row, col);
          hits++;
        }
        else if (board[row][col] == 0 && player1Hits[row][col] == 1) {
          printf("\nPlayer %d hit nothing at row %d, col %d", player, row, col);
          missed++;
        }
        {
        }
        break;
      case 2:
        if (board[row][col] == 1 && player2Hits[row][col] == 1) {
          printf("\nPlayer %d sunk the submarine at row %d, col %i", player, row, col);
          hits++;
        }
        else if (board[row][col] == 0 && player2Hits[row][col] == 1) {
          printf("\nPlayer %d hit nothing at row %d, col %d", player, row, col);
          missed++;
        }
        break;
      default:
        break;
      }
    }
  }
  printf("\nPlayer %d has sunk %d ships", player, hits);
  printf("\nPlayer %d has missed %d shots\n", player, missed);
}

void showPlayerHits(player) { //shows the players' hits on the boards
  char submarine[] = "s";
  char submarineSunk[] = "d";
  char missedHit[] = "x";
  char empty[] = "_";
  printf("\nPlayer %d has made the following shots: \n\n", player);
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
      switch (player) {
      case 1:
        if (player1Hits[row][col] == 1 && board[row][col] == 1) {
          printf(" %s ", submarineSunk);
        }
        else if (player1Hits[row][col] == 1 && board[row][col] == 0) {
          printf(" %s ", missedHit);
        }
        else if (player1Hits[row][col] == 0 && board[row][col] == 1) {
          printf(" %s ", submarine);
        }
        else {
          printf(" %s ", empty);
        }
        break;
      case 2:
        if (player2Hits[row][col] == 1 && board[row][col] == 1) {
          printf(" %s ", submarineSunk);
        }
        else if (player2Hits[row][col] == 1 && board[row][col] == 0) {
          printf(" %s ", missedHit);
        }
        else if (player2Hits[row][col] == 0 && board[row][col] == 1) {
          printf(" %s ", submarine);
        }
        else
        {
          printf(" %s ", empty);
        }
        break;
      default:
        break;
      }
    }
    printf("\n");
  }
  printf("\nKey:  d: submarines sunk; s: submarines; x: empty cell;\n");
}

int main() {
  clearBoard();
  setSubmarines();
  display();
  //clearScreen();
  //setPlayerHits(2);
  //showPlayerHits(2);
  //checkHits(2);
  return 0;
}
