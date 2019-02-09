/**
 * Challenge 1 - UFCFVK-15-2
 * Specification:
 *		Implement a simple game on the BBC Micro:Bit that uses the LED
 * 		matrix and at least two buttons or other sensors on the device. 
 * 
 * @author Paul Goddard - 17019749
 * 
 */

#ifndef COMPETITOR_H
#define COMPETITOR_H

#define	COMPUTER	0
#define	FRIEND		1

#include "MicroBit.h"
#include "Player.h"

class Competitor : public Player
{
protected:
	u_int8_t type;
	u_int8_t confirmed;
public:
	Competitor();
	~Competitor();
	u_int8_t get_type();
	u_int8_t is_competitor_confirmed();
	char get_type_name();
	void on_button_AorB();
	void on_shake();
};

#endif
