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
  	getmaxyx(stdscr, &max_y, &max_x);

  	nrows = (int) (max_y * (6.0/8.0));
  	ncols = (int) (max_x * (1.0/2.0));
  	begin_y = (int) (max_y * (1.0/8.0));
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
	if (window_set_text(win, "prompt> ") == ERROR){
		return NULL;
	}
	if (screen_add_window(scr,  win) == ERROR){
		return NULL;
	}

	nrows = max_y - (int) (max_y * (7.0/8.0));
	ncols = (int) (max_x * (1.0/2.0));
	begin_y = 0;
	begin_x = 0;
	win = window_create(int nrows, int ncols, int begin_y, int begin_x);
	
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

/**
@author Adrián Fernández
@date 07-12-2016

@brief screen_getch
Gets the input of a user in a window.

@param Window *win: Pointer to the window selected.
@param char *input: String in which the input is stored.
@return char *: Input of the user.
*/
char * screen_get_input(Window *win, char *input){
	if(!wgetnstr(win, input, WORD_SIZE)){
		return NULL;
	}
	return input;
}






/**
@date 02-11-2016 
@author Alejandro Sanchez

@brief game_print_objects
Prints the objects of the game (<name>:<location>).

@param Game *game: the game to print its objects.
@param Space *space: the space where you want to print the objects.

@return
*/
void game_print_objects(Game *game, Space *space){
  int i, count;
  char *name = NULL;
  Set *set = NULL;
  Object *object = NULL;

  /* Start printing the row of the space */
  fprintf(stdout, "     |");
  /* Get the set of objects on the space and how many are there */
  set = space_get_object(space);
  count = set_get_count(set);
  /* Get the different names of the objects and print them */
  for(i=0; i<count; i++){    
    object = game_get_object(game, set_get_object_at_position(set, i));
    name = object_get_name(object);
    /* Maximum three objects per space */   
    if(i < 3){             
      fprintf(stdout, "%s ", name);
    }
  }

  /* Print the rest of the row. The way depends on the number of objects */
  switch(i){
    /* 0 objects */
    case 0:
       fprintf(stdout, "           |\n");
       break;
    /* 1 object */
    case 1:
       fprintf(stdout, "        |\n");
       break;
    /* 2 objects */
    case 2:
       fprintf(stdout, "     |\n");
       break;
    /* 3 objects */
    case 3:
       fprintf(stdout, "  |\n");
       break; 
    /* More than 3 objects */
    default:
       fprintf(stdout, "..|\n");  
       break;
  }

  return; 
}



