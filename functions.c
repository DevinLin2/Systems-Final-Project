#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int board[10][10], player1Hits[10][10], player2Hits[10][10];
int p1Hits = 0, p2Hits = 0, boardSize = 10, numships = 10, numHits = 10;

void clearScreen() { //clears screen
  system("clear");
}

char ** parse(char *line, char *delimiter) { //parsing line
	char * args = calloc(SIZE, 1);
	strcpy(args, line);
	char ** parsed = malloc(SIZE);
	int i;
	for (i = 0; args != NULL; i++) {
		parsed[i] = strsep(&args, delimiter);
  }
	parsed[i] = NULL;
	return parsed;
}

void clearBoard() { //clears the board
  int row,col;
  for (row = 0; row < boardSize; row++) {
    for (col = 0; col < boardSize; col++) {
      board[row][col] = 0;
      player1Hits[row][col] = 0;
      player2Hits[row][col] = 0;
    }
  }
}

void display(int status) { //shows board and ships
  printf("\nCurrent board and game status:\n\n");
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
  if (status == 0){
    printf("\nPress enter to start the game...");
    int enter;
    while (enter != '\r' && enter != '\n') {
      enter = getchar();
      //printf("%d\n", enter);
    }
  }
  else {
    printf("\n");
  }
}

void setShips(int player) { //takes user input as coords and places a ship there on the board
  int i;
  printf("Welcome player %d, you have %d ships to place on the board, have fun!\n", player, numships);
    for (i = 0; i < numships; i++) {
      char input[SIZE], row[SIZE], col[SIZE];
      char ** coords;
      printf("Enter a coordinate (row column)(0-9) for ship %d: ", i+1);
      fgets(input,SIZE,stdin);
      coords = parse(input, " ");
      // printf("%s\n", coords[0]);
      // printf("%s\n", coords[1]);
      //printf("%c\n", input[0]);
      //printf("%d\n", strcmp(&input[0], "") );
      strcpy(row, coords[0]);
      strcpy(col, coords[1]);
      free(coords);
      //printf("%s\n", col);
      //printf("%d\n", atoi(row));
      //printf("%d\n", atoi(col));
      //row = input;
      //col = input;
      //printf("ROW: %d\n", r);
      if (atoi(row) > 9 || atoi(row) < 0
       || atoi(col) > 9 || atoi(col) < 0) {
        printf("Enter A Number 0 Through 9 Inclusive\n");
        i--;
      }
      else if (board[atoi(row)][atoi(col)] == 1){
        printf("Already Chose This Coordinate\n");
        i--;
      }
      else {
        board[atoi(row)][atoi(col)] = 1;
        display(1);
      }
    }
}

void showPlayerHits(int player) { //shows the players' hits on the boards
  char ship[] = "s";
  char shipSunk[] = "d";
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
          printf(" %s ", shipSunk);
        }
        else if (player1Hits[row][col] == 1 && board[row][col] == 0) {
          printf(" %s ", missedHit);
        }
        else if (player1Hits[row][col] == 0 && board[row][col] == 1) {
          printf(" %s ", ship);
        }
        else {
          printf(" %s ", empty);
        }
        break;
      case 2:
        if (player2Hits[row][col] == 1 && board[row][col] == 1) {
          printf(" %s ", shipSunk);
        }
        else if (player2Hits[row][col] == 1 && board[row][col] == 0) {
          printf(" %s ", missedHit);
        }
        else if (player2Hits[row][col] == 0 && board[row][col] == 1) {
          printf(" %s ", ship);
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
  printf("\nKey:  d: ships sunk; s: ships; x: empty cell;\n");
}

void displayHits(int player) { //shows a players hits
  char shipSunk[] = "d";
  char missedHit[] = "x";
  int row,col,i;
  printf("\nCurrent board and game status:\n\n");
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
          printf(" %s ", shipSunk);
        }
        else if (player1Hits[row][col] == 1 && board[row][col] == 0) {
          printf(" %s ", missedHit);
        }
        else {
          printf(" %d ", 0);
        }
        break;
      case 2:
        if (player2Hits[row][col] == 1 && board[row][col] == 1) {
          printf(" %s ", shipSunk);
        }
        else if (player2Hits[row][col] == 1 && board[row][col] == 0) {
          printf(" %s ", missedHit);
        }
        else {
          printf(" %d ", 0);
        }
        break;
      default:
        break;
      }
    }
    printf("\n");
  }
  printf("\nKey:  d: ships sunk\n");
}

void setPlayerHits(int player) { //records players' attempts
  printf("Welcome player %d, you have %d tries to find %d ships, good luck!\n", player, numHits, numships);
  int i;
  switch (player) {
  case 1:
    for (i = 0; i < numHits; i++) {
      char input[SIZE], row[SIZE], col[SIZE];
      char ** coords;
      printf("Enter a coordinate (row column)(0-9) for ship %d: ", i+1);
      fgets(input,SIZE,stdin);
      coords = parse(input, " ");
      strcpy(row, coords[0]);
      strcpy(col, coords[1]);
      free(coords);
      if (atoi(row) > 9 || atoi(row) < 0
       || atoi(col) > 9 || atoi(col) < 0) {
        printf("Enter A Number 0 Through 9 Inclusive\n");
        i--;
      }
      else if (player1Hits[atoi(row)][atoi(col)] == 1){
        printf("Already Chose This Coordinate\n");
        i--;
      }
      else {
        player1Hits[atoi(row)][atoi(col)] = 1;
        displayHits(player);
      }
    }
    break;
  case 2:
    for (i = 0; i < numHits; i++) {
      char input[SIZE], row[SIZE], col[SIZE];
      char ** coords;
      printf("Enter a coordinate (row column)(0-9) for ship %d: ", i+1);
      fgets(input,SIZE,stdin);
      coords = parse(input, " ");
      strcpy(row, coords[0]);
      strcpy(col, coords[1]);
      free(coords);
      if (atoi(row) > 9 || atoi(row) < 0
       || atoi(col) > 9 || atoi(col) < 0) {
        printf("Enter A Number 0 Through 9 Inclusive\n");
        i--;
      }
      else if (player2Hits[atoi(row)][atoi(col)] == 1){
        printf("Already Chose This Coordinate\n");
        i--;
      }
      else {
        player2Hits[atoi(row)][atoi(col)] = 1;
        displayHits(player);
      }
    }
    break;
  default:
    break;
  }
}

void checkHits(int player) { //checks to see if a player sunk a ship
  int missed = 0;
  int hits = 0;
  int row,col;
  for (row = 0; row < boardSize; row++) {
    for (col = 0; col < boardSize; col++) {
      switch (player) {
      case 1:
        if (board[row][col] == 1 && player1Hits[row][col] == 1) {
          //printf("\nPlayer %d sunk the ship at row %d, col %d", player, row, col);
          hits++;
        }
        else if (board[row][col] == 0 && player1Hits[row][col] == 1) {
          //printf("\nPlayer %d hit nothing at row %d, col %d", player, row, col);
          missed++;
        }
        break;
      case 2:
        if (board[row][col] == 1 && player2Hits[row][col] == 1) {
          hits++;
        }
        else if (board[row][col] == 0 && player2Hits[row][col] == 1) {
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

int getP1Hits(){
  return p2Hits;
}

int getP2Hits(){
  return p2Hits;
}
