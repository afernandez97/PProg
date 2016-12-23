/**
@file window.h
@version 1.0
@date 21-12-2016
@author Alejandro Sanchez

@brief
Contains the declaration of the functions asociated to the window data type.

@version
Dec. 7, 2016 Version 1.0 (initial release)
@version
Dec. 10, 2016 Version 1.1
  Added window_add_text.
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include "types.h"

/**
@def Constant values description 
*/
#define CMD_LENGTH 100

/**
@brief window structure
Stores a pointer to a window, it's size, position and text.
*/
typedef struct _Window Window;


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
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ window_destroy(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_refresh
Refreshes a window.

@param Window *win: Pointer to the window selected.
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ window_refresh(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_print
Prints a window.

@param Window *win: Pointer to the window selected.
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ window_print(Window * win);

/**
@author Alejandro Sanchez
@date 21-12-2016

@brief window_get_window
Gets the window of ncurses field of a window.

@param Window *win: Pointer to the window selected.
@return WINDOW *: window of ncurses of the window.
*/
WINDOW * window_get_window(Window *win);


/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_input
Gets the input of a user in a window.

@param Window *win: Pointer to the window selected.
@param char *input: String in which the input is stored.
@return STATUS_: OK if success and ERROR otherwise.
*/
STATUS_ window_get_input(Window *win, char *input);

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
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ window_set_text(Window *win, char *text);

/**
@author Adrián Fernández
@date 10-12-2016

@brief window_add_text
Adds a string to the text field of a window.

@param Window *win: Pointer to the window selected.
@param char *: The text we want to add.
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ window_add_text(Window *win, char *text);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_text
Gets the text field of a window.

@param Window *win: Pointer to the window selected.
@return char *: text of the window.
*/
char * window_get_text(Window *win);



#endif
