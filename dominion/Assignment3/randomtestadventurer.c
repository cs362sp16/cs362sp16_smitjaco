#include "dominion.h"
//#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 30

//This randomly tests Adventurer

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, players, player, handCount, deckCount, seed;
	  //struct gameState state;
	  struct gameState state;

	  printf("--- Running Random ADVENTURER Test ---\n");

	  // Actually set player variable
	  player = 0;

	  for (i = 0; i < MAX_TESTS; i++) {
        int flag = 0;
	    players = rand() % 4;
	    seed = rand();
		
	    initializeGame(players, k, seed, &state);	//initialize Gamestate

	    //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			state.deckCount[player] = 0;
		  } // 1 in 3 chance of adding 2 treasure cards to deck
		  else if ((seed - 1) %3 == 0) {
            state.deck[player][deckCount] = gold;
            state.deck[player][deckCount+1] = silver;
            state.deckCount[player] = deckCount+2;
            flag = 1;
		  }

		  int cE = cardEffect(adventurer, 1, 1, 1, &state, 0);		//Run adventurer card

		  if (cE != 0){
		    printf("Failed (cE == 0) condition\n");
		  }

		  if (flag == 1) {
		    if (!(state.handCount[player] == (handCount+2))){
		       printf("Failed (currentHandCount = handCount+2) condition\n");
		    }
		  }
	  }

	  printf("--- Tests Complete ---\n");

	  return 0;
}