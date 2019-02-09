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
	item = ROCK;
	item_confirmed = 0;
}


Player::~Player()
{
}

u_int8_t Player::get_item() {
	return item;
}

char Player::get_item_name() {
	if (this->item == ROCK)
		return 'R';
	else if (this->item == PAPER)
		return 'P';
	else
		return 'S';
}

u_int8_t Player::is_item_confirmed() {
	return item_confirmed;
}

void Player::set_item(u_int8_t item) {
	this->item = item;
}

void Player::set_item_confirmed(u_int8_t item_confirmed) {
	this->item_confirmed = item_confirmed;
}
