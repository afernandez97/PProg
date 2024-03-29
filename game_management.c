/**
@file game_management.c
@version 6.2
@date 16-12-2016
@authors Guillermo Rodriguez and Alejandro Sanchez

@brief
It implements the game management.

@version
Sept. 30, 2016  Version 1.0 (initial release)
@version
Sept. 30, 2016  Version 2.0 
  Commented the file.
@version
Oct. 27,  2016  Version 3.0
  Created functions "game_load_objects" and "game_add_object".
  Modified function "game_load_spaces".
@version
Nov. 05, 2016   Version 4.0
  Modified functions after making "Game" structure private.
@version
Nov. 11, 2016   Version 4.1
  Created functions "game_load_links" and "game_add_link".  
@version
Nov. 26, 2016 Version 5.0
  Updated headers to use Doxygen.
@version
Dec. 3, 2016 Version 6.0
  Added add_player and game_load_players.
@version
Dec. 11, 2016 Version 6.1
  Changed name of the file to game_management.c
  Created functions "game_load" and "game_save" (and game_save_X)
@version
Dec. 16, 2016 Version 6.2
  Added functions to load and save rules and people.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_management.h"
#include "game.h" 



/*!< Public functions definition */

/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save
Saves the status of a game.

@param Game *game: the game you want to save its status.
@param char *path: the path of the different files that will contain the status of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save(Game *game, char *path){
  char f1[WORD_SIZE]="";
  char f2[WORD_SIZE]="";
  char f3[WORD_SIZE]="";
  char f4[WORD_SIZE]="";
  char f5[WORD_SIZE]="";
  char f6[WORD_SIZE]="";

  /* Check that the inputs are not empty */ 
  if(!game || !path){  
    return ERROR_;
  }

  /* Concatenate the rest of the name of each file */
  strcpy(f1, path);
  strcat(f1,"_lnk.dat");
  strcpy(f2, path);
  strcat(f2,"_spc.dat");
  strcpy(f3, path);
  strcat(f3,"_obj.dat");
  strcpy(f4, path);
  strcat(f4,"_ply.dat");
  strcpy(f5, path);
  strcat(f5,"_rul.dat");
  strcpy(f6, path);
  strcat(f6,"_per.dat");

  /* Save the links from the file and check if it has worked */
  if(game_save_links(game, f1) == ERROR_){
    return ERROR_;
  } 

  /* Save the spaces from the file and check if it has worked */
  if(game_save_spaces(game, f2) == ERROR_){ 
    return ERROR_;
  }

  /* Save the objects from the file and check if it has worked */
  if(game_save_objects(game, f3) == ERROR_){
    return ERROR_;
  } 

  /* Save the players from the file and check if it has worked */
  if(game_save_players(game, f4) == ERROR_){
    return ERROR_;
  }

  /* Save the rules from the file and check if it has worked */
  if(game_save_rules(game, f5) == ERROR_){
    return ERROR_;
  }

  /* Save the people from the file and check if it has worked */
  if(game_save_people(game, f6) == ERROR_){
    return ERROR_;
  }

  return OK_;
}


/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save_links
Saves the links of a game.

@param Game *game: the game you want to save its links.
@param char *filename: the filename that will contain the links of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_links(Game *game, char *filename){
  FILE *f_lnk = NULL;
  char name[WORD_SIZE] = "";
  Id id, space1, space2;
  STATE state;
  Link *link = NULL;
  int i = 0, flag = 0;
  STATUS_ status = OK_;

  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR_;
  }
  
  f_lnk = fopen(filename, "w");
  if(!f_lnk){
    return ERROR_;
  }

  /* Print each line of the file until finding an empty link */
  while(i < MAX_LINKS && flag == 0){
    /* Get each link of the game */
    link = game_get_link_at_position(game, i);  
    if(link != NULL) {
      /* Get the id of the link */  
      id = link_get_id(link);

      /* Get the name of the link */
      strcpy(name, link_get_name(link));

      /* Get the spaces that the link connects */  
      space1 = link_get_space1(link);
      space2 = link_get_space2(link);

      /* Get if the link is open or closed */
      state = link_get_state(link); 

      fprintf(f_lnk, "#l:%ld|%s|%ld|%ld|%d\n", 
        id, name, space1, space2, state);
    } else{
      flag = 1;
    } 

    i++;
  }

  if(ferror(f_lnk)){
    status = ERROR_;
  }
  
  fclose(f_lnk);

  return status;
}


