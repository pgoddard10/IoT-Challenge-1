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
	type = COMPUTER;
	confirmed = 0;
}


Competitor::~Competitor()
{
}

u_int8_t Competitor::get_type() {
	return this->type;
}

u_int8_t Competitor::is_competitor_confirmed() {
	return this->confirmed;
}

char Competitor::get_type_name() {
	if(this->type == COMPUTER)
		return 'C';
	else
		return 'F';
}

void Competitor::on_button_AorB() {
	if (this->type == FRIEND)
		this->type = COMPUTER;
	else if (this->type == COMPUTER)
		this->type = FRIEND;
}

void Competitor::on_shake() {
	this->confirmed = 1;
}
