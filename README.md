# Challenge 1 - UFCFVK-15-2 - Internet of Things

## Overview
We were challenged to implement a simple game using the BBC Micro:Bit device within a 
two week period. Details of the specification are below.

My solution to this challenge is a form of the classic game Rock, Paper, Scissors. It 
takes advantage of both buttons for the item selection and the accelerometer to detect a 
shake which confirms item selection. For single player mode, the computer randomly 
decides on its item and confirms whether the player has won, lost, or drawn.
For 2 player mode, the Micro:Bit's radio is used to communicate between two Micro:Bit
devices.

## Task Specification
(This information is copied from the Assignment brief found on Blackboard).

Implement a simple game on the BBC Microbit that uses the LED matrix and at least two
buttons or other sensors on the device.

Your solution should be implemented using C++.

Your solution must be committed in UWE's Gitlab. It will naturally be time stamped and you
must be careful to not make commits after the submission deadline.

Implementing the bare requirements described above will enable you to reach a maximum
of 70%, to get beyond that you must surprise us.

Your solution's source code should follow a coding convention, it should be well
commented, and include a README.md on how to build it and what and how to "play" it.

## Hardware
The game will only work on a BBC Micro:Bit. The diagram below shows the sensors, button 
and component positions, which may be of use when installing and playing the game.