/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save_spaces
Saves the spaces of a game.

@param Game *game: the game you want to save its spaces.
@param char *filename: the filename that will contain the spaces of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_spaces(Game *game, char *filename){
  FILE *f_spc = NULL;
  char name[WORD_SIZE] = "";
  char gdesc[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
  Id id, north, east, south, west, up, down, rule, person;
  BOOL_ illumination, shop, exam;
  Space *space = NULL;
  int i = 0, flag = 0;
  STATUS_ status = OK_;

  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR_;
  }

  f_spc = fopen(filename, "w");
  if(!f_spc){
    return ERROR_;
  }

  /* Print each line of the file until finding an empty space */
  while(i < MAX_SPACES && flag == 0){
    /* Get each space of the game */
    space = game_get_space_at_position(game, i);  
    if(space != NULL) {
      /* Get the id of the space */  
      id = space_get_id(space);

      /* Get the name of the space */
      strcpy(name, space_get_name(space));

      /* Get the links of the space */  
      north = space_get_north(space);
      east = space_get_east(space);
      south = space_get_south(space);
      west = space_get_west(space);
      up = space_get_up(space);
      down = space_get_down(space);

      /* Get the rule of the space */  
      rule = space_get_rule(space);

      /* Get the person of the space */  
      person = space_get_person(space);

      /* Get if the space is illuminated or not */
      illumination = space_is_illuminated(space); 

      /* Get if the space is a shop or not */
      shop = space_is_shop(space);

      /* Get if the space will hold the exam or not */
      exam = space_is_exam(space);

      /* Get the graphic description of the space */ 
      strcpy(gdesc, space_get_gdesc(space));

      /* Get the description of the space */ 
      strcpy(desc, space_get_desc(space));

      fprintf(f_spc, "#s:%ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%d|%d|%d|%s|%s\n", 
        id, name, north, west, south, east, up, down, rule, person, illumination, shop, exam, desc, gdesc);
    } else{
      flag = 1;
    } 

    i++;
  }

  if(ferror(f_spc)){
    status = ERROR_;
  }
  
  fclose(f_spc);

  return status;
}


/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save_objects
Saves the objects of a game.

@param Game *game: the game you want to save its objects.
@param char *filename: the filename that will contain the objects of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_objects(Game *game, char *filename){
  FILE *f_obj = NULL;
  char name[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
  Id id, location, open;
  double price;
  BOOL_ hidden, light, on;
  Object *object = NULL;
  int i = 0, flag = 0;
  STATUS_ status = OK_;

  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR_;
  }

  f_obj = fopen(filename, "w");
  if(!f_obj){
    return ERROR_;
  }

  /* Print each line of the file until finding an empty object */
  while(i < MAX_OBJECTS && flag == 0){
    /* Get each object of the game */
    object = game_get_object_at_position(game, i);  
    if(object != NULL) {
      /* Get the id of the object */  
      id = object_get_id(object);

      /* Get the name of the object */
      strcpy(name, object_get_name(object));

      /* Get the location of the object */  
      location = object_get_location(object);

      /* Get the price of the object */  
      price = object_get_price(object);

      /* Get if the object is hidden or not */
      hidden = object_is_hidden(object); 

      /* Get if the object can light or not */
      light = object_can_light(object); 

      /* Get if the object is on or off */
      on = object_is_on(object); 

      /* Get if the object can open a link or not */
      open = object_can_open(object); 

      /* Get the description of the object */ 
      strcpy(desc, object_get_desc(object));

      fprintf(f_obj, "#o:%ld|%s|%ld|%f|%d|%d|%d|%ld|%s\n", 
        id, name, location, price, hidden, light, on, open, desc);
    } else{
      flag = 1;
    } 

    i++;
  }

  if(ferror(f_obj)){
    status = ERROR_;
  }
  
  fclose(f_obj);

  return status;
}


