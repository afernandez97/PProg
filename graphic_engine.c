/**
@file graphic_engine.c
@version 1.1
@date 12-12-2016
@author Adrián Fernández

@brief
Contains the implementation of the functions asociated to the screen data type.

@version
Dec. 7, 2016 Version 1.0 (initial release)
@version
Dec. 10, 2016 Version 1.1
  Added window_add_text.
*/

#include "graphic_engine.h"

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
	start_color();
	getmaxyx(stdscr, max_y, max_x);

	/*Window 0*/
	nrows = (int) (max_y * (1.0/8.0));
	ncols = (int) (max_x * (1.0/2.0));
	begin_y = 0;
	begin_x = 0;
	win = window_create(nrows, ncols, begin_y, begin_x);
	
	if (screen_add_window(scr,  win) == _ERROR){
		return NULL;
	}

	/*Window 1*/
  nrows = (int) (max_y * (6.0/8.0));
  ncols = (int) (max_x * (1.0/2.0));
  begin_y = (int) (max_y * (1.0/8.0));
	begin_x = 0;
  win = window_create(nrows, ncols, begin_y, begin_x);
  if (screen_add_window(scr,  win) == _ERROR){
  	return NULL;
  }

	/*Window 2*/
	nrows = (int) (max_y * (1.0/8.0));
	ncols = (int) (max_x * (1.0/2.0));	
	begin_y = (int) (max_y * (7.0/8.0));
	begin_x = 0;
	win = window_create(nrows, ncols, begin_y, begin_x);
	if (screen_add_window(scr,  win) == _ERROR){
		return NULL;
	}

	/*Window 3*/
	nrows = (int) (max_y * (1.0/4.0));
	ncols = (int) (max_x * (1.0/2.0));
	begin_y = 0;
	begin_x = (int) (max_x * (1.0/2.0));
	win = window_create(nrows, ncols, begin_y, begin_x);
	if (screen_add_window(scr,  win) == _ERROR){
		return NULL;
	}

	/*Window 4*/
	nrows = (int) (max_y * (3.0/4.0));
	ncols = (int) (max_x * (1.0/2.0));
	begin_y = (int) (max_y * (1.0/4.0));
	begin_x = (int) (max_x * (1.0/2.0));
	win = window_create(nrows, ncols, begin_y, begin_x);
	if (screen_add_window(scr,  win) == _ERROR){
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
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_destroy(Screen *scr){
	int i;

	if(!scr){
  	return _ERROR;
	}

	for(i=0; i<MAX_WIN; i++){
  	if(win(scr)[i] != NULL){
    	window_destroy(win(scr)[i]);
  	}
	}

	free(scr);

	endwin();

	return _OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_refresh
Refreshes a screen.

@param Screen *scr: Pointer to the screen we want to refresh.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_refresh(Screen *scr){
	int i;

	if(!scr){
  	return _ERROR;
	}

  refresh();

	for(i=0; i<MAX_WIN && win(scr)[i] != NULL; i++){
  	window_refresh(win(scr)[i]);
	}
	
	return _OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_print
Prints a screen.

@param Screen *scr: Pointer to the screen we want to print.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_print(Screen *scr){
	int i;

	if(!scr){
		return _ERROR;
	}

	for(i=0; i<MAX_WIN && win(scr)[i] != NULL; i++){
		window_print(win(scr)[i]);
	}

	return _OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Adds a window to a screen.

@param Screen *scr: Pointer to the screen selected.
@param Window *win: Pointer to the window we want to add.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_add_window(Screen *scr, Window *win){
	int i = 0;

	if(!scr || !win){
  	return _ERROR;
	}

	while(i<MAX_WIN && win(scr)[i] != NULL){
  	i++;
	}

	if(i == MAX_WIN){
  	return _ERROR;
	}

	win(scr)[i] = win;

  return _OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_add_window
Deletes the last window of a screen.

@param Screen *scr: Pointer to the screen selected.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS screen_del_window(Screen *scr){
	int i = 0;

	if(!scr){
  	return _ERROR;
	}

	while(i<MAX_WIN && win(scr)[i] != NULL){
  	i++;
	}

	if(i == MAX_WIN){
  	return _ERROR;
	}

	window_destroy(win(scr)[i-1]);

  return _OK;
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
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_destroy(Window *win){
	if(!win){
		return _ERROR;
	}

	delwin(window(win));
	free(win);

	return _OK;
}


/**
@author Adrián Fernández
@date 07-12-2016

@brief window_refresh
Refreshes a window.

@param Window *win: Pointer to the window selected.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_refresh(Window *win){
	if(!win){
		return _ERROR;
	}

	box(window(win), 0, 0);

	wrefresh(window(win));

	return _OK;
}

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_print
Prints a window.

@param Window *win: Pointer to the window selected.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_print(Window *win){
	if(!win || !window_get_text(win)){
		return _ERROR;
	}

	wclear(window(win));
	
	mvwprintw(window(win), 1, 1, "%s", text(win));

	return _OK;
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
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_set_text(Window *win, char *text){
	if(!win || !text){
		return _ERROR;
	}

	if(!strcpy(text(win), text)){
		return _ERROR;
	}

	return _OK;
}

/**
@author Adrián Fernández
@date 10-12-2016

@brief window_add_text
Adds a string to the text field of a window.

@param Window *win: Pointer to the window selected.
@param char *: The text we want to add.
@return _STATUS: OK if success or ERROR otherwise.
*/
_STATUS window_add_text(Window *win, char *text){
  if(!win || !text){
    return ERROR;
  }

  if(!strcat(text(win), text)){
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

/**
@author Adrián Fernández
@date 07-12-2016

@brief window_get_input
Gets the input of a user in a window.

@param Window *win: Pointer to the window selected.
@param char *input: String in which the input is stored.
@return _STATUS: OK if success and ERROR otherwise.
*/
_STATUS window_get_input(Window *win, char *input){
  if(win == NULL || input == NULL){
    return _ERROR;
  }

  if(window_set_text(win, "prompt:> ") == _ERROR){
    return _ERROR;
  }

  if(window_print(win) == _ERROR){
    return _ERROR;
  }

  if(window_refresh(win) == _ERROR){
    return _ERROR;
  }

  if(!wgetnstr(window(win), input, CMD_LENGTH)){
	return _ERROR;
  }

	return _OK;
}

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
void game_print_objects(Game *game, Space *space, char *output){
  int i, count;
  char *name = NULL;
  Set *set = NULL;
  Object *object = NULL;
  char aux[WORD_SIZE] = "";

  if(game == NULL || space == NULL || output == NULL){
    return
  }

  /*Deletes the content of output*/
  if(!strcpy(gdesc, gdesc(space))){
    return;
  }
  /* Start printing the row of the space */
  sprintf(aux, "|");
  strcat(output, aux);

  /* Get the set of objects on the space and how many are there */
  set = space_get_object(space);
  count = set_get_count(set);
  /* Get the different names of the objects and print them */
  for(i=0; i<count; i++){    
    object = game_get_object(game, set_get_object_at_position(set, i));
    name = object_get_name(object);
    /* Maximum three objects per space */   
    if(i < 3){             
      sprintf(aux, "%s ", name);
      strcat(output, aux);
    }
  }

  /* Print the rest of the row. The way depends on the number of objects */
  switch(i){
    /* 0 objects */
    case 0:
       sprintf(aux, "           |");
       strcat(output, aux);
       break;
    /* 1 object */
    case 1:
       sprintf(aux, "        |");
       strcat(output, aux);
       break;
    /* 2 objects */
    case 2:
       sprintf(aux, "     |");
       strcat(output, aux);
       break;
    /* 3 objects */
    case 3:
       sprintf(aux, "  |");
       strcat(output, aux);
       break; 
    /* More than 3 objects */
    default:
       sprintf(aux, "..|");
       strcat(output, aux);
       break;
  }

  return; 
}

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
void game_print_screen(Game *game, char *input, int player){
  Id id_act = NO_ID, id_north = NO_ID, id_south = NO_ID, id_east = NO_ID, id_west = NO_ID;
  Id id_obj = NO_ID;

  Space *space_act = NULL, *space_north = NULL, *space_south = NULL, *space_east = NULL, *space_west = NULL;
  Link *link_north = NULL, *link_south = NULL, *link_east = NULL, *link_west = NULL;
  Object *object = NULL;
  Inventory *inv = NULL; 

  Screen *scr = NULL;
  Window *win = NULL;

  char *name = NULL;
  char aux[WORD_SIZE] = "";
  
  int i, count;

    
  if(!game){ /* Check that the input is not empty */
    return;
  }  

  /* Get actual location of the player */
  id_act = game_get_player_location(game, player);  
  if(id_act == NO_ID){  /* Check if it has worked */
    return;
  }
  
  /* Get the space where the player is */  
  space_act = game_get_space(game, id_act);

  /* Get the north space */
  id_north = space_get_north(space_act);
  if(id_north != NO_ID){
    link_north = game_get_link(game, id_north);
    id_north = link_get_space2(link_north);
    space_north = game_get_space(game, id_north);
  }
 

  /* Get the south space */
  id_south = space_get_south(space_act);
  if(id_south != NO_ID){
    link_south = game_get_link(game, id_south);
    id_south = link_get_space2(link_south);
    space_south = game_get_space(game, id_south); 
  }


  /* Get the east space */
  id_east = space_get_east(space_act);
  if(id_east != NO_ID){
    link_east = game_get_link(game, id_east);
    id_east = link_get_space2(link_east);
    space_east = game_get_space(game, id_east); 
  }


  /* Get the west space */
  id_west = space_get_west(space_act);
  if(id_west != NO_ID){
    link_west = game_get_link(game, id_west);
    id_west = link_get_space2(link_west);
    space_west = game_get_space(game, id_west); 
  }  

  
  /*Window 0*/
  win = screen_get_window(scr, 0);
  /*Print the last die value*/
  sprintf(aux, "Last die value: %d\t%.2lf", die_get_value(die(game)), player_get_money(game_get_player_at_position(game, player)));
  window_set_text(win, aux);

  /*Window 1*/
  win = screen_get_window(scr, 1);

  /* Print the previous space if it is different from NO_ID */
  if(id_north != NO_ID){
    sprintf(aux, "              |         %2d|\n", (int) id_north);
    window_add_text(win, aux);

    /*Person in space*/
		sprintf(aux, "              |  ");
    window_add_text(win, aux);
    if(space_get_person(space_north) != NO_ID){
      sprintf(aux, "o");
    } else {
      sprintf(aux, " ");
    }
    window_add_text(win, aux);
    sprintf(aux, "        |\n");
    window_add_text(win, aux);

    /*Gdesc*/
    sprintf(aux, "              ");
    window_add_text(win, aux);
    space_print_gdesc1(space_north, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    sprintf(aux, "              ");
    window_add_text(win, aux);
    space_print_gdesc2(space_north, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    sprintf(aux, "              ");
    window_add_text(win, aux);
    space_print_gdesc3(space_north, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    /*Objects*/
    sprintf(aux, "              ");
    window_add_text(win, aux);
		game_print_objects(game, space_north, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

		sprintf(aux, "              +-----------+\n");
    window_add_text(win, aux);
		sprintf(aux, "                     ^\n");
    window_add_text(win, aux);
  }
  
  /* Print the actual space if it is different from NO_ID */
  if(id_act != NO_ID){

    if(id_west != NO_ID){
      if(id_east != NO_ID){
        sprintf(aux, "+-----------+  +-----------+ +-----------+\n");
        window_add_text(win, aux);
        sprintf(aux, "|         %2d| | >8D     %2d| |         %2d|\n", (int)id_west, (int)id_act, (int)id_east);
        window_add_text(win, aux);

        /*Person in the space*/
        sprintf(aux, "|           |<|  ");
        window_add_text(win, aux);
        if(space_get_person(space_south) != NO_ID){
          sprintf(aux, "o");
        } else {
          sprintf(aux, " ");
        }
        sprintf(aux, "        |>|           |\n");
        window_add_text(win, aux);

        /*Gdesc*/
        space_print_gdesc1(space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);
        space_print_gdesc1(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);
        space_print_gdesc1(space_east, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        space_print_gdesc2(space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);
        space_print_gdesc2(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);
        space_print_gdesc2(space_east, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);
        
        space_print_gdesc3(space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);
        space_print_gdesc3(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);
        space_print_gdesc3(space_east, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        /*Objects*/
        game_print_objects(game, space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);

        game_print_objects(game, space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);

        game_print_objects(game, space_east, aux);
        window_add_text(win, aux);
        sprintf(aux,"\n");
        window_add_text(win, aux);

        sprintf(aux, "+-----------+  +-----------+ +-----------+\n");
        window_add_text(win, aux);
      } else {
        sprintf(aux, "+-----------+  +-----------+\n");
        window_add_text(win, aux);
        sprintf(aux, "|         %2d| | >8D     %2d|\n", (int)id_west, (int)id_act);
        window_add_text(win, aux);

        /*Person in the space*/
        sprintf(aux, "|           |<|  ");
        window_add_text(win, aux);
        if(space_get_person(space_south) != NO_ID){
          sprintf(aux, "o");
        } else {
          sprintf(aux, " ");
        }
        sprintf(aux, "        |\n");
        window_add_text(win, aux);

        /*Gdesc*/
        space_print_gdesc1(space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);
        space_print_gdesc1(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        space_print_gdesc2(space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);
        space_print_gdesc2(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);
        
        space_print_gdesc3(space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);
        space_print_gdesc3(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        /*Objects*/
        game_print_objects(game, space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, " ");
        window_add_text(win, aux);

        game_print_objects(game, space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        sprintf(aux, "+-----------+  +-----------+\n");
        window_add_text(win, aux);  
      }    
    } else if (id_east != NO_ID) {
      sprintf(aux, "              +-----------+ +-----------+\n");
      window_add_text(win, aux);
      sprintf(aux, "              | >8D     %2d| |         %2d|\n", (int)id_act, (int)id_east);
      window_add_text(win, aux);

      /*Person in the space*/
      sprintf(aux, "              |  ");
      window_add_text(win, aux);
      if(space_get_person(space_south) != NO_ID){
        sprintf(aux, "o");
      } else {
        sprintf(aux, " ");
      }
      sprintf(aux, "        |>|           |\n");
      window_add_text(win, aux);

      /*Gdesc*/
      sprintf(aux, "              ");
      window_add_text(win, aux);
      space_print_gdesc1(space_act, aux);
      window_add_text(win, aux);
      sprintf(aux, " ");
      window_add_text(win, aux);
      space_print_gdesc1(space_east, aux);
      window_add_text(win, aux);
      sprintf(aux, "\n");
      window_add_text(win, aux);

      sprintf(aux, "              ");
      window_add_text(win, aux);
      space_print_gdesc2(space_act, aux);
      window_add_text(win, aux);
      sprintf(aux, " ");
      window_add_text(win, aux);
      space_print_gdesc2(space_east, aux);
      window_add_text(win, aux);
      sprintf(aux, "\n");
      window_add_text(win, aux);
      
      sprintf(aux, "              ");
      window_add_text(win, aux);
      space_print_gdesc3(space_act, aux);
      window_add_text(win, aux);
      sprintf(aux, " ");
      window_add_text(win, aux);
      space_print_gdesc3(space_east, aux);
      window_add_text(win, aux);
      sprintf(aux, "\n");
      window_add_text(win, aux);

      /*Objects*/
      sprintf(aux, "              ");
      window_add_text(win, aux);
      game_print_objects(game, space_act, aux);
      window_add_text(win, aux);
      sprintf(aux, " ");
      window_add_text(win, aux);

      game_print_objects(game, space_east, aux);
      window_add_text(win, aux);
      sprintf(aux,"\n");
      window_add_text(win, aux);

      sprintf(aux, "              +-----------+ +-----------+\n");
      window_add_text(win, aux);      
    } else {
      sprintf(aux, "              +-----------+\n");
      window_add_text(win, aux);
      sprintf(aux, "              | >8D     %2d|\n", (int)id_act);
      window_add_text(win, aux);

      /*Person in the space*/
      sprintf(aux, "              |  ");
      window_add_text(win, aux);
      if(space_get_person(space_south) != NO_ID){
        sprintf(aux, "o");
      } else {
        sprintf(aux, " ");
      }
      sprintf(aux, "        |\n");
      window_add_text(win, aux);

      /*Gdesc*/
      sprintf(aux, "              ");
      window_add_text(win, aux);
      space_print_gdesc1(space_act, aux);
      window_add_text(win, aux);
      sprintf(aux, "\n");
      window_add_text(win, aux);

      sprintf(aux, "              ");
      window_add_text(win, aux);
      space_print_gdesc2(space_act, aux);
      window_add_text(win, aux);
      sprintf(aux, "\n");
      window_add_text(win, aux);
      
      sprintf(aux, "              ");
      window_add_text(win, aux);
      space_print_gdesc3(space_act, aux);
      window_add_text(win, aux);
      sprintf(aux, "\n");
      window_add_text(win, aux);

      /*Objects*/
      sprintf(aux, "              ");
      window_add_text(win, aux);
      game_print_objects(game, space_act, aux);
      window_add_text(win, aux);
      sprintf(aux,"\n");
      window_add_text(win, aux);

      sprintf(aux, "              +-----------+\n");
      window_add_text(win, aux);      
    }
  }  
    
  /* Print the next space if it is different from NO_ID */ 
  if(id_south != NO_ID){
    sprintf(aux, "                    v");
    window_add_text(win, aux);
    sprintf(aux, "              +-----------+\n");
    window_add_text(win, aux);
    sprintf(aux, "              |         %2d|\n", (int) id_south);
    window_add_text(win, aux);

    /*Person in the space*/
		sprintf(aux, "              |  ");
    window_add_text(win, aux);
    if(space_get_person(space_south) != NO_ID){
      sprintf(aux, "o");
    } else {
      sprintf(aux, " ");
    }
    window_add_text(win, aux);
    sprintf(aux,"        |\n");
    window_add_text(win, aux);

		/*Gdesc*/
    sprintf(aux, "              ");
    window_add_text(win, aux);
    space_print_gdesc1(space_south, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    sprintf(aux, "              ");
    window_add_text(win, aux);
    space_print_gdesc2(space_south, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    sprintf(aux, "              ");
    window_add_text(win, aux);
    space_print_gdesc3(space_south, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    /*Objects*/
    sprintf(aux,"        ");
    window_add_text(win, aux);
    game_print_objects(game, space_south, aux);
    window_add_text(win, aux);
    sprintf(aux,"\n");
    window_add_text(win, aux);
    
  }

  
  /*Window 2*/
  win = screen_get_window(scr, 2);
  window_set_text(win, "prompt:> ");
  scr = game_get_screen(game);

  /*Window 3*/
  win = screen_get_window(scr, 3);
  /* Print the objects of the game*/  
  inv = player_get_inventory(players(game)[0]);
  count = inventory_get_count(inv);
  sprintf(aux, "Player objects: ");
  window_add_text(win, aux);
  /* Get the different names of the objects and print them */
	for(i=0; i<count; i++){    
	  object = game_get_object(game, set_get_object_at_position(inventory_get_bag(inv), i));
    name = object_get_name(object);
    sprintf(aux, "%s ",name);
    window_add_text(win, aux);
  }

  /*Window 4*/
  win = screen_get_window(scr, 4);
  /*Print the text*/
  window_set_text(win, game_get_text(game));

  

  /*Prints all the windows*/
  for(i = 0; i < MAX_WIN; i++){
    win = screen_get_window(scr, i);
    window_print(win);
  }
  screen_refresh(scr);

  /*Gets the input of the player in the window number 1*/
  win = screen_get_window(scr, 1);
  input = window_get_input(win);

  return;
}
