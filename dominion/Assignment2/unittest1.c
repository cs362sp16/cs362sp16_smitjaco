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

  srand(time(NULL));
  int rando = ( rand()%10 );
  int r = initializeGame(2, k, rando, &G);
  
  if (r == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }
  
  // TESTING - buyCard

  int prevNumBuys = G.numBuys;
  int prevCoins = G.coins;

  int bC = buyCard(copper, &G);

  if (bC == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }
  if (G.numBuys == (prevNumBuys - 1)) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }
  if (G.coins == (prevCoins - (getCost(copper)))) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }
  return 0;
}