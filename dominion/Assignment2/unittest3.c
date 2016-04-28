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

  // TESTING - isGameOver

  int iGO = isGameOver(&G);
  if (iGO == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  // The game ends when Providence cards are all gone
  G.supplyCount[province] == 0;
  iGO = isGameOver(&G);
  if (iGO == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  // Or the game ends when any 3 stacks are empty
  srand(time(NULL));
  int rand1 = ( rand()%25 );
  int rand2 = ( rand()%25 );
  int rand3 = ( rand()%25 );

  G.supplyCount[rand1] == 0;
  G.supplyCount[rand2] == 0;
  G.supplyCount[rand3] == 0;

  iGO = isGameOver(&G);
  if (iGO == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  return 0;
}