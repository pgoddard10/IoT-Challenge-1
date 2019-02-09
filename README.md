# Challenge 1 - UFCFVK-15-2 - Internet of Things

## Introduction

## Task Specification

## Game Play

## Technical Details

### Class Breakdown

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

(Use UWE Harvard)
- https://lancaster-university.github.io/microbit-docs/
- https://github.com/lancaster-university/microbit-dal/issues/372
