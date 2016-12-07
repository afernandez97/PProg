/**
@file graphicengine.c
@version 1.0
@date 07-12-2016
@author Adrián Fernández

@brief
Contains the implementation of the functions asociated to the screen data type.

@version
  Dec. 7, 2016 Version 1.0 (initial release)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "graphicengine.h"

/**
@def Constant values description.
*/
#define win(X) (X)->win
#define window(X) (X)->window
#define nrows(X) (X)->nrows
#define ncols(X) (X)->ncols
#define begin_y(X) (X)->begin_y
#define begin_x(X) (X)->begin_x
#define text(X) (X)->text

/**
@brief screen structure
Stores the windows shown while executing the program.
*/
struct _Screen{
	Window *win[MAX_WIN];
};

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

/*!< Implementation of screen's functions */

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_create
Creates a new screen.

@param
@return Screen *: Pointer to the screen created.
*/
Screen * screen_create(){
	Screen *scr = NULL;
  Window *win = NULL;
	int max_y, max_x, begin_y, begin_x, ncols, nrows;

	scr = (Screen *)malloc(sizeof(Screen));
	if(!scr){
  	return NULL;
	}

  initscr();
  getmaxyx(stdscr, max_y, max_x);

  nrows = (int) (max_y * (7.0/8.0));
  ncols = (int) (max_x * (1.0/2.0));
  begin_y = 0;
  begin_x = 0;
  win = window_create(int nrows, int ncols, int begin_y, int begin_x);
  if (screen_add_window(scr,  win) == ERROR){
    return NULL;
  }

  nrows = max_y - (int) (max_y * (7.0/8.0));
  ncols = (int) (max_x * (1.0/2.0));	
  begin_y = (int) (max_y * (7.0/8.0));
  begin_x = 0;
  win = window_create(int nrows, int ncols, int begin_y, int begin_x);
  if (screen_add_window(scr,  win) == ERROR){
    return NULL;
  }

  nrows = max_y - (int) (max_y * (7.0/8.0));
  ncols = (int) (max_x * (1.0/4.0));
  begin_y = 0;
  begin_x = (int) (max_x * (1.0/2.0)) - (int) (max_x * (1.0/4.0));
  win = window_create(int nrows, int ncols, int begin_y, int begin_x);
  if (window_set_text(win, "prompt> ") == ERROR){
    return NULL;
  }
  if (screen_add_window(scr,  win) == ERROR){
    return NULL;
  }

  nrows = (int) (max_y * (1.0/4.0));
  ncols = max_x - ((int) (max_x * (1.0/2.0)));
  begin_y = 0;
  begin_x = (int) (max_x * (1.0/2.0));
  win = window_create(int nrows, int ncols, int begin_y, int begin_x);
  if (screen_add_window(scr,  win) == ERROR){
    return NULL;
  }

  nrows = max_y - (int) (max_y * (1.0/4.0));
  ncols = max_x - ((int) (max_x * (1.0/2.0)));
  begin_y = (int) (max_y * (1.0/4.0));
  begin_x = (int) (max_x * (1.0/2.0));
  win = window_create(int nrows, int ncols, int begin_y, int begin_x);
  if (screen_add_window(scr,  win) == ERROR){
    return NULL;
  }

	return scr;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_destroy
Destroys a screen.

@param Screen *scr: Pointer to the screen we want to destroy.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_destroy(Screen *scr){
	int i;

	if(!scr){
  	return ERROR;
	}

	for(i=0; i<MAX_WIN; i++){
  	if(win(scr)[i] != NULL){
    		window_destroy(win(scr)[i]);
  	}
	}

	free(scr);

	endwin();

	return OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_refresh
Refreshes a screen.

@param Screen *scr: Pointer to the screen we want to refresh.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_refresh(Screen *scr){
	int i;

	if(!scr){
  	return ERROR;
	}

  refresh();

	for(i=0; i<MAX_WIN && win(scr)[i] != NULL; i++){
  	window_refresh(win(scr)[i]);
	}
	
  return OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_print
Prints a screen.

@param Screen *scr: Pointer to the screen we want to print.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_print(Screen *scr){
  int i;

  if(!scr){
    return ERROR;
  }

  for(i=0; i<MAX_WIN && win(scr)[i] != NULL; i++){
    window_print(win(scr)[i]);
  }

  return OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_getch
Shows the prompt in a screen.

@param Screen *scr: Pointer to the screen selected.
@return char *: Input of the user.
*/
char * screen_getch(Screen *scr){
	int buff;

  if(!scr){
  	return NULL;
	}

	buff = getch();

  switch(buff){
    case KEY_UP:
      return "go north";
      break;
    case KEY_DOWN:
      return "go south";
      break;
    /* --------CONTINUAR-------- */
    default:
      return "unknown";
  }

	return NULL;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Adds a window to a screen.

@param Screen *scr: Pointer to the screen selected.
@param Window *win: Pointer to the window we want to add.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_add_window(Screen *scr, Window *win){
	int i = 0;

	if(!scr || !win){
  	return ERROR;
	}

	while(i<MAX_WIN && win(scr)[i] != NULL){
  	i++;
	}

	if(i == MAX_WIN){
  	return ERROR;
	}

	win(scr)[i] = win;

  	return OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Deletes the last window of a screen.

@param Screen *scr: Pointer to the screen selected.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS screen_del_window(Screen *scr){
	int i = 0;

	if(!scr){
  	return ERROR;
	}

	while(i<MAX_WIN && win(scr)[i] != NULL){
  	i++;
	}

	if(i == MAX_WIN){
  	return ERROR;
	}

	window_destroy(win(scr)[i-1]);

  return OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Gets the window in a selected position of a screen.

@param Screen *scr: Pointer to the screen selected.
@param int n: Position selected.
@return Window *: Window found in the position selected or NULL if not found.
*/
Window * screen_get_window(Screen *scr, int n){
	if(!scr){
  	return NULL;
	}	

	return win(scr)[n];
}


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

	win = (Window *)malloc(sizeof(Window));
	if(win == NULL){
		return NULL;
	}

	window(win) = newwin(nrows, ncols, begin_y, begin_x);
  if(window(win) == NULL){
    return NULL;
  }

	text(win) = "";

  box(window(win), 0, 0);

	return win;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_destroy
Destroys a window.

@param Window *win: Pointer to the window selected.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS window_destroy(Window *win){
	if(!win){
		return ERROR;
	}

	delwin(window(win));
	free(win);

	return OK;
}


/**
@author Adrián Fernández
@date 07-12-2016

@brief window_refresh
Refreshes a window.

@param Window *win: Pointer to the window selected.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS window_refresh(Window *win){
	if(!win){
		return ERROR;
	}

	wrefresh(window(win));

	return OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_print
Prints a window.

@param Window *win: Pointer to the window selected.
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS window_print(Window *win){
	if(!win || !window_get_text(win)){
		return ERROR;
	}

	wprintw(window(win), "%s", text(win));

	return OK;
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

@brief window_get_hight
Gets the nrows field of a window.

@param Window *win: Pointer to the window selected.
@return int: nrows of the window.
*/
int window_get_hight(Window *win){
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
@return STATUS: OK if success or ERROR otherwise.
*/
STATUS window_set_text(Window *win, char *text){
	if(!win || !text){
		return ERROR;
	}

	if(!strcpy(text(win), text)){
		return ERROR;
	}

	return OK;
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