![Micro:Bit Hardware Diagram](https://tech.microbit.org/docs/hardware/assets/microbit-overview-1-5.png)

You can read more about the hardware on the Hardware page (Micro:bit Educational Foundation, 2018). [2]

## Installation of game
### Prerequisites
In order to run this game, you will need the following hardware/software:
- At least one BBC Micro:Bit (two for 2 Player mode) and Micro USB cable (you can purchase 
one from Amazon, for example, https://tinyurl.com/ycs96p9e)
- A running copy of this virtual machine: https://tinyurl.com/ya59un4m You can get login 
credentials from XXXXXXXXX (University of the West of England)

### How-To
1. Open a Terminal window within the VM you've downloaded (see Prerequisites, above).
2. `cd` to the folder you wish to store the code for the game
3. `git clone https://gitlab.uwe.ac.uk/p3-goddard/ufcfvk-15-2-iot-challenge-1.git`
4. `cd ufcfvk-15-2-iot-challenge-1/game\ code`
5. `yt target bbc-microbit-classic-gcc`
6. `yt build`
7. Connect your Micro:Bit via USB to your computer.
8. `cp build/bbc-microbit-classic-gcc/source/iot-rps-2player-combined.hex /media/student/MICROBIT`
9. If you want to play against another player, remove the Micro:Bit and repeat steps 7 and 8 
for the second Micro:Bit

Now you are ready to play. See Game Play for instructions on how to play.

## Game Play
The table below takes you through the sequence of events possible within the game.
The Micro:Bit LED matrix is only 5x5 and the scrolling text can be frustrating for the user.
With this in mind, the gameplay mostly uses single characters to display messages to the user.
This table explains what those characters mean and what user input is available when displayed.

| Order              | What is displayed | What this means                                          | User Interaction                                                                     |
|--------------------| ------------------|----------------------------------------------------------|--------------------------------------------------------------------------------------|
| 1.                 | `C` or `F`        | Your competitor: Play against the computer or a Friend   | Switch between the two using the left (A) and right (B) buttons. Shake to confirm.   |
| 2.   	             | `R` or `P` or `S` | Your item selection: Rock, Paper or Scissors             | Switch item selection by using the left (A) and right (B) buttons. Shake to confirm. |
| 3. (2 Player only) | `Wait...`         | Wait for your friend to select their item.               | None.                                                                                |
| 4.                 | `W` or `L` or `D` | The game results: Win, Lose or Draw                      | None.                                                                                |

Use the `reset` button to play a new game.

## Technical Details
### Class Breakdown
![Class Diagram](https://gitlab.uwe.ac.uk/p3-goddard/ufcfvk-15-2-iot-challenge-1/raw/master/ClassDiagram.png)

#### Player
This is the parent class for forming the two child classes.

It contains two variables:

`u_int8_t item` holds the selected item to play, i.e. rock, paper or scissors. These are represented by 0, 1 or 2 respectively.

`u_int8_t item_confirmed` contains whether the player has confirmed their item choice.

The functions it contains are:

`u_int8_t get_item()` returns the item value (i.e. 0, 1 or 2 for rock, paper or scissors respectively).

`char get_item_name()` returns the item's name as a char (i.e. R, P or S for rock, paper or scissors respectively).

`void set_item(u_int8_t item)` updates the item's value to that which is passed in

`u_int8_t is_item_confirmed()` returns the boolean of item_confirmed

`void set_item_confirmed(u_int8_t item_confirmed)` updates the item_confirmed variable to that which is passed in

#### Competitor
Inherits Player.

It contains two variables:

`u_int8_t type` holds which type of competitor to play: 0 for Computer and 1 for Friend

`u_int8_t confirmed` contains whether the player has confirmed their competitor choice.

The functions it contains are:

`u_int8_t get_type()` returns the competitor type value (i.e. 0 or 1 for Computer or Friend, respectively).

`u_int8_t is_competitor_confirmed()` returns whether the player has confirmed their competitor choice via a 1 for true and 0 for false

`char get_type_name()` returns the competitors's name as a char (i.e. C for Computer, or F for Friend).

`void on_button_AorB()` switches the type variable between 0 (Computer) or 1 (Friend) as the competitor type

`void on_shake()` marks the competitor as confirmed, i.e. sets the confirmed variable to 1

#### MyPlayer
Inherits Player.

Contains no variables that are not inherited.

The functions it contains are:

`void on_button_A()` decrements the number stored in item to a minimum of 0. Once 0 is reached, if this is called again, set item to 2 (this allows accurate switching between Scissors, Paper then Rock and back to Scissors again).

`void on_button_B()` similar to on_button_A() but increments instead (i.e goes in the opposite direction)

`void on_shake()` marks the item as confirmed, i.e. sets the item_confirmed variable to 1

#### Interface

`char pick_winner(u_int8_t my_item, u_int8_t opponent_item)` the item selection for this player, and the item selection for the competitor is passed into this function. It works out whether there is a win, lose or draw and displays W, L or D respectively.

not using uBit as a whole, but the individual elements

### main.cpp / main()

Global variables to workaround for uBit.accelerometer.getGesture() not working:
`u_int8_t opponent_confirmed` the default is 0 and works with 
`u_int8_t item_confirmed` the default is 0
`int8_t opponent_item` the default is -1
`u_int8_t received` is a global variable used for marking whether the Player 2 Micro:Bit has sent a signal to confirm that it's received the item selection that was sent to it.

An instance of `MicroBit` is used and called `uBit`. This contains the runtime components for use (e.g. display, radio, accelerometer, etc).

There are two `PacketBuffer` objects used: `pb_send` and `pb_recevied`. `pb_send` contains the item selecting being sent to the other Micro:Bit and `pb_received` contains the received item selection and the confirmation bit once a received message is broadcast.

Objects of each class described above are created and used:
`MyPlayer me`
`Competitor opponent`
`Interface intrfc`

Functions:
`void competitor_shake(MicroBitEvent)` marks the global variable confirming the competitor.
`void item_shake(MicroBitEvent)` marks the global variable confirming the item.
`void send_item(u_int8_t item)` responsible for sending the item selection to the other player's Micro:Bit
`void onData(MicroBitEvent)` responsible for receiving the data from the other player's Micro:Bit

### Performance
To save of memory, I used `u_int_8`, where possible, instead of the default 32 bit integers.

During the works of this project, I attempted to save on memory by using the individual runtime components instead of creating an instance of the entire MicroBit object (usually named uBit). I was able to get all of the components I needed running apart from the Accelerometer. I searched the header files, and cpp files but couldn't find the code needed to get this working. I eventually raised a support ticket[3] for help and was provided with different code to use which did work. However, once this was up and running, I discovered that the volume of code needed for the Accelerometer to work was large and, after discussion with Ben, decided that the savings made by using the individual components would be minimal.

### Problems and Future Improvements
The getGesture() function doesn't seem to work. I have used the accelerometer code provided in the support ticket I raised to the Micro:bit support and can confirm that related functions, getX() and getY() work, but getGesture() still fails. I have therefore used the listener within my main function and called a non-OOP function to register global variables, and then used those global variables to call the OOP functions. This workaround is clearly marked in code, see lines 25-29, 37-44, 96-101 and 119 in main.cpp.
This also directly links to the issue of using OOP functions in listeners - which does not seem to be possible and therefore the workarounds take this into consideration.

I took the decision not to pass my object of MicroBit into my classes in an attempt to improve the ideals behind my program. I was aiming for code reusability and to minimise passing the uBit object around. However, in building this project and content from other modules delivered during this project's run, I am now more familiar with OOP classes and will aim to make the code cleaner in future by using pointers to the uBit in future.

## References

[1] Lancaster University (2018) *micro:bit runtime.* Available from: https://lancaster-university.github.io/microbit-docs/ [Accessed 28 January 2019].

[2] Micro:bit Educational Foundation (2018) *Hardware.* Available from: Hardware [Accessed 07 February 2019].

[3] Williams, M. (2019) Support Ticket Answer to Paul Goddard, 07 February.

[4] University of the West of England, CSCT, (2019) *Internet of Things Practical Week 1* [online]. Bristol. UWE. Available from: https://blackboard.uwe.ac.uk/bbcswebdav/pid-6702826-dt-content-rid-14420247_2/courses/UFCFVK-15-2_18jan_2/UFCFVK-15-2_Practical_Week1.pdf [Accessed 23 January 2019].
