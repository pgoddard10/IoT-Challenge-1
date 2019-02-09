# Challenge 1 - UFCFVK-15-2 - Internet of Things

## Overview
We were challenged to implement a simple game using the BBC Micro:Bit device within a 
two week period. Details of the specification are below.

My solution to this challenge is a form of the classic game Rock, Paper, Scissors. It 
takes advantage of both buttons for the item selection and the accelerometer to detect a 
shake which confirmes item selection. For single player mode, the computer randomly 
decides on its item and confirms whether the player has won, lost, or drawn.
For 2 player mode, the Micro:Bit's radio is used to communicate between two Micro:Bit
devices.

## Task Specification
(This information is copied from the Assignement brief found on Blackboard).

Implement a simple game on the BBC Microbit that uses the LED matrix and at least two
buttons or other sensors on the device.

Your solution should be implemented using C++.

Your solution must be committed in UWE's Gitlab. It will naturally be time stamped and you
must be careful to not make commits after the submission deadline.

Implementing the bare requirements described above will enable you to reach a maximum
of 70%, to get beyond that you must surprise us.

Your solution's source code should follow a coding convention, it should be well
commented, and include a README.md on how to build it and what and how to "play" it.

### Installation of game
#### Prerequisites
In order to run this game, you will need the following hardware/software:
- At least one BBC Micro:Bit (two for 2 Player mode) and Micro USB cable (you can purchase 
one from Amazon, for example, https://tinyurl.com/ycs96p9e)
- A running copy of this virtual machine: https://tinyurl.com/ya59un4m You can get login credentials from XXX (University of the West of England)

#### How-To
1. Open a Terminal window within the VM you've downloaded (see Prerequisites, above).
2. `cd` to the folder you wish to store the code for the game
3. `git clone https://gitlab.uwe.ac.uk/p3-goddard/ufcfvk-15-2-iot-challenge-1.git`
4. `cd ufcfvk-15-2-iot-challenge-1/game\ code`
5. `yt target bbc-microbit-classic-gcc`
6. `yt build`
7. Connect your Micro:Bit via USB to your computer.
8. `cp build/bbc-microbit-classic-gcc/source/iot-rps-2player-combined.hex /media/student/MICROBIT`
9. If you want to play against another player, remove the Micro:Bit and repeat steps 7 and 8 for the second Micro:Bit

Now you are ready to play. See Game Play for instructions on how to play.

## Game Play
Computer vs Friend
Rock / Paper / Scissors
In the 2 Player mode, you will be prompted to Wait until your friend has made their selection
Results displayed


| Order | What is displayed | What this means                                                       | User Interaction                                                             |
|-------| ------------------|-----------------------------------------------------------------------|------------------------------------------------------------------------------|
| 1.    | `C` or `F`        | Your competitor: Play against the computer or a Friend                | Switch between the two using the left and right buttons. Shake to confirm.   |
| 2.    | `R` or `P` or `S` | Your item selection: Rock, Paper or Scissors                          | Switch item selection by using the left and right buttons. Shake to confirm. |
| 3.    | `Wait...`         | (2 Player only) Wait for your friend to select their item.            | None.                                                                        |
| 4.    | `W` or `L` or `D` | The game results: Win, Lose or Draw                                   | None.                                                                        |

Use the `rest` button to play a new game.

## Technical Details
### Class Breakdown
![Class Diagram](https://gitlab.uwe.ac.uk/p3-goddard/ufcfvk-15-2-iot-challenge-1/*****/class_diagram.png)

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
Inherites Player.


#### MyPlayer

#### Interface


`u_int8_t`
`int16_t`

not using uBit as a whole, but the individual elements

## References

Lancaster University (2018) micro:bit runtime. Available from: https://lancaster-university.github.io/microbit-docs/ [Accessed 28 January 2019].

Atencio, CP / Micro:bit Educational Foundation (2018) Tight loop checking gestures does not recognise shake. Available from: https://github.com/lancaster-university/microbit-dal/issues/372 [Accessed 02 February 2019].