/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_save_players
Saves the players of a game.

@param Game *game: the game you want to save its players.
@param char *filename: the filename that will contain the players of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_players(Game *game, char *filename){
  FILE *f_ply = NULL;
  char name[WORD_SIZE] = "";
  Id id, location;
  Player *player = NULL;
  Set *bag = NULL;
  int i = 0, flag = 0, j, count;
  char objects[WORD_SIZE] = "", aux[WORD_SIZE] = "";
  STATUS_ status = OK_;
  double money;

  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR_;
  }

  f_ply = fopen(filename, "w");
  if(!f_ply){
    return ERROR_;
  }

  /* Print each line of the file until finding an empty player */
  while(i < MAX_PLAYERS && flag == 0){
    /* Get each player of the game */
    player = game_get_player_at_position(game, i);  
    if(player != NULL) {
      /* Get the id of the player */  
      id = player_get_id(player);

      /* Get the name of the player */
      strcpy(name, player_get_name(player));

      /* Get the location of the player */  
      location = player_get_location(player);

      /* Get the money of the player */  
      money = player_get_money(player);

      /* Get the objects of the player */
      bag = inventory_get_bag(player_get_inventory(player));
      if(bag != NULL){
        count = set_get_count(bag);
        strcpy(objects, "");
        for(j=0; j<count; j++){
          sprintf(aux, "%ld,", set_get_object_at_position(bag, j));
          strcat(objects, aux);
        }
      }

      fprintf(f_ply, "#p:%ld|%s|%ld|%f|%s\n", 
        id, name, location, money, objects);
    } else{
      flag = 1;
    } 

    i++;
  }

  if(ferror(f_ply)){
    status = ERROR_;
  }
  
  fclose(f_ply);

  return status;
}

/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_save_rules
Saves the rules of a game.

@param Game *game: the game you want to save its rules.
@param char *filename: the filename that will contain the rules of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_rules(Game *game, char *filename){
  FILE *f_rul = NULL;
  Rule *rule = NULL;
  char question[WORD_SIZE] = "",choice1[WORD_SIZE] = "",choice2[WORD_SIZE] = "";
  Id id;
  int i = 0, flag = 0;
  STATUS_ status = OK_;

  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR_;
  }

  f_rul = fopen(filename, "w");
  if(!f_rul){
    return ERROR_;
  }

  /* Print each line of the file until finding an empty rule */
  while(i < MAX_RULES && flag == 0){
    /* Get each rule of the game */
    rule = game_get_rule_at_position(game, i);  
    if(rule != NULL) {
      /* Get the id of the rule */  
      id = rule_get_id(rule);

      /* Get the question of the rule */
      strcpy(question, rule_get_question(rule));
      /* Get the choice1 of the rule */
      strcpy(choice1, rule_get_choice1(rule));
      /* Get the choice2 of the rule */
      strcpy(choice2, rule_get_choice2(rule));
      
      fprintf(f_rul, "#r:%ld|%s|%s|%s\n", 
        id, question, choice1, choice2);
    } else{
      flag = 1;
    } 

    i++;
  }

  if(ferror(f_rul)){
    status = ERROR_;
  }
  
  fclose(f_rul);

  return status;
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_save_people
Saves the people of a game.

