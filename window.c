/**
@file window.c
@version 1.0
@date 21-12-2016
@author Alejandro Sanchez

@brief
Contains the implementation of the functions asociated to the window data type.

@version
Dec. 21, 2016 Version 1.0 (initial release)
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "window.h"

/**
@def Constant values description.
*/
#define window(X) (X)->window
#define nrows(X) (X)->nrows
#define ncols(X) (X)->ncols
#define begin_y(X) (X)->begin_y
#define begin_x(X) (X)->begin_x
#define text(X) (X)->text

/**
@brief window structure
Stores a pointer to a window, it's size, position and text.
*/
struct _Window{
  WINDOW *window;
  int nrows;
  int ncols;
  int begin_y;
  int begin_x;
  char text[WORD_SIZE];
};

/*!< Implementation of window's functions */


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
Window * window_create(int nrows, int ncols, int begin_y, int begin_x){
	Window *win = NULL;

	if(nrows < 0 || ncols < 0 || begin_y < 0 || begin_x < 0){
		return NULL;
	}

	win = (Window *)malloc(sizeof(Window));
	if(win == NULL){
		return NULL;
	}

	window(win) = newwin(nrows, ncols, begin_y, begin_x);
  	if(window(win) == NULL){
    	free(win);
  		return NULL;
  	}

	strcpy(text(win), "");

	/*Defining colors and shape of the window*/
  	box(window(win), 0, 0);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	wbkgd(window(win), COLOR_PAIR(1));

	return win;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_destroy
Destroys a window.

@param Window *win: Pointer to the window selected.
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ window_destroy(Window *win){
	if(!win){
		return ERROR_;
	}

	delwin(window(win));
	free(win);

	return OK_;
}


/**
@author Adrián Fernández
@date 07-12-2016

@brief window_refresh
Refreshes a window.

@param Window *win: Pointer to the window selected.
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ window_refresh(Window *win){
	if(!win){
		return ERROR_;
	}

	box(window(win), 0, 0);

	wrefresh(window(win));

	return OK_;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_print
Prints a window.

@param Window *win: Pointer to the window selected.
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ window_print(Window *win){
	if(!win || !window_get_text(win)){
		return ERROR_;
	}

	wclear(window(win));
	
	mvwprintw(window(win), 1, 0, "%s", text(win));

	return OK_;
}

/**
@author Alejandro Sanchez
@date 21-12-2016

@brief window_get_window
Gets the window of ncurses field of a window.

@param Window *win: Pointer to the window selected.
@return WINDOW *: window of ncurses of the window.
*/
WINDOW * window_get_window(Window *win){
	if(!win){
		return NULL;
	}

	return window(win);
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_input
Gets the input of a user in a window.

@param Window *win: Pointer to the window selected.
@param char *input: String in which the input is stored.
@return STATUS_: OK_ if success and ERROR_ otherwise.
*/
STATUS_ window_get_input(Window *win, char *input){
  if(win == NULL || input == NULL){
    return ERROR_;
  }

  if(window_set_text(win, " prompt:> ") == ERROR_){
    return ERROR_;
  }

  if(window_print(win) == ERROR_){
    return ERROR_;
  }

  if(window_refresh(win) == ERROR_){
    return ERROR_;
  }

  if(!wgetnstr(window(win), input, CMD_LENGTH)){
  	return ERROR_;
  }

  return OK_;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_x
Gets the begin_x field of a window.

@param Window *win: Pointer to the window selected.
@return int: begin_x of the window.
*/
int window_get_x(Window *win){
	if(!win){
		return -1;
	}

	return begin_x(win);
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_y
Gets the begin_y field of a window.

@param Window *win: Pointer to the window selected.
@return int: begin_y of the window.
*/
int window_get_y(Window *win){
	if(!win){
		return -1;
	}

	return begin_y(win);
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_height
Gets the nrows field of a window.

@param Window *win: Pointer to the window selected.
@return int: nrows of the window.
*/
int window_get_height(Window *win){
	if(!win){
		return -1;
	}

	return nrows(win);
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_weight
Gets the ncols field of a window.

@param Window *win: Pointer to the window selected.
@return int: ncols of the window.
*/
int window_get_weight(Window *win){
	if(!win){
		return -1;
	}

	return ncols(win);
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_set_text
Sets the text field of a window.

@param Window *win: Pointer to the window selected.
@param char *: The text we want to set.
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ window_set_text(Window *win, char *text){
	if(!win || !text){
		return ERROR_;
	}

	if(!strcpy(text(win), text)){
		return ERROR_;
	}

	return OK_;
}

/**
@author Adrián Fernández
@date 10-12-2016

@brief window_add_text
Adds a string to the text field of a window.

@param Window *win: Pointer to the window selected.
@param char *: The text we want to add.
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ window_add_text(Window *win, char *text){
  if(!win || !text){
    return ERROR_;
  }

  if(!strcat(text(win), text)){
    return ERROR_;
  }

  return OK_;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_text
Gets the text field of a window.

@param Window *win: Pointer to the window selected.
@return char *: text of the window.
*/
char * window_get_text(Window *win){
	if(!win){
		return NULL;
	}

	return text(win);
}



