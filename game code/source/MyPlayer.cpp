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
	if (this->item == ROCK)
		this->item = SCISSORS;
	else //create a selection 'wheel' rather than just left to right
		this->item--;
}

void MyPlayer::on_button_B() {
	if (this->item == SCISSORS)
		this->item = ROCK;
	else //create a selection 'wheel' rather than just left to right
		this->item++;
}

void MyPlayer::on_shake() {
	this->item_confirmed = 1;
}
