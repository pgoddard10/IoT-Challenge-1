/**
 * Project IoT Task 1 - Build a Game
 * @author Paul Goddard - 17019749
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include "MicroBit.h" //included for the u_int8_t usage

class Interface
{
public:
	Interface();
	~Interface();
	char pick_winner(u_int8_t my_item, u_int8_t opponent_item);
};

#endif
