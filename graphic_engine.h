/**
@file graphic_engine.h
@version 1.1
@date 12-12-2016
@author Adrián Fernández

@brief
Contains the declaration of the functions asociated to the screen data type.

@version
Dec. 7, 2016 Version 1.0 (initial release)
@version
Dec. 10, 2016 Version 1.1
  Added window_add_text.
*/

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "screen.h"
#include "game.h"



/**
@date 02-11-2016 
@author Adrián Fernández

@brief game_print_objects
Stores the objects of the game in a string (output).

@param Game *game: the game to print its objects.
@param Space *space: the space where you want to print the objects.
@param char *output: string modified to show the objects.

@return
*/
void game_print_objects(Game *game, Space *space, char *output);

/**
@date 12-12-2016 
@author Adrian Fernández

@brief game_print_screen
Prints the screen of the game.

@param Game *game: the game to print its screen.
@param int player: integer that indicates the player.

@return
*/
void game_print_screen(Game *game, int player);

#endif
