/**
 * Challenge 1 - UFCFVK-15-2
 * Specification:
 *		Implement a simple game on the BBC Micro:Bit that uses the LED
 * 		matrix and at least two buttons or other sensors on the device. 
 * 
 * @author Paul Goddard - 17019749
 * 
 */


#ifndef PLAYER_H
#define PLAYER_H

#include "MicroBit.h"

#define	ROCK		0
#define	PAPER		1
#define	SCISSORS	2

class Player
{
protected:
	u_int8_t item;
	u_int8_t item_confirmed;
public:
	Player();
	~Player();
	u_int8_t get_item();
	char get_item_name();
	void set_item(u_int8_t item);
	u_int8_t is_item_confirmed();
	void set_item_confirmed(u_int8_t item_confirmed);
};

#endif
