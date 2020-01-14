#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[10][10], player1Shots[10][10], player2Shots[10][10], mapSize = 10, submarinesQty = 10, shotsQty = 10;

void clrscr() { //clears screen
  system("@cls||clear");
}
