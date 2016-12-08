/**
@file graphicengine.c
@version 1.0
@date 07-12-2016
@author Adrián Fernández

@brief
Contains the declaration of the functions asociated to the screen data type.

@version
  Dec. 7, 2016 Version 1.0 (initial release)
*/

#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include <ncurses.h>
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
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_destroy(Screen *scr);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_refresh
Refreshes a screen.

@param Screen *scr: Pointer to the screen we want to refresh.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_refresh(Screen *scr);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_print
Prints a screen.

@param Screen *scr: Pointer to the screen we want to print.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_print(Screen *scr);

/**
@author Adrián Fernández

@brief screen_add_window
Adds a window to a screen.

@param Screen *scr: Pointer to the screen selected.
@param Window *win: Pointer to the window we want to add.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_add_window(Screen *scr, Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Deletes the last window of a screen.

@param Screen *scr: Pointer to the screen selected.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_del_window(Screen *scr);

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
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS window_destroy(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_refresh
Refreshes a window.

@param Window *win: Pointer to the window selected.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS window_refresh(Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_print
Prints a window.

@param Window *win: Pointer to the window selected.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS window_print(Window *);

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

@brief window_get_hight
Gets the nrows field of a window.

@param Window *win: Pointer to the window selected.
@return int: nrows of the window.
*/
int window_get_hight(Window *win);

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
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS window_set_text(Window *win, char *text);

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

@brief screen_getch
Gets the input of a user in a window.

@param Window *win: Pointer to the window selected.
@param char *input: String in which the input is stored.
@return char *: Input of the user.
*/
char * screen_get_input(Window *win, char *input);

#endif