@param Game *game: the game you want to save its people.
@param char *filename: the filename that will contain the people of the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_save_people(Game *game, char *filename){
  FILE *f_per = NULL;
  Person *person = NULL;
  char name[WORD_SIZE] = "";
  Id id, location, rule;
  STATUS_ status = OK_;
  int i = 0, flag = 0;

  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR_;
  }

  f_per = fopen(filename, "w");
  if(!f_per){
    return ERROR_;
  }

  /* Print each line of the file until finding an empty person */
  while(i < MAX_PEOPLE && flag == 0){
    /* Get each person of the game */
    person = game_get_person_at_position(game, i);  
    if(person != NULL) {
      /* Get the id of the person */  
      id = person_get_id(person);

      /* Get the name of the person */
      strcpy(name, person_get_name(person));

      /* Get the location of the person */  
      location = person_get_location(person);

      /* Get the rule of the  */  
      rule = person_get_rule(person);
      
      fprintf(f_per, "#p:%ld|%s|%ld|%ld\n", 
        id, name, location, rule);
    } else{
      flag = 1;
    } 

    i++;
  }

  if(ferror(f_per)){
    status = ERROR_;
  }
  
  fclose(f_per);

  return status;
}



/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_load
Loads a previous save of a game.

@param Game *game: the game where you want to load the previous save of it.
@param char *path: the path of the different files that contain the game.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load(Game *game, char *path){
  char f1[WORD_SIZE]="";
  char f2[WORD_SIZE]="";
  char f3[WORD_SIZE]="";
  char f4[WORD_SIZE]="";
  char f5[WORD_SIZE]="";
  char f6[WORD_SIZE]="";

  /* Check that the inputs are not empty */ 
  if(!game || !path){  
    return ERROR_;
  }

  /* Concatenate the rest of the name of each file */
  strcpy(f1, path);
  strcat(f1,"_rul.dat");
  strcpy(f2, path);
  strcat(f2,"_lnk.dat");
  strcpy(f3, path);
  strcat(f3,"_spc.dat");
  strcpy(f4, path);
  strcat(f4,"_obj.dat");
  strcpy(f5, path);
  strcat(f5,"_ply.dat");
  strcpy(f6, path);
  strcat(f6,"_per.dat");

  /* Load the rules from the file and check if it has worked */
  if(game_load_rules(game, f1) == ERROR_){
    return ERROR_;
  }

  /* Load the links from the file and check if it has worked */
  if(game_load_links(game, f2) == ERROR_){
    return ERROR_;
  } 

  /* Load the spaces from the file and check if it has worked */
  if(game_load_spaces(game, f3) == ERROR_){ 
    return ERROR_;
  }

  /* Load the objects from the file and check if it has worked */
  if(game_load_objects(game, f4) == ERROR_){
    return ERROR_;
  } 

  /* Load the players from the file and check if it has worked */
  if(game_load_players(game, f5) == ERROR_){
    return ERROR_;
  }

  /* Load the people from the file and check if it has worked */
  if(game_load_people(game, f6) == ERROR_){
    return ERROR_;
  }

  return OK_;
}


/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_add_link
Adds an link to a game.

