/**
@file screen.h
@version 1.0
@date 21-12-2016
@author Alejandro Sanchez

@brief
Contains the declaration of the functions asociated to the screen data type.

@version
Dec. 7, 2016 Version 1.0 (initial release)
@version
Dec. 10, 2016 Version 1.1
  Added window_add_text.
*/

#ifndef SCREEN_H
#define SCREEN_H

#include "window.h"

/**
@def Constant values description.
*/
#define MAX_WIN 5

/**
@brief screen structure
Stores the windows shown while executing the program.
*/
typedef struct _Screen Screen;


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
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ screen_destroy(Screen *scr);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_refresh
Refreshes a screen.

@param Screen *scr: Pointer to the screen we want to refresh.
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ screen_refresh(Screen *scr);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_print
Prints a screen.

@param Screen *scr: Pointer to the screen we want to print.
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ screen_print(Screen *scr);

/**
@author Adrián Fernández

@brief screen_add_window
Adds a window to a screen.

@param Screen *scr: Pointer to the screen selected.
@param Window *win: Pointer to the window we want to add.
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ screen_add_window(Screen *scr, Window *win);

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Deletes the last window of a screen.

@param Screen *scr: Pointer to the screen selected.
@return STATUS_: OK if success or ERROR otherwise.
*/
STATUS_ screen_del_window(Screen *scr);

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


#endif
