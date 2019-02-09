/**
 * Challenge 1 - UFCFVK-15-2
 * Specification:
 *		Implement a simple game on the BBC Micro:Bit that uses the LED
 * 		matrix and at least two buttons or other sensors on the device. 
 * 
 * @author Paul Goddard - 17019749
 * 
 */


#include "MicroBit.h"
#include "Player.h"
#include "MyPlayer.h"
#include "Competitor.h"
#include "Interface.h"

#define	ROCK		0
#define	PAPER		1
#define	SCISSORS	2

#define	COMPUTER	0
#define	FRIEND		1

//global variables to workaround for uBit.accelerometer.getGesture() not working
u_int8_t opponent_confirmed = 0;
u_int8_t item_confirmed = 0;
int8_t opponent_item = -1; //signed because of negative number
//workaround end

//global variable for the radio send/receive
u_int8_t received = 0;

//micro:bit runtime components
MicroBit   			uBit;

//functions to workaround for uBit.accelerometer.getGesture() not working
void competitor_shake(MicroBitEvent) {
	opponent_confirmed = 1;
}
void item_shake(MicroBitEvent) {
	item_confirmed = 1;
}
//workaround end

void send_item(u_int8_t item) {
	PacketBuffer pb_send(1);
	pb_send[0] = item; //send this player's selected item
	uBit.radio.datagram.send(pb_send);
	fiber_sleep(100);
}

//radio send/receive for 2 player mode
void onData(MicroBitEvent) {
	PacketBuffer pb_recevied = uBit.radio.datagram.recv();
	
	if(pb_recevied[0]>=ROCK && pb_recevied[0]<=SCISSORS) {
		//send confirmation back that the message has been received
		PacketBuffer pb_send(1); //create new packet buffer
		pb_send[0] = 9; //set it to a value not used elsewhere
		uBit.radio.datagram.send(pb_send); //send 9 to the other player
		
		//set the global variable to the opponents chosen item
		if (pb_recevied[0] == ROCK)
			opponent_item = ROCK;
		if (pb_recevied[0] == PAPER)
			opponent_item = PAPER;
		if (pb_recevied[0] == SCISSORS)
			opponent_item = SCISSORS;
	}
	
	if((pb_recevied[0]==9) && (opponent_item > -1)) {
		//if the opponent sends a received signal and the opponent item is already set
		//important to prevent overlap in power cycles (i.e. one micro:bit is left on, the other rebooted)
		received = 1;
	}
		
	fiber_sleep(100); //allow other fibers to run (have a kitkat)
}

int main() {
    uBit.init();
    uBit.radio.enable(); //turn the radio on
    uBit.radio.setGroup(2); //limit radio broadcasts to group 2 (prevents cross-over with colleague's games)

	//init objects
	MyPlayer me;
	Competitor opponent;
	Interface intrfc;

	//listen for response from other player
	uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);
	
	while(1) {
				
		//workaround for uBit.accelerometer.getGesture() not working
		if(opponent_confirmed)
			opponent.on_shake();
		if(item_confirmed)
			me.on_shake();
		//workaround end
						
		if (!me.is_item_confirmed()) { //if this player hasn't selected an item yet
			if (!opponent.is_competitor_confirmed()) { //if this player hasn't selected a competitor
				if((uBit.buttonA.isPressed()) || (uBit.buttonB.isPressed())) //buttons allow for switching between competitor
					opponent.on_button_AorB(); //switch from Friend to Computer and vica-versa
					
				uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_SHAKE, competitor_shake); //listen for confirmation of competitor selection	
				
				uBit.display.print(opponent.get_type_name()); //print F for Friend or C for Computer
			}
			else { //if the competitor has been selected
				if(uBit.buttonA.isPressed()) //switch between scissors/paper/rock
					me.on_button_A();
					
				if(uBit.buttonB.isPressed()) //switch between rock/paper/scissors
					me.on_button_B();
					
				uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_SHAKE, item_shake); //listen for confirmation of competitor selection
				
				uBit.display.print(me.get_item_name()); //print R for Rock, P for Paper, S for scissors
			}
		}
		else {
			if (!opponent.is_item_confirmed()) { //if the opponent hasn't confirmed their item
				if (opponent.get_type() == COMPUTER) { //if playing against the computer
					opponent.set_item(uBit.random(3)); //generate random number
					opponent.set_item_confirmed(1); //confirm item has been selected
				}
				else { //playing against a friend
					while(!received) { //keep sending signal until the other micro:bit confirms the message has been received
						uBit.display.scrollAsync("Wait.."); //user-friendly message (to say wait for opponent to make their choice)
						send_item(me.get_item()); //send this player's chosen item
						uBit.sleep(100);
					}
					if((opponent_item > -1) && (received)) {
						//convert global variables into OOP
						opponent.set_item(opponent_item);
						opponent.set_item_confirmed(1);
					}
				}
			}
			else {
				uBit.display.print(intrfc.pick_winner(me.get_item(), opponent.get_item())); //prints W for Winner, L for Loser, D for Draw
			}
		}
        uBit.sleep(100); //have a kitkat
	}
	return 0;
}
