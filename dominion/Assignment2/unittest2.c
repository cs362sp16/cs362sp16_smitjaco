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

  // TESTING - getCost

 
  int estateValue = getCost(estate);
  if (estateValue == 2) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  int duchyValue = getCost(duchy);
  if (duchyValue == 5) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

   int curseValue = getCost(curse);
  if (curseValue == 0) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }
  
  
  int provinceValue = getCost(province);
  if (provinceValue == 8) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  int remodelValue = getCost(remodel);
  if (remodelValue == 8) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  int smithyValue = getCost(smithy);
  if (smithyValue == 4) {
	printf("PASSED\n");  
  } else {
	printf("FAILED\n");
  }

  return 0;
}