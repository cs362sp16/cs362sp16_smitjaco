#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv) {
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");

  // 2 player game
  srand(time(NULL));
  int rando = ( rand()%10 );
  int r = initializeGame(2, k, rando, &G);
  if (r == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  // TESTING -- int council_roomEffect(int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
  // Council Room will add +4 cards, +1 buy, and each other player draws a card
  int p1handCount = G.handCount[0];
  int p2handCount = G.handCount[1];
  int numBuys = G.numBuys;

  int cRE = council_roomEffect(0, 0, 0, &G, 0);
  
  if (G.handCount[1] == (p2handCount+1)) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }
  if (G.handCount[0] == (p1handCount+4)) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }
  if (G.numBuys == (numBuys+1)) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }
  if (cRE == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  return 0;
}