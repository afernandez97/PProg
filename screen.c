/**
@file screen.c
@version 1.0
@date 21-12-2016
@author Alejandro Sanchez

@brief
Contains the implementation of the functions asociated to the screen data type.

@version
Dec. 21, 2016 Version 1.0 (initial release)
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen.h"

/**
@def Constant values description.
*/
#define win(X) (X)->win

/**
@brief screen structure
Stores the windows shown while executing the program.
*/
struct _Screen{
  Window *win[MAX_WIN];
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
  start_color();
  getmaxyx(stdscr, max_y, max_x);

  /*Window 0*/
  nrows = (int) (max_y * (1.0/8.0));
  ncols = (int) (max_x * (1.0/2.0));
  begin_y = 0;
  begin_x = 0;
  win = window_create(nrows, ncols, begin_y, begin_x);
  
  if (screen_add_window(scr,  win) == ERROR_){
    return NULL;
  }

  /*Window 1*/
  nrows = (int) (max_y * (6.0/8.0));
  ncols = (int) (max_x * (1.0/2.0));
  begin_y = (int) (max_y * (1.0/8.0));
  begin_x = 0;
  win = window_create(nrows, ncols, begin_y, begin_x);
  if (screen_add_window(scr,  win) == ERROR_){
    return NULL;
  }

  /*Window 2*/
  nrows = (int) (max_y * (1.0/8.0));
  ncols = (int) (max_x * (1.0/2.0));  
  begin_y = (int) (max_y * (7.0/8.0));
  begin_x = 0;
  win = window_create(nrows, ncols, begin_y, begin_x);
  if (screen_add_window(scr,  win) == ERROR_){
    return NULL;
  }

  /*Window 3*/
  nrows = (int) (max_y * (1.0/4.0));
  ncols = (int) (max_x * (1.0/2.0));
  begin_y = 0;
  begin_x = (int) (max_x * (1.0/2.0));
  win = window_create(nrows, ncols, begin_y, begin_x);
  if (screen_add_window(scr,  win) == ERROR_){
    return NULL;
  }

  /*Window 4*/
  nrows = (int) (max_y * (3.0/4.0));
  ncols = (int) (max_x * (1.0/2.0));
  begin_y = (int) (max_y * (1.0/4.0));
  begin_x = (int) (max_x * (1.0/2.0));
  win = window_create(nrows, ncols, begin_y, begin_x);
  if (screen_add_window(scr,  win) == ERROR_){
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
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ screen_destroy(Screen *scr){
  int i;

  if(!scr){
    return ERROR_;
  }

  for(i=0; i<MAX_WIN; i++){
    if(win(scr)[i] != NULL){
      screen_del_window(scr);
    }
  }

  free(scr);

  endwin();

  return OK_;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_refresh
Refreshes a screen.

@param Screen *scr: Pointer to the screen we want to refresh.
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ screen_refresh(Screen *scr){
  int i;

  if(!scr){
    return ERROR_;
  }

  refresh();

  for(i=0; i<MAX_WIN && win(scr)[i] != NULL; i++){
    window_refresh(win(scr)[i]);
  }
  
  return OK_;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_print
Prints a screen.

@param Screen *scr: Pointer to the screen we want to print.
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ screen_print(Screen *scr){
  int i;

  if(!scr){
    return ERROR_;
  }

  for(i=0; i<MAX_WIN && win(scr)[i] != NULL; i++){
    window_print(win(scr)[i]);
  }

  return OK_;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Adds a window to a screen.

@param Screen *scr: Pointer to the screen selected.
@param Window *win: Pointer to the window we want to add.
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ screen_add_window(Screen *scr, Window *win){
  int i = 0;

  if(!scr || !win){
    return ERROR_;
  }

  while(i<MAX_WIN && win(scr)[i] != NULL){
    i++;
  }

  if(i == MAX_WIN){
    return ERROR_;
  }

  win(scr)[i] = win;

  return OK_;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Deletes the last window of a screen.

@param Screen *scr: Pointer to the screen selected.
@return STATUS_: OK_ if success or ERROR_ otherwise.
*/
STATUS_ screen_del_window(Screen *scr){
  int i = 0;

  if(!scr){
    return ERROR_;
  }

  while(i<MAX_WIN && win(scr)[i] != NULL){
    i++;
  }

  if(i == MAX_WIN){
    return ERROR_;
  }

  window_destroy(win(scr)[i-1]);

  return OK_;
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

