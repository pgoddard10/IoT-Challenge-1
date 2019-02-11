/**
 * Project IoT Task 1 - Build a Game
 * @author Paul Goddard - 17019749
 */

#include "Interface.h"

#define	ROCK		0
#define	PAPER		1
#define	SCISSORS	2

#define	COMPUTER	0
#define	FRIEND		1

Interface::Interface()
{
}


Interface::~Interface()
{
}

char Interface::pick_winner(u_int8_t my_item, u_int8_t opponent_item) {
	// the item selection for this player, and the item selection for the competitor is passed into this function. It works out whether there is a win, lose or draw and displays W, L or D respectively.
	if ((my_item == ROCK) && (opponent_item == PAPER)) //rock vs paper
		return 'L';
	else if ((my_item == ROCK) && (opponent_item == SCISSORS)) //rock vs scissors
		return 'W';
	else if ((my_item == PAPER) && (opponent_item == ROCK)) //paper vs rock
		return 'W';
	else if ((my_item == PAPER) && (opponent_item == SCISSORS)) //paper vs scissors
		return 'L';
	else if ((my_item == SCISSORS) && (opponent_item == ROCK)) //scissors vs rock
		return 'L';
	else if ((my_item == SCISSORS) && (opponent_item == PAPER)) //scissors vs paper
		return 'W';
	else
		return 'D';
}
