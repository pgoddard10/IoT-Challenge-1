/**
 * Challenge 1 - UFCFVK-15-2
 * Specification:
 *		Implement a simple game on the BBC Micro:Bit that uses the LED
 * 		matrix and at least two buttons or other sensors on the device. 
 * 
 * @author Paul Goddard - 17019749
 * 
 */

 
#include "Competitor.h"

#define	COMPUTER	0
#define	FRIEND		1

Competitor::Competitor()
{
	type = COMPUTER; //holds which type of competitor to play: 0 for Computer and 1 for Friend
	confirmed = 0; //contains whether the player has confirmed their competitor choice.
}


Competitor::~Competitor()
{
}

u_int8_t Competitor::get_type() {
	//returns the competitor type value (i.e. 0 or 1 for Computer or Friend, respectively).
	return this->type;
}

u_int8_t Competitor::is_competitor_confirmed() {
	//returns whether the player has confirmed their competitor choice via a 1 for true and 0 for false
	return this->confirmed;
}

char Competitor::get_type_name() {
	//returns the competitors's name as a char (i.e. C for Computer, or F for Friend).
	if(this->type == COMPUTER)
		return 'C';
	else
		return 'F';
}

void Competitor::on_button_AorB() {
	//switches the type variable between 0 (Computer) or 1 (Friend) as the competitor type
	if (this->type == FRIEND)
		this->type = COMPUTER;
	else if (this->type == COMPUTER)
		this->type = FRIEND;
}

void Competitor::on_shake() {
	//marks the competitor as confirmed, i.e. sets the confirmed variable to 1
	this->confirmed = 1;
}
