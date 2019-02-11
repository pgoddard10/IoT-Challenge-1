/**
 * Challenge 1 - UFCFVK-15-2
 * Specification:
 *		Implement a simple game on the BBC Micro:Bit that uses the LED
 * 		matrix and at least two buttons or other sensors on the device. 
 * 
 * @author Paul Goddard - 17019749
 * 
 */

#include "MyPlayer.h"

#define	ROCK		0
#define	PAPER		1
#define	SCISSORS	2

MyPlayer::MyPlayer()
{
}


MyPlayer::~MyPlayer()
{
}

void MyPlayer::on_button_A() {
	//decrements the number stored in item to a minimum of 0. Once 0 is reached, if this is called again, set item to 2 (this allows accurate switching between Scissors, Paper then Rock and back to Scissors again).
	if (this->item == ROCK)
		this->item = SCISSORS;
	else //create a selection 'wheel' rather than just left to right
		this->item--;
}

void MyPlayer::on_button_B() {
	//similar to on_button_A() but increments instead (i.e goes in the opposite direction)
	if (this->item == SCISSORS)
		this->item = ROCK;
	else //create a selection 'wheel' rather than just left to right
		this->item++;
}

void MyPlayer::on_shake() {
	//marks the item as confirmed, i.e. sets the item_confirmed variable to 1
	this->item_confirmed = 1;
}
