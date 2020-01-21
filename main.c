#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
  int i,player;
  int enter;
  for (i = 1; i < 3; i++){
    clearScreen();
    clearBoard();
    setShips(i);
    display(0);
    clearScreen();
    setPlayerHits(i);
    showPlayerHits(i);
    checkHits(i);
    if (i == 1) {
      printf("\nPress enter for player 2's turn...");
      while (enter != '\r' && enter != '\n') {
        enter = getchar();
      }
    }
  }
  if (getP1Hits() == getP2Hits()){
    printf("\nTIE!\n");
  }
  else if (getP1Hits() > getP2Hits()){
    printf("\nPlayer 1 has has won!\n");
  }
  else {
    printf("\nPlayer 2 has has won!\n");
  }
  printf("Game Finished\n");
  return 0;
}
