#define SIZE 512
void clearScreen();
char ** parse(char *line, char *delimiter);
void clearBoard();
void display(int status);
void setShips(int player);
void showPlayerHits(int player);
void displayHits(int player);
void setPlayerHits(int player);
int checkHits(int player);
int getP1Hits();
int getP2Hits();
