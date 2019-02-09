/**
 * Challenge 1 - UFCFVK-15-2
 * Specification:
 *		Implement a simple game on the BBC Micro:Bit that uses the LED
 * 		matrix and at least two buttons or other sensors on the device. 
 * 
 * @author Paul Goddard - 17019749
 * 
 */


#ifndef MYPLAYER_H
#define MYPLAYER_H

#include "MicroBit.h"

#define	COMPUTER	0
#define	FRIEND		1

#include "MicroBit.h"
#include "Player.h"

class MyPlayer : public Player
{
public:
	MyPlayer();
	~MyPlayer();
	void on_button_A();
	void on_button_B();
	void on_shake();
};

#endif
