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

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic_engine.h"


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
  int i, j, count;
  char *name = NULL;
  Set *set = NULL;
  Object *object = NULL;
  char aux[WORD_SIZE] = "";

  if(game == NULL || space == NULL || output == NULL){
    return;
  }

  /*Deletes the content of output*/
  if(!strcpy(output, aux)){
    return;
  }
  /* Start printing the row of the space */
  sprintf(aux, "|");
  strcat(output, aux);

  /* Get the set of objects on the space and how many are there */
  set = space_get_object(space);
  count = set_get_count(set);
  /* Get the different names of the objects and print them */
  for(i = 0, j = 0; i<count; i++){ 
    object = game_get_object(game, set_get_object_at_position(set, i));
    name = object_get_name(object);
    /* Maximum three objects per space */   
    if(j < 3){
	  if(object_is_hidden(object) == FALSE_){              
      	sprintf(aux, "%s ", name);
      	strcat(output, aux);
		j++;
	  }
    }
  }

  /* Print the rest of the row. The way depends on the number of objects */
  switch(j){
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
Prints the screen of the game.

@param Game *game: the game to print its screen.
@param int player: integer that indicates the player.

@return
*/
void game_print_screen(Game *game, int player){
  Id id_act = NO_ID, id_north = NO_ID, id_south = NO_ID, id_east = NO_ID, id_west = NO_ID;

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

  scr = game_get_screen(game);

  
  /*Window 0*/
  win = screen_get_window(scr, 0);
  /*Print the last die value*/
  sprintf(aux, " Last die value: %d\t Money:%.2f", die_get_value(game_get_die(game)), player_get_money(game_get_player_at_position(game, player)));
  window_set_text(win, aux);

  /*Window 1*/
  win = screen_get_window(scr, 1);

  window_set_text(win, "");

  /* Print the previous space if it is different from NO_ID */
  if(id_north != NO_ID){
    sprintf(aux, "                  |         %2d|\n", (int) id_north);
    window_add_text(win, aux);

    /*Person in space*/
		sprintf(aux, "                  |  ");
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
    sprintf(aux, "                  ");
    window_add_text(win, aux);
    space_print_gdesc1(space_north, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    sprintf(aux, "                  ");
    window_add_text(win, aux);
    space_print_gdesc2(space_north, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    sprintf(aux, "                  ");
    window_add_text(win, aux);
    space_print_gdesc3(space_north, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    /*Objects*/
    sprintf(aux, "                  ");
    window_add_text(win, aux);
		game_print_objects(game, space_north, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

		sprintf(aux, "                  +-----------+\n");
    window_add_text(win, aux);
		sprintf(aux, "                        ^\n");
    window_add_text(win, aux);
  }
  
  /* Print the actual space if it is different from NO_ID */
  if(id_act != NO_ID){

    if(id_west != NO_ID){
      if(id_east != NO_ID){
        sprintf(aux, "  +-----------+   +-----------+   +-----------+\n");
        window_add_text(win, aux);
        sprintf(aux, "  |         %2d|   | >8D     %2d|   |         %2d|\n", (int)id_west, (int)id_act, (int)id_east);
        window_add_text(win, aux);

        /*Person in the space*/
        sprintf(aux, "  |  ");
		window_add_text(win, aux);
 		if(space_get_person(space_west) != NO_ID){
          	sprintf(aux, "o");
        } else {
        	sprintf(aux, " ");
        }
	    window_add_text(win, aux);
		sprintf(aux, "        | < |  ");
        window_add_text(win, aux);
        if(space_get_person(space_act) != NO_ID){
          sprintf(aux, "o");
        } else {
            sprintf(aux, " ");
        }
    	window_add_text(win, aux);
        sprintf(aux, "        | > |  ");
		window_add_text(win, aux);
		if(space_get_person(space_east) != NO_ID){
          sprintf(aux, "o");
        } else {
            sprintf(aux, " ");
        }
		window_add_text(win, aux);
		sprintf(aux, "        |\n");
        window_add_text(win, aux);

        /*Gdesc*/
		sprintf(aux, "  ");
        window_add_text(win, aux);
        space_print_gdesc1(space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);
        space_print_gdesc1(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);
        space_print_gdesc1(space_east, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

		sprintf(aux, "  ");
        window_add_text(win, aux);
        space_print_gdesc2(space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);
        space_print_gdesc2(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);
        space_print_gdesc2(space_east, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);
        
		sprintf(aux, "  ");
        window_add_text(win, aux);
        space_print_gdesc3(space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);
        space_print_gdesc3(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);
        space_print_gdesc3(space_east, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        /*Objects*/
		sprintf(aux, "  ");
        window_add_text(win, aux);
        game_print_objects(game, space_west, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);

        game_print_objects(game, space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);

        game_print_objects(game, space_east, aux);
        window_add_text(win, aux);
        sprintf(aux,"\n");
        window_add_text(win, aux);

        sprintf(aux, "  +-----------+   +-----------+   +-----------+\n");
        window_add_text(win, aux);
      } else {
        sprintf(aux, "  +-----------+   +-----------+\n");
        window_add_text(win, aux);
        sprintf(aux, "  |         %2d|   | >8D     %2d|\n", (int)id_west, (int)id_act);
        window_add_text(win, aux);

        /*Person in the space*/
        sprintf(aux, "  |  ");
		window_add_text(win, aux);
 		if(space_get_person(space_west) != NO_ID){
          	sprintf(aux, "o");
        } else {
        	sprintf(aux, " ");
        }
	    window_add_text(win, aux);
		sprintf(aux, "        | < |  ");
        window_add_text(win, aux);
        if(space_get_person(space_act) != NO_ID){
          sprintf(aux, "o");
        } else {
            sprintf(aux, " ");
        }
    	window_add_text(win, aux);
        sprintf(aux, "        |\n");
        window_add_text(win, aux);

          /*Gdesc*/
		  sprintf(aux, "  ");
          window_add_text(win, aux);
          space_print_gdesc1(space_west, aux);
          window_add_text(win, aux);
          sprintf(aux, "   ");
          window_add_text(win, aux);
          space_print_gdesc1(space_act, aux);
          window_add_text(win, aux);
          sprintf(aux, "\n");
          window_add_text(win, aux);

		  sprintf(aux, "  ");
          window_add_text(win, aux);
          space_print_gdesc2(space_west, aux);
          window_add_text(win, aux);
          sprintf(aux, "   ");
          window_add_text(win, aux);
          space_print_gdesc2(space_act, aux);
          window_add_text(win, aux);
          sprintf(aux, "\n");
          window_add_text(win, aux);
          
		  sprintf(aux, "  ");
          window_add_text(win, aux);
          space_print_gdesc3(space_west, aux);
          window_add_text(win, aux);
          sprintf(aux, "   ");
          window_add_text(win, aux);
          space_print_gdesc3(space_act, aux);
          window_add_text(win, aux);
          sprintf(aux, "\n");
          window_add_text(win, aux);

          /*Objects*/
		  sprintf(aux, "  ");
          window_add_text(win, aux);
          game_print_objects(game, space_west, aux);
          window_add_text(win, aux);
          sprintf(aux, "   ");
          window_add_text(win, aux);

          game_print_objects(game, space_act, aux);
          window_add_text(win, aux);
          sprintf(aux, "\n");
          window_add_text(win, aux);

          sprintf(aux, "  +-----------+   +-----------+\n");
          window_add_text(win, aux);  
      }    
    } else if (id_east != NO_ID) {
        sprintf(aux, "                  +-----------+   +-----------+\n");
        window_add_text(win, aux);
        sprintf(aux, "                  | >8D     %2d|   |         %2d|\n", (int)id_act, (int)id_east);
        window_add_text(win, aux);

        /*Person in the space*/
        sprintf(aux, "                  |  ");
        window_add_text(win, aux);
        if(space_get_person(space_act) != NO_ID){
          sprintf(aux, "o");
        } else {
            sprintf(aux, " ");
        }
    	window_add_text(win, aux);
        sprintf(aux, "        | > |  ");
		window_add_text(win, aux);
		if(space_get_person(space_east) != NO_ID){
          sprintf(aux, "o");
        } else {
            sprintf(aux, " ");
        }
		window_add_text(win, aux);
		sprintf(aux, "        |\n");
        window_add_text(win, aux);

        /*Gdesc*/
        sprintf(aux, "                  ");
        window_add_text(win, aux);
        space_print_gdesc1(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);
        space_print_gdesc1(space_east, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        sprintf(aux, "                  ");
        window_add_text(win, aux);
        space_print_gdesc2(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);
        space_print_gdesc2(space_east, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);
        
        sprintf(aux, "                  ");
        window_add_text(win, aux);
        space_print_gdesc3(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);
        space_print_gdesc3(space_east, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        /*Objects*/
        sprintf(aux, "                  ");
        window_add_text(win, aux);
        game_print_objects(game, space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "   ");
        window_add_text(win, aux);

        game_print_objects(game, space_east, aux);
        window_add_text(win, aux);
        sprintf(aux,"\n");
        window_add_text(win, aux);

        sprintf(aux, "                  +-----------+   +-----------+\n");
        window_add_text(win, aux);      
    } else {
        sprintf(aux, "                  +-----------+\n");
        window_add_text(win, aux);
        sprintf(aux, "                  | >8D     %2d|\n", (int)id_act);
        window_add_text(win, aux);

        /*Person in the space*/
        sprintf(aux, "                  |  ");
        window_add_text(win, aux);
        if(space_get_person(space_act) != NO_ID){
          sprintf(aux, "o");
        } else {
            sprintf(aux, " ");
        }
		window_add_text(win, aux);
        sprintf(aux, "        |\n");
        window_add_text(win, aux);

        /*Gdesc*/
        sprintf(aux, "                  ");
        window_add_text(win, aux);
        space_print_gdesc1(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        sprintf(aux, "                  ");
        window_add_text(win, aux);
        space_print_gdesc2(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);
        
        sprintf(aux, "                  ");
        window_add_text(win, aux);
        space_print_gdesc3(space_act, aux);
        window_add_text(win, aux);
        sprintf(aux, "\n");
        window_add_text(win, aux);

        /*Objects*/
        sprintf(aux, "                  ");
        window_add_text(win, aux);
        game_print_objects(game, space_act, aux);
        window_add_text(win, aux);
        sprintf(aux,"\n");
        window_add_text(win, aux);

        sprintf(aux, "                  +-----------+\n");
        window_add_text(win, aux);      
    }
  }  
    
  /* Print the next space if it is different from NO_ID */ 
  if(id_south != NO_ID){
    sprintf(aux, "                        v\n");
    window_add_text(win, aux);
    sprintf(aux, "                  +-----------+\n");
    window_add_text(win, aux);
    sprintf(aux, "                  |         %2d|\n", (int) id_south);
    window_add_text(win, aux);

    /*Person in the space*/
		sprintf(aux, "                  |  ");
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
    sprintf(aux, "                  ");
    window_add_text(win, aux);
    space_print_gdesc1(space_south, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    sprintf(aux, "                  ");
    window_add_text(win, aux);
    space_print_gdesc2(space_south, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    sprintf(aux, "                  ");
    window_add_text(win, aux);
    space_print_gdesc3(space_south, aux);
    window_add_text(win, aux);
    sprintf(aux, "\n");
    window_add_text(win, aux);

    /*Objects*/
    sprintf(aux,"                  ");
    window_add_text(win, aux);
    game_print_objects(game, space_south, aux);
    window_add_text(win, aux);
    sprintf(aux,"\n");
    window_add_text(win, aux);
    
  }

  
  /*Window 2*/
  win = screen_get_window(scr, 2);
  window_set_text(win, " prompt:> ");

  /*Window 3*/
  win = screen_get_window(scr, 3);
  /* Print the objects of the game*/  
  inv = player_get_inventory(game_get_player_at_position(game, player));
  count = inventory_get_count(inv);
  sprintf(aux, " Player objects: ");
  window_set_text(win, aux);
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

  screen_print(scr);

  screen_refresh(scr);

  return;
}
