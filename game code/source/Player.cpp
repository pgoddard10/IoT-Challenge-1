/**
 * Challenge 1 - UFCFVK-15-2
 * Specification:
 *		Implement a simple game on the BBC Micro:Bit that uses the LED
 * 		matrix and at least two buttons or other sensors on the device. 
 * 
 * @author Paul Goddard - 17019749
 * 
 */


#include "Player.h"

#define	ROCK		0
#define	PAPER		1
#define	SCISSORS	2

Player::Player()
{
	item = ROCK; //holds the selected item to play, i.e. rock, paper or scissors. These are represented by 0, 1 or 2 respectively.
	item_confirmed = 0; //contains whether the player has confirmed their item choice.
}


Player::~Player()
{
}

u_int8_t Player::get_item() {
	//returns the item value (i.e. 0, 1 or 2 for rock, paper or scissors respectively).
	return item;
}

char Player::get_item_name() {
	//returns the item's name as a char (i.e. R, P or S for rock, paper or scissors respectively).
	if (this->item == ROCK)
		return 'R';
	else if (this->item == PAPER)
		return 'P';
	else
		return 'S';
}

u_int8_t Player::is_item_confirmed() {
	//returns the boolean of item_confirmed
	return item_confirmed;
}

void Player::set_item(u_int8_t item) {
	//updates the item's value to that which is passed in
	this->item = item;
}

void Player::set_item_confirmed(u_int8_t item_confirmed) {
	//updates the item_confirmed variable to that which is passed in
	this->item_confirmed = item_confirmed;
}
