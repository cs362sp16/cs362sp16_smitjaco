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

  // TESTING - whoseTurn

  int wT = whoseTurn(&G);
  if (wT == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }


  int endingTurn = endTurn(&G);
  if (endingTurn == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }
  wT = whoseTurn(&G);
  if (wT == 1) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  return 0;
}