/**
Function: 
@date 02-11-2016 
@author Alejandro Sanchez

@brief game_print_screen
Prints the screen of the game.

@param Game *game: the game to print its screen.

@return
*/
void game_print_screen(Game *game){
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_east = NO_ID;
  Id id_west = NO_ID, id_obj = NO_ID, id_spc_back = NO_ID, id_spc_next = NO_ID;
  Space *space_act = NULL, *space_back = NULL, *space_next = NULL;
  Link *link_back = NULL, *link_next = NULL;
  char *name = NULL;
  char aux[WORD SIZE] = "";
  Object *object = NULL;
  int i, count;
  Inventory *inv = NULL; 
    
  if(!game){ /* Check that the input is not empty */
    return;
  }  

  /* Get actual location of the player */
  id_act = game_get_player_location(game, 1);  
  if(id_act == NO_ID){  /* Check if it has worked */
    return;
  }
  
  /* Get the space where the player is */  
  space_act = game_get_space(game, id_act);

  /* Get the previous space */
  id_back = space_get_north(space_act);
  if(id_back != NO_ID){
    link_back = game_get_link(game, id_back);
    id_spc_back = link_get_space2(link_back);
    space_back = game_get_space(game, id_spc_back);
  }
 

  /* Get the next space */
  id_next = space_get_south(space_act);
  if(id_next != NO_ID){
    link_next = game_get_link(game, id_next);
    id_spc_next = link_get_space2(link_next);
    space_next = game_get_space(game, id_spc_next); 
  }
  
   
  if(system(CLEAR)){
    return; 
  }

  /* Print the previous space if it is different from NO_ID */
  if(id_back != NO_ID){
    id_east = space_get_east(space_back);
    id_west = space_get_west(space_back);
    if(id_east != NO_ID && id_west != NO_ID){
      link_back = game_get_link(game, id_east);
      link_next = game_get_link(game, id_west);

      sprintf(aux, "   %2d|         %2d|%2d\n", (int)id_west, (int)id_spc_back, 
        (int)id_east);
	  window_add_text(screen_get_window(game_get_screen(game), 0), aux);

      printf("%2d<--|           |-->%2d\n", (int)link_get_space2(link_next), 
        (int)link_get_space2(link_back));
      space_print_gdesc(space_back);
    } else if(id_east != NO_ID && id_west == NO_ID){
     	  link_back = game_get_link(game, id_east);
        printf("     |         %2d|%2d\n", (int)id_spc_back, (int)id_east);
        printf("     |           |-->%2d\n", (int)link_get_space2(link_back));
        space_print_gdesc(space_back);
		} else if(id_west != NO_ID){
		    link_back = game_get_link(game, id_west);
        printf("   %2d|         %2d|\n", (int)id_west, (int)id_back);
				printf("%2d<--|           |\n", (int)link_get_space2(link_back));
        space_print_gdesc(space_back);
		} else{
        printf("     |         %2d|\n", (int) id_back);
				printf("     |           |\n");
				space_print_gdesc(space_back);
		}
		game_print_objects(game, space_back);
		printf("     +-----------+\n");
		printf("            ^ %2d\n", (int)id_back);
  }
  
  /* Print the actual space if it is different from NO_ID */
  if(id_act != NO_ID){
    printf("     +-----------+\n");
    id_east = space_get_east(space_act);
    id_west = space_get_west(space_act);
    if(id_east != NO_ID && id_west != NO_ID){
      link_back = game_get_link(game, id_east);
      link_next = game_get_link(game, id_west);
      printf("   %2d| >8D     %2d|%2d\n", (int)id_west, (int)id_act, 
        (int)id_east);
      printf("%2d<--|           |-->%2d\n", (int)link_get_space2(link_next), 
        (int)link_get_space2(link_back));
      space_print_gdesc(space_act);
    } else if(id_east != NO_ID && id_west == NO_ID){
     	  link_back = game_get_link(game, id_east);
        printf("     | >8D     %2d|%2d\n", (int)id_act, (int)id_east);
        printf("     |           |-->%2d\n", (int)link_get_space2(link_back));
        space_print_gdesc(space_act);
		} else if(id_west != NO_ID){
		    link_back = game_get_link(game, id_west);
        printf("   %2d| >8D     %2d|\n", (int)id_west, (int)id_act);
				printf("%2d<--|           |\n", (int)link_get_space2(link_back));
        space_print_gdesc(space_act);
		} else{
        printf("     | >8D     %2d|\n", (int) id_act);
				printf("     |           |\n");
        space_print_gdesc(space_act);
		}
		game_print_objects(game, space_act);
		printf("     +-----------+\n");
  }  
    
  /* Print the next space if it is different from NO_ID */ 
  if(id_next != NO_ID){
    printf("            v %2d\n", (int)id_next);
    printf("     +-----------+\n");
    id_east = space_get_east(space_next);
    id_west = space_get_west(space_next);
    if(id_east != NO_ID && id_west != NO_ID){
      link_next = game_get_link(game, id_east);
      link_back = game_get_link(game, id_west);
      printf("   %2d|         %2d|%2d\n", (int)id_west, (int)id_spc_next, 
        (int)id_east);
      printf("%2d<--|           |-->%2d\n", (int)link_get_space2(link_back), 
        (int)link_get_space2(link_next));
      space_print_gdesc(space_next);
    } else if(id_east != NO_ID && id_west == NO_ID){
     	  link_next = game_get_link(game, id_east);
        printf("     |         %2d|%2d\n", (int)id_spc_next, (int)id_east);
        printf("     |           |-->%2d\n", (int)link_get_space2(link_next));
        space_print_gdesc(space_next);
		} else if(id_west != NO_ID){
		    link_next = game_get_link(game, id_west);
        printf("   %2d|         %2d|\n", (int)id_west, (int)id_next);
				printf("%2d<--|           |\n", (int)link_get_space2(link_next));
        space_print_gdesc(space_next);
		} else{
        printf("     |         %2d|\n", (int) id_spc_next);
				printf("     |           |\n");
        space_print_gdesc(space_next);
		}
		game_print_objects(game, space_next);
  }

  /*
  printf("\nObjects location: ");
  for(i=0; i<MAX_OBJECTS && objects(game)[i] != NULL; i++){
    id_obj = object_get_location(objects(game)[i]);
    name = object_get_name(objects(game)[i]);
    if(id_obj != NO_ID){
      printf("%s:%2d ", name, (int)id_obj);
    }
  }
  */

  /* Print the objects of the game*/  
  inv = player_get_inventory(players(game)[0]);
  count = inventory_get_count(inv);
  printf("\nPlayer objects: ");
  /* Get the different names of the objects and print them */
	for(i=0; i<count; i++){    
	  object = game_get_object(game, set_get_object_at_position(inventory_get_bag(inv), i));
    name = object_get_name(object);
    printf("%s, ",name);
  }

  /*Print the last die value*/
  printf("\nLast die value: %d", die_get_value(die(game)));
  /* Print the commands the user can type */
  printf("\n[commands: go <direction> or g <direction>, catch <obj_name> or c <obj_name>, leave ");
  printf("<obj_name> or l <obj_name>, inspect <spc_name/obj_name> or i <spc_name/obj_name>, quit or q, roll or r]");
  printf("\nprompt:> ");
}