@param Game *game: the game where you add the link.
@param Link *link: the link you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_link(Game *game, Link *link){
  int i = 0;  /* Initialize the counter */

  if(!game || !link){  /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Increase the counter until finding an empty link */
  while(i < MAX_LINKS && game_get_link_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every link is not empty */
  if(i >= MAX_LINKS){
    return ERROR_;
  }

  /* Set the new link */
  if(game_set_link_at_position(game, link, i) == ERROR_){
    return ERROR_;
  }

  return OK_;
}



/**
@date 10-11-2016
@author Ricardo Riol

@brief game_load_links
Loads the links from a file.

@param Game *game: the game where you want to load the links.
@param char *filename: the file that contains the links. 
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load_links(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID;
  Id space_id1 = NO_ID;
  Id space_id2 = NO_ID;
  STATE link_state = NO_STATE;
  Link *link = NULL;
  STATUS_ status = OK_;


  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR_;
  }
  
  file = fopen(filename, "r");  /* Open the file where the links are */
  if(!file){        
    return ERROR_;
  }

  /* Read each line of the file and get the id, the name, the spaces and the state of the links */
  while(fgets(line, WORD_SIZE, file)){
    if(strncmp("#l:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|"); 
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      space_id1 = atol(toks);
      toks = strtok(NULL, "|");
      space_id2 = atol(toks);
      toks = strtok(NULL, "|");
      link_state = atoi(toks);

#ifdef DEBUG 
  printf("Leido: %ld|%s|%ld|%ld|%d\n", id, name, space_id1, space_id2, link_state);
#endif
  
      link = link_create(id); /* Create the link */
      if(link != NULL){
        /* Set the name to the link */      
        link_set_name(link, name);

        /* Set the first space to the link */
        link_set_space1(link, space_id1);

        /* Set the second space to the link */
        link_set_space2(link, space_id2);

        /* Set the state to the link */
        link_set_state(link, link_state);

        /* Add the link to the game */
        game_add_link(game, link);  
      }
    } /* if(strncmp("#l:", line, 3) == 0) */
  } /* while */
  
  if(ferror(file)){
    status = ERROR_;
  }
  
  fclose(file);
  
  return status;
}


/**
@date 30-09-2016 
@author Alejandro Sanchez

@brief game_add_space
Add a space to a game.

@param Game *game: the game where you add the space.
@param Space *space: the space you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_space(Game *game, Space *space){
  int i = 0;  /* Initialize the counter */

  if(!game || !space){  /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Increase the counter until finding an empty space */
  while(i < MAX_SPACES && game_get_space_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every space is not empty */
  if(i >= MAX_SPACES){
    return ERROR_;
  }

  /* Set the new space */
  if(game_set_space_at_position(game, space, i) == ERROR_){
    return ERROR_;
  }

  return OK_;
}



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_load_spaces
Loads the spaces from a file.

@param Game *game: the game where you want to load the spaces.
@param char *filename: the file that contains the spaces.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load_spaces(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
	char gdesc[WORD_SIZE] = "";
	char desc[WORD_SIZE] = "";
	char printdesc[WORD_SIZE] = "";
	char aux[WORD_SIZE] = "";
	char buff[WORD_SIZE] = "";
  char *toks = NULL, *toks2 = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Id up = NO_ID, down = NO_ID, rule = NO_ID, person = NO_ID;
  BOOL_ illumination = FALSE_, shop = FALSE_, exam = FALSE_;
  Space *space = NULL;
  STATUS_ status = OK_;
  int flag = 0, flag2 = 0;
  
  if(!game || !filename){ /* Check that the inputs are not empty */
    return ERROR_;
  }
  
  file = fopen(filename, "r");   /* Open the file where the spaces are */
  if(!file){
    return ERROR_;
  }
  
  /* Read each line of the file and get the id and the links of each space */
  while(fgets(line, WORD_SIZE, file)){
    if(strncmp("#s:", line, 3) == 0){
	  flag = 0;
	  flag2 = 0;
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      if(toks != NULL){
        strcpy(name, toks);
      }
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");      
      west = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      up = atol(toks);
      toks = strtok(NULL, "|");
      down = atol(toks);
      toks = strtok(NULL, "|");
      rule = atol(toks);
      toks = strtok(NULL, "|");
      person = atol(toks);
			toks = strtok(NULL, "|");
      illumination = atoi(toks);
      toks = strtok(NULL, "|");
      shop = atoi(toks);
      toks = strtok(NULL, "|");
      exam = atoi(toks);

      toks = strtok(NULL, "|");
	  if(toks != NULL){
      	strcpy(desc, toks);
		flag = 1;
	  }

      toks = strtok(NULL, "\r");
      if(toks != NULL){
        strncpy(gdesc, toks, strlen(toks)-1);
		flag2 = 1;    
      }

	  if (flag == 1){
		strcpy(printdesc, desc);
		toks2 = strtok(printdesc, "/");
		strcpy(buff, "");
		while(toks2){
			strcpy(aux, " ");
			strcat(aux, toks2);
			strcat(aux, "\n");
			strcat(buff, aux);
			toks2 = strtok(NULL, "/");
		}
		strcpy(printdesc, buff);
	  }

#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%ld|%d|%d|%d|%s|%s\n", 
        id, name, north, east, south, west, up, down, rule, person, illumination, shop, exam, desc, gdesc);
#endif
      space = space_create(id); /* Create the space */
      if(space != NULL){
        /* Set the name to the space */  
        space_set_name(space, name);

        /* Set the links to the space */  
        space_set_north(space, north);
        space_set_west(space, west);
        space_set_south(space, south);
        space_set_east(space, east);
        space_set_up(space, up);
        space_set_down(space, down);

        /* Set the rule to the space */
        space_set_rule(space, rule);

        /* Set the person to the space */
        space_set_person(space, person);
        
        /* Set if the space is illuminated or not */
				space_set_illumination(space, illumination); 

        /* Set if the space is a shop or not */
        space_set_shop(space, shop); 

        /* Set if the space will hold the exam or not */
        space_set_exam(space, exam); 

        /* Set the graphic description to the space */ 
		if (flag2 == 1) {
          space_set_gdesc(space, gdesc);
        }
        /* Set the description to the space */ 
				space_set_desc(space, desc);
        		space_set_printdesc(space, printdesc);
        /* Add the space to the game */
        game_add_space(game, space);  
      }
    } /* if(strncmp("#s:", line, 3) == 0) */
  } /* while */
  
  if(ferror(file)){ /* Test the error indicator for the file */ 
    status = ERROR_;
  }
  
  fclose(file); /* Close the file */
  
  return status;
}



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_add_object
Adds an object to a game.

@param Game *game: the game where you add the object.
@param Object *object: the object you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_object(Game *game, Object *object){
  int i = 0;  /* Initialize the counter */

  if(!game || !object){  /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Increase the counter until finding an empty object */
  while(i < MAX_OBJECTS && game_get_object_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every object is not empty */
  if(i >= MAX_OBJECTS){
    return ERROR_;
  }

  /* Set the new object */
  if(game_set_object_at_position(game, object, i) == ERROR_){
    return ERROR_;
	}

  return OK_;
}



/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_load_objects
Loads the objects from a file.

@param Game *game: the game where you want to load the objects.
@param char *filename: the file that contains the spaces.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load_objects(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
	char desc[WORD_SIZE] = "";
	char printdesc[WORD_SIZE] = "";
  char aux[WORD_SIZE] = "";
  char buff[WORD_SIZE] = "";
  char *toks = NULL, *toks2 = NULL;
  double price = -1;
  Id id = NO_ID, location = NO_ID, open = NO_ID;
  Object *object = NULL;
  Space *space = NULL;
  STATUS_ status = OK_;
	BOOL_ hidden = FALSE_, light = FALSE_, on = FALSE_;
	
  
  if(!game || !filename){ /* Check that the inputs are not empty */
    return ERROR_;
  }
  
  file = fopen(filename, "r");   /* Open the file where the objects are */
  if(!file){
    return ERROR_;
  }
  
  /* Read each line of the file and get the id, the name and the location of the objects */
  while(fgets(line, WORD_SIZE, file)){
    if(strncmp("#o:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      if(toks != NULL){
        strcpy(name, toks);
      }
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      price = atof(toks);
      toks = strtok(NULL, "|");
      hidden = atoi(toks);
      toks = strtok(NULL, "|");
      light = atoi(toks);
	    toks = strtok(NULL, "|");
      on = atoi(toks);
	    toks = strtok(NULL, "|");
	    open = atol(toks);
	    toks = strtok(NULL, "|");
	    if(toks !=NULL){
      	strcpy(desc, toks);
		strcpy(printdesc, desc);
		    toks2 = strtok(printdesc, "/");
		    strcpy(buff, "");
		    while(toks2){
			    strcpy(aux, " ");
			    strcat(aux, toks2);
			    strcat(aux, "\n");
			    strcat(buff, aux);
			    toks2 = strtok(NULL, "/");
		    }
		    strcpy(printdesc, buff);
	    }
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%f|%d|%d|%d|%ld|%s\n", id, name, location, price, hidden, light, on, open, desc);
#endif
      object = object_create(id); /* Create the object */
      if(object != NULL){
        /* Set the name to the object */  
        object_set_name(object, name);

        /* Set the location to the object */  
				object_set_location(object, location);
				
				/* Set the description to the object */ 
				object_set_desc(object, desc);
				object_set_printdesc(object, printdesc);
				
				/* Set the price for an object */         
				object_set_price(object, price);
		    
        /* Set if an object is hidden or not */
        object_set_hidden(object, hidden);

				/* Set if an object can open a link or not */	
				object_set_open(object, open);

				/* Set if an object can light or not */
				object_set_light(object, light);

        /* Set if an object is on or off */
				object_set_on(object, on);

	
        /* Add the object to the game */
        game_add_object(game, object);  


        /* Add the object to the set of objects of its location */
        space = game_get_space(game, location);
        if(space != NULL){
          space_add_object(space, id);
				} 
      } /* if(object != NULL) */
    } /* if(strncmp("#o:", line, 3) == 0) */
  } /* while */
  
  if(ferror(file)){ /* Test the error indicator for the file */ 
    status = ERROR_;
  }
  
  fclose(file); /* Close the file */
  
  return status;
}



/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_add_link
Adds an player to a game.

@param Game *game: the game where you add the player.
@param Player *player: the player you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_player(Game *game, Player *player){
  int i = 0;  /* Initialize the counter */

  if(!game || !player){  /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Increase the counter until finding an empty player */
  while(i < MAX_PLAYERS && game_get_player_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every player is not empty */
  if(i >= MAX_PLAYERS){
    return ERROR_;
  }

  /* Set the new player */
  if(game_set_player_at_position(game, player, i) == ERROR_){
    return ERROR_;
  }

  return OK_;
}


/**
@date 03-12-2016
@author Adrián Fernández

@brief game_load_players
Loads players from a file.

@param Game *game: the game where you want to load the players.
@param char *filename: the file that contains the players. 
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_load_players(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  char obj[WORD_SIZE] = "";
  Id id = NO_ID, location = NO_ID, objects[MAX_BAG];
  Player *player = NULL;
  STATUS_ status = OK_;
  int i;
  double money = 0;


  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR_;
  }

  for(i=0; i<MAX_BAG; i++){
    objects[i] = NO_ID;
  }
  
  file = fopen(filename, "r");  /* Open the file where the players are */
  if(!file){        
    return ERROR_;
  }

  /* Read each line of the file and get the id, the name, the spaces and the state of the players */
  while(fgets(line, WORD_SIZE, file)){
    if(strncmp("#p:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|"); 
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      money = atof(toks);
      toks = strtok(NULL, "\r");
      if(toks != NULL){
        strncpy(obj, toks, strlen(toks)-1); 
        toks = strtok(obj, ",");
        for(i=0; i<MAX_BAG && toks != NULL; i++){
          objects[i] = atol(toks);
          toks = strtok(NULL, ",");
        }       
      } 

#ifdef DEBUG 
  printf("Leido: %ld|%s|%ld|%f|%s\n", id, name, location, money, obj);
#endif
  
      player = player_create(id); /* Create the player */
      if(player != NULL){
        /* Set the name to the player */      
        player_set_name(player, name);

        /* Set the location of the player */
        player_set_location(player, location);

        /* Set the money of the player */
        player_set_money(player, money);

        /* Add the objects to the player */
        for(i=0; i<MAX_BAG; i++){
          player_add_object(player, objects[i]);
        }
         
        /* Add the player to the game */
        game_add_player(game, player);  
      }
    } /* if(strncmp("#p:", line, 3) == 0) */
  } /* while */
  
  if(ferror(file)){
    status = ERROR_;
  }
  
  fclose(file);
  
  return status;
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_add_rule
Adds a rule to a game.

@param Game *game: the game where you add the rule.
@param Rule *rule: the rule you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_rule(Game *game, Rule *rule){
  int i = 0;  /* Initialize the counter */

  if(!game || !rule){  /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Increase the counter until finding an empty rule */
  while(i < MAX_RULES && game_get_rule_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every rule is not empty */
  if(i >= MAX_RULES){
    return ERROR_;
  }

  /* Set the new rule */
  if(game_set_rule_at_position(game,rule, i) == ERROR_){
    return ERROR_;
  }

  return OK_;
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_load_rules
Loads the rules from a file.

@param Game *game: the game where you want to load the rules .
@param char *filename: the file that contains the rules.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ game_load_rules(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char *toks = NULL;
  char question[WORD_SIZE] = "", choice1[WORD_SIZE] = "", choice2[WORD_SIZE] = "";
  Id id = NO_ID;
  Rule * rule = NULL; 
  STATUS_ status = OK_;
  
  if(!game || !filename){ /* Check that the inputs are not empty */
    return ERROR_;
  }
  
  file = fopen(filename, "r");   /* Open the file where the rules are */
  if(!file){
    return ERROR_;
  }
  
  /* Read each line of the file and get the id, the question and choices of the rule */
  while(fgets(line, WORD_SIZE, file)){
    if(strncmp("#r:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      if(toks != NULL){
        strcpy(question, toks);
      }
      toks = strtok(NULL, "|");
      if(toks != NULL){
        strcpy(choice1, toks);
      }
      toks = strtok(NULL, "|");
      if(toks != NULL){
        strcpy(choice2, toks);
      }
#ifdef DEBUG 
      printf("Leido: %ld|%s|%s|%s\n", id, question, choice1, choice2);
#endif
      rule = rule_create(id); /* Create the rule */
      if(rule != NULL){
        /* Set the question to the rule */  
        rule_set_question(rule, question);
        
        /* Set the choice1 to the rule */  
        rule_set_choice1(rule, choice1);
        
        /* Set the choice2 to the rule */  
        rule_set_choice2(rule, choice2);
        
        /* Add the rule to the game */
        game_add_rule(game,rule);  
      } 
    } 
  }
  if(ferror(file)){ /* Test the error indicator for the file */ 
    status = ERROR_;
  }
  
  fclose(file); /* Close the file */
  
  return status;
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_add_person
Adds an person to a game.

@param Game *game: the game where you add the person.
@param Person *person: the person you want to add to the game.  
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_person(Game *game, Person *person){
  int i = 0;  /* Initialize the counter */

  if(!game || !person){  /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Increase the counter until finding an empty person */
  while(i < MAX_PEOPLE && game_get_person_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every person is not empty */
  if(i >= MAX_PEOPLE){
    return ERROR_;
  }

  /* Set the new person */
  if(game_set_person_at_position(game,person, i) == ERROR_){
    return ERROR_;
  }

  return OK_;
}



/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_load_people
Loads the people from a file.

@param Game *game: the game where you want to load the people.
@param char *filename: the file that contains the people.   
@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/

STATUS_ game_load_people(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char *toks = NULL;
  char name[WORD_SIZE] = "";
  Id id = NO_ID, location = NO_ID, rule = NO_ID;
  Person * person = NULL;
  Space *space = NULL;
  STATUS_ status = OK_; 
  
  if(!game || !filename){ /* Check that the inputs are not empty */
    return ERROR_;
  }
  
  file = fopen(filename, "r");   /* Open the file where the people are */
  if(!file){
    return ERROR_;
  }
  
  /* Read each line of the file and get the id, the name and the location of the people */
  while(fgets(line, WORD_SIZE, file)){
    if(strncmp("#p:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      if(toks != NULL){
        strcpy(name, toks);
      }
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      rule = atol(toks);
      
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%ld\n", id, name, location, rule);
#endif
      person = person_create(id); /* Create the person */
      if(person != NULL){
        /* Set the name to the person */  
        person_set_name(person, name);

        /* Set the location to the person */  
        person_set_location(person, location);
        
        /* Set the rule to the person */  
        person_set_rule(person, rule);
        

  
        /* Add the person to the game */
        game_add_person(game, person);  


        /* Set the person to a space */
        space = game_get_space(game, location);
        if(space != NULL){
          space_set_person(space, id);
        } 
      }
    } 
  }
  if(ferror(file)){ /* Test the error indicator for the file */ 
    status = ERROR_;
  }
  
  fclose(file); /* Close the file */
  
  return status;
}




