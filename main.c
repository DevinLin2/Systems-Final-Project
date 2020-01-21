#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
  clearScreen();
  int enter;
  printf("\n\n\n\n\n\n\n\n\n\n\t\tWelcome to battleship. Please hit enter to begin.");
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  int i,player;
  enter = 0;
  for (i = 1; i < 3; i++){
    clearScreen();
    clearBoard();
    setShips(i);
    display(0);
    clearScreen();
    if (i == 1) {
      setPlayerHits(2);
      showPlayerHits(2);
	  printf("\nPlayer 2 has sunk %d ships", checkHits(2));
	  printf("\nPlayer 2 has missed %d shots\n", 10 - checkHits(2));
    } else {
      setPlayerHits(1);
      showPlayerHits(1);
      printf("\nPlayer 1 has sunk %d ships", checkHits(1));
	  printf("\nPlayer 1 has missed %d shots\n", 10 - checkHits(1));
    }
    if (i == 1) {
      printf("\nPress enter for player 2's turn...");
      while (enter != '\r' && enter != '\n') {
        enter = getchar();
      }
    }
  }
  if (checkHits(1) == checkHits(2)){
    printf("\nTIE!\n");
  }
  else if (checkHits(1) < checkHits(2)){
    printf("\nPlayer 1 has won!\n");
  }
  else {
    printf("\nPlayer 2 has won!\n");
  }
  printf("Game Finished\n");
  return 0;
}
