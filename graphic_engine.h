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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "game.h"
#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "link.h"
#include "die.h"
#include "types.h"

/**
@def Constant values description.
*/
#define MAX_WIN 5
#define DIVISIONS 8

/**
@brief screen structure
Stores the windows shown while executing the program.
*/
typedef struct _Screen Screen;
/**
@brief window structure
Stores a pointer to a window, it's size, position and text.
*/
typedef struct _Window Window;


/*!< Declaration of screen's functions */


/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_create
Creates a new screen.

@param
@return Screen *: Pointer to the screen created.
*/
Screen * screen_create();

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_destroy
Destroys a screen.

@param Screen *scr: Pointer to the screen we want to destroy.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_destroy(Screen *scr);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_refresh
Refreshes a screen.

@param Screen *scr: Pointer to the screen we want to refresh.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_refresh(Screen *scr);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_print
Prints a screen.

@param Screen *scr: Pointer to the screen we want to print.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_print(Screen *scr);

/**
@author Adrián Fernández

@brief screen_add_window
Adds a window to a screen.

@param Screen *scr: Pointer to the screen selected.
@param Window *win: Pointer to the window we want to add.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_add_window(Screen *scr, Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Deletes the last window of a screen.

@param Screen *scr: Pointer to the screen selected.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_del_window(Screen *scr);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Gets the window in a selected position of a screen.

@param Screen *scr: Pointer to the screen selected.
@param int n: Position selected.
@return Window *: Window found in the position selected or NULL if not found.
*/
Window * screen_get_window(Screen *scr, int n);


/*!< Declaration of window's functions */


/**
@author Adrián Fernández
@date 07-12-2016

@brief window_create
Creates a window.

@param int nrows: Number of rows desired.
@param int ncols: Number of columns desired.
@param int begin_y: Starting y coordenate.
@param int begin_x: Starting x coordenate.
@return Window *: Pointer to the window created.
*/
Window * window_create(int nrows, int ncols, int begin_y, int begin_x);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_destroy
Destroys a window.

@param Window *win: Pointer to the window selected.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_destroy(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_refresh
Refreshes a window.

@param Window *win: Pointer to the window selected.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_refresh(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_print
Prints a window.

@param Window *win: Pointer to the window selected.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_print(Window * win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_x
Gets the begin_x field of a window.

@param Window *win: Pointer to the window selected.
@return int: begin_x of the window.
*/
int window_get_x(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_y
Gets the begin_y field of a window.

@param Window *win: Pointer to the window selected.
@return int: begin_y of the window.
*/
int window_get_y(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_height
Gets the nrows field of a window.

@param Window *win: Pointer to the window selected.
@return int: nrows of the window.
*/
int window_get_height(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_weight
Gets the ncols field of a window.

@param Window *win: Pointer to the window selected.
@return int: ncols of the window.
*/
int window_get_weight(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_set_text
Sets the text field of a window.

@param Window *win: Pointer to the window selected.
@param char *: The text we want to set.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_set_text(Window *win, char *text);

/**
@author Adrián Fernández
@date 10-12-2016

@brief window_add_text
Adds a string to the text field of a window.

@param Window *win: Pointer to the window selected.
@param char *: The text we want to add.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_add_text(Window *win, char *text);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_text
Gets the text field of a window.

@param Window *win: Pointer to the window selected.
@return char *: text of the window.
*/
char * window_get_text(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_input
Gets the input of a user in a window.

@param Window *win: Pointer to the window selected.
@param char *input: String in which the input is stored.
@return _STATUS: OK if success and ERROR otherwise.
*/
_STATUS window_get_input(Window *win, char *input);

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
Prints the screen of the game and gets an input.

@param Game *game: the game to print its screen.
@param char *input: string containing the input.
@param int player: integer that indicates the player.

@return
*/
void game_print_screen(Game *game, char *input, int player);

#endif
