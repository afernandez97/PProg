/**
@file game.c
@version 6.1
@date 19-12-2016
@authors Guillermo Rodriguez, Alejandro Sanchez, Adrian Fernandez and Ricardo Riol

@brief
It implements the game interface and all the associated callbacks
for each command.

@version
Jan. 13, 2015 Version 1.0 (initial release)
@version
Sept. 23, 2016  Version 2.0 
  Commented the file.
@version
Oct. 04, 2016 Version 2.1
  Changed "Id player_location" and "Id object_location" fields 
  for "Player *player" and "Object *object".
  Added macros for each structure field.
  Added input control to the functions.
  Added two inputs (player and object) to "game_init" and 
  "game_init_from_file" after creating ADT Player and ADT Object. 
@version
Oct. 08, 2016 Version 2.2
  Added callbacks CATCH and LEAVE.
  Changed "game_set_player_location", "game_get_player_location", 
  "game_set_object_location" and "game_get_object_location".
@version
Oct. 20, 2016 Version 3.0
  Modified some functions after creating ADT Die and ADT Set.
  Added callback ROLL.
@version
Oct. 27, 2016 Version 3.1
  Created function "game_get_object".
  Made public the function "game_get_space".
@version
Oct. 30, 2016 Version 3.2
  Modified "game_set_player_location", "game_get_player_location", 
  "game_set_object_location" and "game_get_object_location".
@version
Nov. 02, 2016 Version 3.3
  Created function "game_print_objects" and modified function 
  "game_print_screen" to show the graphic description.
@version
Nov. 04, 2016 Version 3.4
  Modified callbacks CATCH and LEAVE to receive input's argument.
  Modified "game_update" and callbacks to return a status.
@version
Nov. 05, 2016 Version 4.0
  Made "Game" structure private.
  Modified some functions after this change.
  Added callback GO and removed callbacks NEXT, BACK and JUMP.
@version
Nov. 13, 2016 Version 4.1
  Added field "Link *links" to the structure after creating ADT Link.
  Created functions "game_spaces_are_linked" and "game_is_link_open"
@version
Nov. 20, 2016 Version 4.2
  Added callback INSPECT.
@version
Nov. 26, 2016 Version 5.0
  Updated headers to use Doxygen.
@version
Dec. 3, 2016 Version 6.0
  Added field "text", players now can be loaded from a file.
@version
Dec. 19, 2016 Version 6.1
  Modified inspect to write the descriptions on the text field.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_management.h"

#ifdef __WINDOWS_BUILD__
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/**
@def Constant values description
*/
#define players(X) (X)->players
#define people(X) (X)->people
#define rules(X) (X)->rules
#define spaces(X) (X)->spaces
#define objects(X) (X)->objects
#define die(X) (X)->die
#define links(X) (X)->links
#define text(X) (X)->text
#define keyboard(X) (X)->keyboard
#define answer(X) (X)->answer
#define screen(X) (X)->screen



/**
@brief
The Game structure stores information of the game and its elements.
*/
struct _Game{
  Player *players[MAX_PLAYERS];   /*!< Players of the game */
  Person *people[MAX_PEOPLE];     /*!< People of the game */
  Rule *rules[MAX_RULES];       /*!< Rules of the game */
  Object *objects[MAX_OBJECTS];   /*!< Objects of the game */
  Space *spaces[MAX_SPACES];      /*!< Spaces of the game */
  Die *die;             /*!< Die of the game*/ 
  Link *links[MAX_LINKS];       /*!< Links of the game */
  char text[WORD_SIZE];       /*!< Text shown on the screen */
  BOOL_ keyboard;           /*!< Indicates if the input comes from the keyboard */ 
  char answer[WORD_SIZE];       /*!< String that stores a command */
  Screen *screen;   /* Screen of the game */
};


/*!< List of callbacks for each command in the game */
/**
@date 04-11-2016 
@author Alejandro Sanchez

@brief callback_UNKNOWN
No actions. It is used when the command is UNKOWN.

@param Game *game: the game.

@return STATUS_: ERROR_, because this command can't be typed.
*/
STATUS_ callback_UNKNOWN(Game *game);
/** 
@date 04-11-2016 
@author Alejandro Sanchez

@brief callback_QUIT
No actions. It is used when the command is QUIT.

@param Game *game: the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_QUIT(Game *game);
/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_CATCH
Catches an object from a space. It is used when the command is CATCH.

@param Game *game: the game.
@param char *arg: the name of the object to catch.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_CATCH(Game *game, char *arg, int player);
/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_LEAVE
Leaves an object on a space. It is used when the command is LEAVE.

@param Game *game: the game.
@param char *arg: the name of the object to leave.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_LEAVE(Game *game, char *arg, int player);
/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief callback_GO
Moves the player to a new space. It is used when the command 
is GO.

@param Game *game: the game.
@param char *arg: the direction you want to move the player.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_GO(Game *game, char *arg, int player);
/**
@date 04-11-2016 
@author Guillermo Rodriguez

@brief callback_ROLL
Rolls a die of the game. It is used when the command is ROLL.

@param Game *game: the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_ROLL(Game *game);
/**
@date 02-12-2016 
@author Ricardo Riol

@brief callback_INSPECT
Tells the space's or object's information

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_INSPECT(Game *game, char *arg, int player);
/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_TURNON
Turns on an object

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_TURNON(Game *game, char *arg, int player);
/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_TURNOFF
Turns on an object

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_TURNOFF(Game *game, char *arg, int player);
/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_open
Opens a link

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_OPENL(Game *game, char *arg, char *arg2, int player);
/**
@date 16-12-2016 
@author Alejandro Sanchez
@brief callback_SAVE
Makes a save of the game. It is used when the command is SAVE.
@param Game *game: the game.
@param char *path: the path of the file to make the save of the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_SAVE(Game *game, char *path);
/**
@date 16-12-2016 
@author Alejandro Sanchez
@brief callback_LOAD
Loads a save of the game. It is used when the command is LOAD.
@param Game *game: the game.
@param char *path: the path of the file to load the save of the game.
@param int die: die of the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_LOAD(Game *game, char *path, int die);
/**
@date 18-12-2016 
@author Guillermo Rodriguez

@brief callback_BUY
Buy an object from a shop. It is used when the command is BUY.

@param Game *game: the game.
@param char *arg: the name of the object to buy.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_BUY(Game *game, char *arg, int player);
/**
@date 18-12-2016 
@author Guillermo Rodriguez

@brief callback_SELL
Sells an object to a shop . It is used when the command is SELL.

@param Game *game: the game.
@param char *arg: the name of the object to sell.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_SELL(Game *game, char *arg, int player);
/**
@date 18-12-2016 
@author Guillermo Rodriguez

@brief callback_ANSWER
Answer to a question . It is used when the command is ANSWER.

@param Game *game: the game.
@param char *arg: the answer of a question.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_ANSWER(Game *game, char *arg, int player);

/**
@date 21-12-2016 
@author Guillermo Rodriguez

@brief callback_TALK
Talk with a person . It is used when the command is TALK.

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_TALK(Game *game, int player);

/** 
@date 21-12-2016 
@author Alejandro Sanchez

@brief callback_NEXT
It is used to change turn. It is used when the command is NEXT.

@param Game *game: the game.
@param int *player: the number of the player.
@param int num: the number of players of the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_NEXT(Game *game, int *player, int num);

/*!< Private functions description */
/**
@date 04-10-2016 
@author Alejandro Sanchez

@brief game_get_space_id_at
Gives the information of the identifier of the space at the position
you want.

@param Game *game: the game where the space is.
@param int position: the position of the space you want the id.

@return Id: the identifier of the space you want or NO_ID on error.
*/
Id game_get_space_id_at(Game *game, int position);


/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_player
Gives a specific player.

@param Game *game: the game where the player is.
@param Id id: the id of the player you want.

@return Player *: the player you want or NULL on error.
*/
Player * game_get_player(Game *game, Id id);

/**
@date 18-12-2016 
@author Alejandro Sanchez

@brief game_get_rule
Gives a specific rule.

@param Game *game: the game where the rule is.
@param Id id: the id of the rule you want.

@return Rule *: the rule you want or NULL on error.
*/
Rule * game_get_rule(Game *game, Id id);

/**
@date 18-12-2016 
@author Alejandro Sanchez

@brief game_get_person
Gives a specific person.

@param Game *game: the game where the person is.
@param Id id: the id of the person you want.

@return Person *: the person you want or NULL on error.
*/
Person * game_get_person(Game *game, Id id);

/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_set_player_location
Sets a location of a player.

@param Game *game: the game where the player is.
@param int player: the number of the player selected.
@param Id location: the location you want for the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_player_location(Game *game, int player, Id location);

/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_set_object_location
Sets a location for an object.

@param Game *game: the game where the object is.
@param Id id: the location you want for the object.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_object_location(Game *game, Id object, Id location);

/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_get_object_location
Gives the location of the object.

@param Game *game: the game where the object is.

@return Id: the location of the object or NO_ID on error.
*/
Id game_get_object_location(Game *game, Id object);

/**
@date 18-12-2016 
@author Alejandro Sanchez

@brief game_set_person_location
Sets a location for an person.

@param Game *game: the game where the person is.
@param Id id: the location you want for the person.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_person_location(Game *game, Id person, Id location);

/**
@date 18-12-2016 
@author Alejandro Sanchez

@brief game_get_person_location
Gives the location of the person.

@param Game *game: the game where the person is.

@return Id: the location of the person or NO_ID on error.
*/
Id game_get_person_location(Game *game, Id person);

/**
@date 11-11-2016 
@author Alejandro Sanchez

@brief game_spaces_are_linked
Checks if there is a link between two spaces.

@param Game *game: the game where the link and spaces are.
@param Space *space1: one of the spaces you want to know if is linked.
@param Space *space2: the other space you want to know if is linked.
@return BOOL_: TRUE_ if the spaces are linked and FALSE_ in other cases. 
*/

BOOL_ game_spaces_are_linked(Game *game, Space *space1, Space *space2);

/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_is_link_open
Checks if a link of the game is open or not.

@param Game *game: the game where the link is.
@param Id link: the identifier of the link to check.
             
@return BOOL_: TRUE_ is the link is open or FALSE_ if not.
*/
BOOL_ game_is_link_open(Game *game, Id link);



/*!< Public functions definition */

/**
@brief get_user_input
Interprets the user's input. 
Input must be typed: 
 <command><blank space><arguments between blank spaces> 
 (space and argument only if needed)

@date 05-11-2016 
@author Ricardo Riol
@param Game *game: the game.
@return Command *: interpretation of user's input or NULL on error.
*/

Command * get_user_input(Game *game){
  Command *command = NULL;
  char input[CMD_LENGTH] = "", aux[CMD_LENGTH] = "";
  char *toks = NULL, *cmd = NULL, *cmd2 = NULL, *arg = NULL, *arg2 = NULL;
  Window *win = NULL;
  BOOL_ flag;

  command = command_create();
  if(!command){   /* Check if memory has been allocated */
    return NULL;
  }
  
  flag = game_get_keyboard(game);

  /* Receive user's input from keyboard */
  if(flag == TRUE_){
    win = game_get_window(game, 2);
    window_get_input(win, input);
  }
 
  /* Receive the answer of the question */
  if(flag == FALSE_){
    if(!strcpy(aux, game_get_answer(game))){
      command_set_cmd(command, NO_CMD);
      return command;
    }
    strcpy(input, aux);
    game_set_keyboard(game, TRUE_);
  }

  /* Check that the user has entered at least 1 character */    
  if(!strcmp(input, "\n") || !strcmp(input, "")){
    command_set_cmd(command, NO_CMD);
    return command;
  }
  
  /* "Tokenize" input */
  /* Delete \n because it's always read at the end of the line */ 
  toks = strtok(input, "\n");
  
  /* Copy toks to an auxiliar string to break it and not toks */
  strcpy(aux, toks);
  /* Save the type of command in cmd. This can't be NULL */
  cmd = strtok(aux, " ");
  /* Save the argument of the command in arg */
  arg = strtok(NULL, " ");

  /* Check if user entered an argument or not */
  if(arg != NULL){   /* There is an argument */
    /* Check if user entered more things after the argument */
    /*if(strtok(NULL, "\0") != NULL){
      command_set_cmd(command) =  UNKNOWN;
      return command;
    }*/
    if(!strcmp(cmd, "c") || !strcmp(cmd, "catch")){
      command_set_cmd(command, CATCH) /* "Catch" case */;
      command_set_arg(command, arg);
    } else if(!strcmp(cmd, "l") || !strcmp(cmd, "leave")){    
        command_set_cmd(command, LEAVE); /* "Leave" case */
        command_set_arg(command, arg);
    }  else if(!strcmp(cmd, "b") || !strcmp(cmd, "buy")){
        command_set_cmd(command, BUY); /* "Buy" case */;
        command_set_arg(command, arg);
    } else if(!strcmp(cmd, "s") || !strcmp(cmd, "sell")){
        command_set_cmd(command, SELL); /* "Sell" case */;
        command_set_arg(command, arg);
    } else if(!strcmp(cmd, "a") || !strcmp(cmd, "answer")){
        command_set_cmd(command, ANSWER); /* "Answer" case */;
        command_set_arg(command, arg);
    } else if(!strcmp(cmd, "i") || !strcmp(cmd, "inspect")){    
        command_set_cmd(command, INSPECT); /* "Inspect" case */
        command_set_arg(command, arg);
    } else if(!strcmp(cmd, "turnon")){    
        command_set_cmd(command, TURNON); /* "Turnon" case */
        command_set_arg(command, arg);
    } else if(!strcmp(cmd, "turnoff")){    
        command_set_cmd(command, TURNOFF); /* "Turnoff" case */
        command_set_arg(command, arg);
    } else if(!strcmp(cmd, "g") || !strcmp(cmd, "go")){
        command_set_cmd(command, GO);    /* "Go" case*/
        command_set_arg(command, arg);
    } else if(!strcmp(cmd, "load")){
        command_set_cmd(command, LOAD);    /* "Load" case*/
        command_set_arg(command, arg);
    } else if(!strcmp(cmd, "save")){
        command_set_cmd(command, SAVE);    /* "Save" case*/
        command_set_arg(command, arg);
    } else if(!strcmp(cmd, "open")){
        cmd2 = strtok(NULL, " ");
        if(!strcmp(cmd2, "with")){
          command_set_arg(command, arg);
          arg2 = strtok(NULL, " ");
          command_set_arg2(command, arg2);
          command_set_cmd(command, OPENL);  /* "Openl" case*/
        }
    } else{                           
        command_set_cmd(command, UNKNOWN); /* Wrong input */
    }
  } else{  /* There isn't any argument */
      if(!strcmp(toks, "q") || !strcmp(toks, "quit")){      
        command_set_cmd(command, QUIT);    /* "Quit" case */
      } else if(!strcmp(toks, "r") || !strcmp(toks, "roll")){
        command_set_cmd(command, ROLL);    /* "Roll" case */
      } else if(!strcmp(toks, "t") || !strcmp(toks, "talk")){
        command_set_cmd(command, TALK);    /* "Talk" case */
      } else if(!strcmp(toks, "n") || !strcmp(toks, "next")){
        command_set_cmd(command, NEXT);    /* "Next" case */
      } else{                           
        command_set_cmd(command, UNKNOWN); /* Wrong input */
      }
  }

  return command;
}


/**
@date 05-10-2016 
@author Guillermo Rodriguez

@brief game_init
Initializes a game.

@param Id die: the identifier of the die of the game.
@param BOOL_ screen: TRUE_ if the screen must be created, FALSE_ if it already exists.

@return Game *game: the game initialized.
*/
Game * game_init(Id die, BOOL_ screen){
  int i;
  Game *game=NULL;

  /* Check that the inputs are not empty */ 
  if(die == NO_ID){ 
    return NULL;
  }

  game = (Game *)malloc(sizeof(Game));
  if(!game){    /* Check if memory has been allocated */
    return NULL;
  }
  
  for(i=0; i < MAX_SPACES; i++){  
    spaces(game)[i] = NULL;  /* Initialize to NULL each space */
  }
    
  for(i=0; i < MAX_LINKS; i++){  
    links(game)[i] = NULL;  /* Initialize to NULL each link */
  }

  for(i=0; i < MAX_PLAYERS; i++){ 
    players(game)[i] = NULL;   /* Initialize to NULL each player */
  }

  for(i=0; i < MAX_OBJECTS; i++){ 
    objects(game)[i] = NULL;   /* Initialize to NULL each object */
  }

  for(i=0; i < MAX_PEOPLE; i++){ 
    people(game)[i] = NULL;   /* Initialize to NULL each person */
  }

  for(i=0; i < MAX_RULES; i++){ 
    rules(game)[i] = NULL;   /* Initialize to NULL each rule */
  }

  die(game) = die_create(die);  /* Create a die */
  if(!die(game)){  /* Check if memory has been allocated */
    free(game);
    return NULL;
  }

  if(screen == TRUE_){
    screen(game) = screen_create();
    if(!screen(game)){
      die_destroy(die(game));
      return NULL;  
    }
  }

  text(game)[0] = '\0';
  answer(game)[0] = '\0';
  keyboard(game) = TRUE_;

  return game;
}



/**
@date 11-12-2016 
@author Alejandro Sanchez

@brief game_init_from_file
Initializes a game from two files which contain the spaces and objects.

@param char *path: the path of the different files that contain the game.
@param Id die: the identifier of the die of the game.
@param BOOL_ screen: TRUE_ if the screen must be created, FALSE_ if it already exists.

@return Game *game: the game initialized.
*/
Game * game_init_from_file(char *path, Id die, BOOL_ screen){
  Game *game = NULL;

  /* Check that the inputs are not empty */ 
  if(!path || die == NO_ID){  
    return NULL;
  }

  /* Initialize the elements of the game and check if it has worked */
  game = game_init(die, screen);
  if(!game){
    return NULL; 
  }

  /* Load the game from the file and check if it has worked */
  if(game_load(game, path) == ERROR_){
    game_destroy(game); /* Destroy the game if it has been an error */
    return NULL;
  } 
  
  return game;
}

/**
@date 21-12-2016 
@author Alejandro Sanchez

@brief game_destroy_screen
Destroys the screen of the game.

@param Game *game: the game where the screen is.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_destroy_screen(Game *game){
  if(!game){
    return ERROR_;
  }

  return screen_destroy(screen(game));
}

/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief game_destroy
Destroys a game.

@param Game *game: the game to destroy.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_destroy(Game *game){
  int i;

  if(!game){  /* Check that the input is not empty */
    return ERROR_;
  }
  
  /* Destroy the die */
  die_destroy(die(game));

  /* Destroy the players */
  for(i=0; i < MAX_PLAYERS; i++){
    player_destroy(players(game)[i]);
  }
  /* Destroy the spaces */
  for(i=0; i < MAX_SPACES; i++){
    space_destroy(spaces(game)[i]);
  }
  /* Destroy the objects */
  for(i=0; i < MAX_OBJECTS; i++){
    object_destroy(objects(game)[i]);
  }
  /* Destroy the links*/ 
  for(i=0; i < MAX_LINKS; i++){
    link_destroy(links(game)[i]);
  }

  /* Destroy the rules*/ 
  for(i=0; i < MAX_RULES; i++){
    rule_destroy(rules(game)[i]);
  }

  /* Destroy the people*/ 
  for(i=0; i < MAX_PEOPLE; i++){
    person_destroy(people(game)[i]);
  }

  free(game);  /* Eliminate the memory of the game */ 

  return OK_;
}



/**
@date 16-12-2016 
@author Alejandro Sanchez

@brief game_update
Updates a game.

@param Game *game: the game to update.
@param Command *cmd: the command typed by the user.
@param int *player: number of the player.
@param int num: the number of players of the game.
@param int die: die of the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_update(Game *game, Command *command, int *player, int num, int die){
  T_Command cmd;
  char arg[CMD_LENGTH] = "";
  char arg2[CMD_LENGTH] = "";
  STATUS_ status = ERROR_;

  if(!game || !command || *player < 0 || num < 0){ /* Check that the inputs are not empty */
    return ERROR_;
  }

  cmd = command_get_cmd(command);
  strcpy(arg, command_get_arg(command));
  strcpy(arg2, command_get_arg2(command));
  /* Call a function depending on the command */
  switch(cmd){
    case UNKNOWN:
      status = callback_UNKNOWN(game);
      break;
    case QUIT:
      status = callback_QUIT(game);
      break;
    case CATCH:
      status = callback_CATCH(game, arg, *player);
      break;
    case LEAVE:
      status = callback_LEAVE(game, arg, *player);
      break;
    case GO:
      status = callback_GO(game, arg, *player);
      break;
    case INSPECT:
      status = callback_INSPECT(game, arg, *player);
      break;          
    case ROLL:
      status = callback_ROLL(game);
      break;
    case TURNON:
      status = callback_TURNON(game ,arg, *player);
      break;
    case TURNOFF:
      status = callback_TURNOFF(game,arg, *player);
      break;
    case BUY:
      status = callback_BUY(game,arg, *player);
      break;
    case SELL:
      status = callback_SELL(game,arg, *player);
      break;
    case ANSWER:
      status = callback_ANSWER(game,arg, *player);
      break;
    case LOAD:
      status = callback_LOAD(game, arg, die);
      break;
    case SAVE:
      status = callback_SAVE(game, arg);
      break;
    case TALK:
      status = callback_TALK(game, *player);
      break;
    case NEXT:
      status = callback_NEXT(game, player, num);
      break;
    case OPENL:
      status = callback_OPENL(game, arg, arg2, *player);
      break;
    case NO_CMD:
      break;
    default: /* We must never arrive here */
      break;
  }
  return status;
}



/**
@date 04-10-2016 
@author Alejandro Sanchez

@brief game_get_space
Gives a specific space.

@param Game *game: the game where the space is.
@param Id id: the id of the space you want.

@return Space *: the space you want or NULL on error.
*/
Space * game_get_space(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
  
  return NULL;
  }

  /* Look for the space you want */
  for(i=0; i < MAX_SPACES && spaces(game)[i] != NULL; i++){
    if(id == space_get_id(spaces(game)[i])){
      return spaces(game)[i];
    }
  }
    
  return NULL;
}


/**
@date 27-10-2016 
@author Alejandro Sanchez

@brief game_get_object
Gives a specific object.

@param Game *game: the game where the object is.
@param Id id: the id of the object you want.

@return Object *: the object you want or NULL on error.
*/
Object * game_get_object(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
    return NULL;
  }

  /* Look for the object you want */
  for(i=0; i < MAX_OBJECTS && objects(game)[i] != NULL; i++){
    if(id == object_get_id(objects(game)[i])){
      return objects(game)[i];
    }
  }
    
  return NULL;
}


/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_get_link
Gives a specific link.

@param Game *game: the game where the link is.
@param Id id: the id of the link you want.

@return Link *: the link you want or NULL on error.
*/
Link * game_get_link(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
    return NULL;
  }

  /* Look for the link you want */
  for(i=0; i < MAX_LINKS && links(game)[i] != NULL; i++){
    if(id == link_get_id(links(game)[i])){
      return links(game)[i];
    }
  }
    
  return NULL;
}


/**
@date 21-12-2016 
@author Alejandro Sanchez

@brief game_get_screen
Gives the screen of the game.

@param Game *game: the game where the screen is.

@return Screen *: the screen you want or NULL on error.
*/
Screen * game_get_screen(Game *game){
  if(!game){
    return NULL;
  }

  return screen(game);
}

/**
@date 21-12-2016 
@author Alejandro Sanchez

@brief game_get_die
Gives the die of the game.

@param Game *game: the game where the die is.

@return Die *: the die you want or NULL on error.
*/
Die * game_get_die(Game *game){
  if(!game){
    return NULL;
  }

  return die(game);
}


/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_set_space_at_position
Sets a space in a specific position.

@param Game *game: the game where the space is.
@param Space *space : the space you want to set
@param int position: the position where you want to set the space.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_space_at_position(Game *game, Space *space, int position){
  if(!game || !space || position < 0){  /* Check that the inputs are not empty */
    return ERROR_;
  }

  if(spaces(game)[position] != NULL){
    space_destroy(spaces(game)[position]);
  }

  spaces(game)[position] = space;

  return OK_;
}



/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_get_space_at_position
Gets the space in a specific position.

@param Game *game: the game where the space is.
@param int position: the position of the space.

@return Space *space : the space in that position or NULL on error.
*/
Space * game_get_space_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return spaces(game)[position];
}



/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_set_object_at_position
Sets an object in a specific position.

@param Game *game: the game where the object is.
@param Object *object : the object you want to set
@param int position: the position where you want to set the object.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_object_at_position(Game *game, Object *object, int position){
  if(!game || !object || position < 0){ /* Check that the inputs are not empty */
    return ERROR_;
  }

  if(objects(game)[position] != NULL){
    object_destroy(objects(game)[position]);
  }

  objects(game)[position] = object;

  return OK_;
}



/**
@date 30-10-2016 
@author Guillermo Rodriguez

@brief game_get_object_at_position
Gets the object in a specific position.

@param Game *game: the game where the object is.
@param int position: the position of the object

@return Object *object : the object in that position or NULL on error.
*/
Object * game_get_object_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return objects(game)[position];
}



/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_set_link_at_position
Sets a link in a specific position.

@param Game *game: the game where the link is.
@param Link *link : the link you want to set
@param int position: the position where you want to set the link.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_link_at_position(Game *game, Link *link, int position){
  if(!game || !link || position < 0){ /* Check that the inputs are not empty */
    return ERROR_;
  }

  if(links(game)[position] != NULL){
    link_destroy(links(game)[position]);
  }

  links(game)[position] = link;

  return OK_;
}



/**
@date 13-10-2016 
@author Alejandro Sanchez

@brief game_get_link_at_position
Gets the link in a specific position.

@param Game *game: the game where the link is.
@param int position: the position of the link.

@return Link *link : the link in that position or NULL on error.
*/
Link * game_get_link_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return links(game)[position];
}



/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_set_link_at_position
Sets a player in a specific position.

@param Game *game: the game where the player is.
@param Player *player: the player you want to set
@param int position: the position where you want to set the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_player_at_position(Game *game, Player *player, int position){
  if(!game || !player || position < 0){ /* Check that the inputs are not empty */
    return ERROR_;
  }

  if(players(game)[position] != NULL){
    player_destroy(players(game)[position]);
  }

  players(game)[position] = player;

  return OK_;
}


/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_link_at_position
Gets the player in a specific position.

@param Game *game: the game where the player is.
@param int position: the position of the player.

@return Player *player : the player in that position or NULL on error.
*/
Player * game_get_player_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return players(game)[position];
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_set_person_at_position
Sets a person in a specific position.

@param Game *game: the game where the person is.
@param Person * person : the person you want to set
@param int position: the position where you want to set the person.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_person_at_position(Game *game, Person *person, int position){
  if(!game || !person || position < 0){ /* Check that the inputs are not empty */
    return ERROR_;
  }

  if(people(game)[position] != NULL){
    person_destroy(people(game)[position]);
  }

  people(game)[position] = person;

  return OK_;
}



/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_get_person_at_position
Gets the person in a specific position.

@param Game *game: the game where the person is.
@param int position: the position of the person

@return Person *person : the person in that position or NULL on error.
*/
Person * game_get_person_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return people(game)[position];
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_set_rule_at_position
Sets a rule in a specific position.

@param Game *game: the game where the rule is.
@param Rule * rule : the rule you want to set
@param int position: the position where you want to set the rule.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_rule_at_position(Game *game, Rule *rule, int position){
  if(!game || !rule || position < 0){ /* Check that the inputs are not empty */
    return ERROR_;
  }

  if(rules(game)[position] != NULL){
    rule_destroy(rules(game)[position]);
  }

  rules(game)[position] = rule;

  return OK_;
}



/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_get_rule_at_position
Gets the rule in a specific position.

@param Game *game: the game where the rule is.
@param int position: the position of the rule

@return Rule *rule : the rule in that position or NULL on error.
*/
Rule * game_get_rule_at_position(Game *game, int position){
  if(!game || position < 0){
    return NULL;  
  }
  
  return rules(game)[position];
}

/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_set_keyboard(Game* game, BOOL_ keyboard)
Sets the keyboard field of a game.

@param Game *game: the game whose keyboard field you want to set.
@param BOOL_ keyboard: the value you want to set.

@return 
STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_keyboard(Game* game, BOOL_ keyboard){
  if (game == NULL){  /* Check if the input is not empty */
    return ERROR_;
  }

  keyboard(game) = keyboard;
  return OK_;
}



/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_get_keyboard(Game* game)
Gets the keyboard field of a game.

@param Game *game: the game whose keyboard field you want to get.

@return 
BOOL_: value of the keyboard field
*/
BOOL_ game_get_keyboard(Game *game){
  if (game == NULL){  /* Check if the input is not empty */
    return FALSE_;
  }

  return keyboard(game);
}



/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_set_answer(Game* game, char * answer)
Sets the answer field of a game.

@param Game *game: the game whose answer field you want to set.
@param char * answer: the value you want to set.

@return 
STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_answer(Game* game, char * answer){
  /* Check if the inputs are not empty */
  if (game == NULL || answer == NULL){  
    return ERROR_;
  }

    /* Set the answer and check if it has worked */
  if(!strcpy(answer(game), answer)){
    return ERROR_;
  }
  return OK_;
}



/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_get_answer
Gets the answer field of a game.

@param Game *game: the game whose answer field you want to get.

@return 
char *: value of the answer field
*/
char * game_get_answer(Game *game){
  /* Check if the input is not empty */
  if (game == NULL){
    return NULL;
  }

  return answer(game);
}

/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_set_text
Sets the text field of a game.

@param Game *game: the game whose text you want to set.
@param char *text: the text you want to set.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_text(Game *game, char *text){
  if (game == NULL || text == NULL){
    return ERROR_;
  }

  if(!strcpy(text(game), text)){
    return ERROR_;
  }

  return OK_;
}

/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_add_text
Adds a string to the text field of a game.

@param Game *game: the game whose text you want to modify.
@param char *text: the text you want to add.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_add_text(Game *game, char *text){
  if (game == NULL || text == NULL){
    return ERROR_;
  }

  if(!strcat(text(game), text)){
    return ERROR_;
  }
  if(!strcat(text(game),"\n")){
    return ERROR_;
  }
   
  return OK_;
}

/**
@date 19-12-2016 
@author Adrián Fernández

@brief game_get_text
Gets the text field of a game.

@param Game *game: the game whose text you want to get.

@return char *: pointer to the text field.
*/
char * game_get_text(Game *game){
  if (game == NULL){
    return NULL;
  }

  return text(game); 
}

/**
@date 20-12-2016 
@author Alejandro Sanchez

@brief game_get_window
Gets a window of the screen of the game.

@param Game *game: the game whose window you want to get.
@param int n: the number of the window.

@return 
Window *: the window you want or NULL on error.
*/
Window * game_get_window(Game *game, int n){
  /* Check if the inputs are not empty */
  if (game == NULL || n < 0){
    return NULL;
  }

  return screen_get_window(screen(game), n);
}

/**
@date 21-12-2016 
@author Adrián Fernández

@brief STATUS_ game_screen_refresh(Game * game)
Refreshes the game screen.

@param Game *game: the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_screen_refresh(Game * game){
  if(game == NULL){
    return ERROR_;
  }

  return screen_refresh(screen(game));
}

/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_player_location
Gives the location of a player.

@param Game *game: the game where the player is.
@param int player: number of the player.

@return Id: the location of the player or NO_ID on error.
*/
Id game_get_player_location(Game *game, int player){
  Player *ply = NULL;

  if(!game || player < 0){  /* Check that the inputs are not empty */
    return NO_ID;
  }

  
  /* Get the player */
  ply = game_get_player_at_position(game, player);

  /* Get its location */
  return player_get_location(ply);
}

/**
@date 21-12-2016 
@author Alejandro Sanchez

@brief game_get_num_players
Gives the number of players in the game.

@param Game *game: the game where the players are.

@return int: the number of players or -1 on error.
*/
int game_get_num_players(Game *game){
  int num = 0;

  if(!game){ /* Check that the input is not empty */
    return -1;
  }

  /* Increase the counter until finding an empty player */
  while(num<MAX_PLAYERS && players(game)[num] != NULL){
    num++;
  }

  return num;
}


/**
@date 23-09-2016 
@author Alejandro Sanchez

@brief game_is_over
Ends the game.

@param Game *game: the game to end.

@return BOOL_: FALSE_.
*/
BOOL_ game_is_over(Game *game){
  return FALSE_;
}



/**
@date 20-10-2016 
@author Alejandro Sanchez

@brief game_print_data
Prints the data of the game.

@param Game *game: the game to print its elements.

@return
*/
void game_print_data(Game *game){
  int i;

  if(!game){  /* Check that the input is not empty */
    return;
  }
    
  printf("\n\n-------------\n\n");
  
  /* Print the spaces */  
  printf("=> Spaces: \n");
  for(i=0; i < MAX_SPACES && spaces(game)[i] != NULL; i++){
    space_print(spaces(game)[i]);
  }
  
  /* Print the objects */
  printf("=> Objects: \n");
  for(i=0; i < MAX_OBJECTS && objects(game)[i] != NULL; i++){
    object_print(objects(game)[i]);
  }
  
  /* Print the links */
  printf("=> Links: \n");
  for(i=0; i < MAX_LINKS && links(game)[i] != NULL; i++){
    link_print(links(game)[i]);
  }

  /* Print the players */
  printf("=> Players: \n");
  for(i=0; i < MAX_PLAYERS && players(game)[i] != NULL; i++){
    player_print(players(game)[i]);
  }

  /* Print the die information */ 
  die_print(die(game));

  return;
}





/*!< Private functions definition */

/**
@date 04-10-2016 
@author Alejandro Sanchez

@brief game_get_space_id_at
Gives the information of the identifier of the space at the position
you want.

@param Game *game: the game where the space is.
@param int position: the position of the space you want the id.

@return Id: the identifier of the space you want or NO_ID on error.
*/
Id game_get_space_id_at(Game *game, int position){
  /* Check that the inputs are correct and not empty */
  if(!game || position < 0 || position >= MAX_SPACES){   
    return NO_ID;
  }

  return space_get_id(spaces(game)[position]);
}



/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_get_player
Gives a specific player.

@param Game *game: the game where the player is.
@param Id id: the id of the player you want.

@return Player *: the player you want or NULL on error.
*/
Player * game_get_player(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
    return NULL;
  }

  /* Look for the player you want */
  for(i=0; i < MAX_PLAYERS && players(game)[i] != NULL; i++){
    if(id == player_get_id(players(game)[i])){
      return players(game)[i];
    }
  }
    
  return NULL;
}



/**
@date 18-12-2016 
@author Alejandro Sanchez

@brief game_get_rule
Gives a specific rule.

@param Game *game: the game where the rule is.
@param Id id: the id of the rule you want.

@return Rule *: the rule you want or NULL on error.
*/
Rule * game_get_rule(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
    return NULL;
  }

  /* Look for the rule you want */
  for(i=0; i < MAX_RULES && rules(game)[i] != NULL; i++){
    if(id == rule_get_id(rules(game)[i])){
      return rules(game)[i];
    }
  }
    
  return NULL;
}

/**
@date 18-12-2016 
@author Alejandro Sanchez

@brief game_get_person
Gives a specific person.

@param Game *game: the game where the person is.
@param Id id: the id of the person you want.

@return Person *: the person you want or NULL on error.
*/
Person * game_get_person(Game *game, Id id){
  int i;

  if(!game || id == NO_ID){ /* Check that the inputs are not empty */
    return NULL;
  }

  /* Look for the person you want */
  for(i=0; i < MAX_PEOPLE && people(game)[i] != NULL; i++){
    if(id == person_get_id(people(game)[i])){
      return people(game)[i];
    }
  }
    
  return NULL;
}

/**
@date 03-12-2016 
@author Adrián Fernández

@brief game_set_player_location
Sets a location of a player.

@param Game *game: the game where the player is.
@param int player: number of the player.
@param Id location: the location you want for the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_player_location(Game *game, int player, Id location){
  Player *ply = NULL;

  if(!game || player < 0 || location == NO_ID){ /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Get the player */
  ply = game_get_player_at_position(game, player);
  
  /* Set its location */
  return player_set_location(ply, location);
}
 

/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_set_object_location
Sets a location for an object.

@param Game *game: the game where the object is.
@param Id id: the location you want for the object.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_object_location(Game *game, Id object, Id location){
  Object *obj = NULL;

  if(!game || object == NO_ID || location == NO_ID){  /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Get the object */
  obj = game_get_object(game, object);
  
  /* Set its location */
  return object_set_location(obj, location);
}



/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief game_get_object_location
Gives the location of the object.

@param Game *game: the game where the object is.
@param Id object: the id of the object you want its location.

@return Id: the location of the object or NO_ID on error.
*/
Id game_get_object_location(Game *game, Id object){
  Object *obj = NULL;

  if(!game || object == NO_ID){ /* Check that the inputs are not empty */
    return NO_ID;
  }

  /* Get the object */
  obj = game_get_object(game, object);

  /* Get its location */
  return object_get_location(obj);
}

/**
@date 18-12-2016 
@author Alejandro Sanchez

@brief game_set_person_location
Sets a location for an person.

@param Game *game: the game where the person is.
@param Id location: the location you want for the person.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ game_set_person_location(Game *game, Id person, Id location){
  Person *per = NULL;

  if(!game || person == NO_ID || location == NO_ID){  /* Check that the inputs are not empty */
    return ERROR_;
  }

  /* Get the person */
  per = game_get_person(game, person);
  
  /* Set its location */
  return person_set_location(per, location);
}

/**
@date 18-12-2016 
@author Alejandro Sanchez

@brief game_get_person_location
Gives the location of the person.

@param Game *game: the game where the person is.
@param Id person: the id of the person you want its location.

@return Id: the location of the person or NO_ID on error.
*/
Id game_get_person_location(Game *game, Id person){
  Person *per = NULL;

  if(!game || person == NO_ID){ /* Check that the inputs are not empty */
    return NO_ID;
  }

  /* Get the person */
  per = game_get_person(game, person);

  /* Get its location */
  return person_get_location(per);
}


/**
@date 11-11-2016 
@author Alejandro Sanchez

@brief game_spaces_are_linked
Checks if there is a link between two spaces.

@param Game *game: the game where the link and spaces are.
@param Space *space1: one of the spaces you want to know if is linked.
@param Space *space2: the other space you want to know if is linked.
@return BOOL_: TRUE_ if the spaces are linked and FALSE_ in other cases. 
*/
BOOL_ game_spaces_are_linked(Game *game, Space *space1, Space *space2){
  Id aux1, aux2, id_space1, id_space2;
  int i = 0, flag = 0;

  if(!game || !space1 || !space2){
    return FALSE_;
  }

  id_space1 = space_get_id(space1);
  id_space2 = space_get_id(space2);

  while(1 < MAX_LINKS && flag == 0){
    aux1 = link_get_space1(links(game)[i]);
    if(aux1 == id_space1){
      aux2 = link_get_space2(links(game)[i]);
        if(aux2 == id_space2){
          flag = 1;
        } 
    } else if(aux1 == id_space2){
        aux2 = link_get_space2(links(game)[i]);
        if(aux2 == id_space1){
          flag = 1;
        } 
    }
    i++;
  }

  if(flag == 0){
    return FALSE_;
  }

  return TRUE_;
}

/**
@date 13-11-2016 
@author Alejandro Sanchez

@brief game_is_link_open
Checks if a link of the game is open or not.

@param Game *game: the game where the link is.
@param Id link: the identifier of the link to check.
             
@return BOOL_: TRUE_ is the link is open or FALSE_ if not.
*/
BOOL_ game_is_link_open(Game *game, Id link){
  Link *lnk = NULL;

  if(!game || link == NO_ID){
    return FALSE_;
  }

  /* Get the link */
  lnk = game_get_link(game, link);

  /* Check if the link is open or not */
  return link_is_open(lnk);
}



/*!< Callbacks implementation for each action */

/**
@date 04-11-2016 
@author Alejandro Sanchez

@brief callback_UNKNOWN
No actions. It is used when the command is UNKOWN.

@param Game *game: the game.

@return STATUS_: ERROR_, because this command can't be typed.
*/
STATUS_ callback_UNKNOWN(Game *game){
  return ERROR_;
}



/** 
@date 04-11-2016 
@author Alejandro Sanchez

@brief callback_QUIT
No actions. It is used when the command is QUIT.

@param Game *game: the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_QUIT(Game *game){
  if(!game){
    return ERROR_;
  }
  
  return OK_;
}



/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_CATCH
Catches an object from a space. It is used when the command is CATCH.

@param Game *game: the game.
@param char *arg: the name of the object to catch.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_CATCH(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Set *set = NULL;
  Object *object = NULL;
  Space *space = NULL;
  char text[WORD_SIZE]="";
  
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
    return ERROR_;
  } 
  
  /* Get player location */
  space_id = game_get_player_location(game, player);
  space = game_get_space(game, space_id); 

  /* Checks if the is space is dark */
  if (space_is_illuminated(space) == FALSE_){
    sprintf(text, " The space is dark, you can not see anything.\n");
    game_set_text(game, text);
    return ERROR_;
  } 
  
  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR_;
  }

  if(space_is_shop(spaces(game)[aux]) == TRUE_){
    return ERROR_;
  }

  /* Get the set of objects from that space */
  set = space_get_object(spaces(game)[aux]);
  if(!set){ /* Check that there is at least one object on that space */
    return ERROR_;
  }
  
  /* Get the number of objects on that space */
  count = set_get_count(set);

  /* Look for the object to catch */
  i = 0;
  while(i < count && flag == 1){
    object_id = set_get_object_at_position(set, i);
    object = game_get_object(game, object_id);
    if(strcmp(arg, object_get_name(object)) == 0){
      flag = 0;
    }
    i++;
  }
  


  if(flag == 1){  /* Check that the object was found */
    return ERROR_;
  }

  /* Set to the player the object with name "arg" which is on that space */
  if(player_add_object(players(game)[player], object_id) == ERROR_){
    return ERROR_;
  }

  /* Delete that object from that space */
  if(space_del_object(spaces(game)[aux], object_id) == ERROR_){
    return ERROR_;
  }

  /* Set that the object is held by a player */
  game_set_object_location(game, object_id, NO_ID);

  return OK_; 
} 


/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_LEAVE
Leaves an object on a space. It is used when the command is LEAVE.

@param Game *game: the game.
@param char *arg: the name of the object to leave.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_LEAVE(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Inventory *inv = NULL;
  Object *object = NULL;
  Space *space = NULL;
  char text[WORD_SIZE]="";
 
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
    return ERROR_;
  } 

  /* Get the objects that the player have */
  inv = player_get_inventory(players(game)[player]);
  if(!inv){ /* Check that the player has at least one object */
    return ERROR_;
  }

  /* Get player location */
  space_id = game_get_player_location(game, player);
  space = game_get_space(game, space_id); 

  /* Checks if the is space is dark */
  if (space_is_illuminated(space) == FALSE_){
    sprintf(text, " The space is dark, you can not see anything.\n");
    game_set_text(game, text);
    return ERROR_;
  }  

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR_;
  }

  if(space_is_shop(spaces(game)[aux]) == TRUE_){
    return ERROR_;
  }

  /* Get the number of objects of the player */
  count = inventory_get_count(inv);

  /* Look for the object to leave */
  i = 0;
  while(i < count && flag == 1){
    object_id = set_get_object_at_position(inventory_get_bag(inv), i);
    object = game_get_object(game, object_id);
    if(strcmp(arg, object_get_name(object)) == 0){
      flag = 0;
    }
    i++;
  }

  if(flag == 1){  /* Check that the object was found */
    return ERROR_;
  }

  /* Set the object to the space */
  if(space_add_object(spaces(game)[aux], object_id) == ERROR_){
    return ERROR_;
  }

  /* Set that the player does not have that object */
  if(player_del_object(players(game)[player], object_id) == ERROR_){
    return ERROR_;
  }

  /* Set that the object is on that space */
  game_set_object_location(game, object_id, space_id);

  return OK_;
}



/**
@date 05-11-2016 
@author Guillermo Rodriguez

@brief callback_GO
Moves the player to a new space. It is used when the command 
is GO.

@param Game *game: the game.
@param char *arg: the direction you want to move the player.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_GO(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, auxl = NO_ID, i = 0, flag = 0;
  Id space_id, space_id2, link_id;

  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
    return ERROR_;
  } 
  
  /* Get player location */
  space_id = game_get_player_location(game, player); 
  if(space_id == NO_ID){  /* Check if it has worked */
    return ERROR_;
  }

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR_;
  }
  
  if(!strcmp(arg, "north") || !strcmp(arg, "n")){
    link_id = space_get_north(spaces(game)[aux]);
  } else if(!strcmp(arg, "south") || !strcmp(arg, "s")){
     link_id = space_get_south(spaces(game)[aux]);  
  } else if(!strcmp(arg, "west") || !strcmp(arg, "w")){
     link_id = space_get_west(spaces(game)[aux]); 
  } else if(!strcmp(arg, "east") || !strcmp(arg, "e")){
     link_id = space_get_east(spaces(game)[aux]); 
  } else if(!strcmp(arg, "up") || !strcmp(arg, "u")){
     link_id = space_get_up(spaces(game)[aux]); 
  } else if(!strcmp(arg, "down") || !strcmp(arg, "d")){
     link_id = space_get_down(spaces(game)[aux]); 
  } else{
      return ERROR_;
  }

  /* If there is not link connection */
  if(link_id == NO_ID){
    return ERROR_; 
  }

  /* Find the space with the same link*/
  i = 0;
  flag = 0;
  while(i < MAX_LINKS && flag == 0){
    if(link_id == link_get_id(links(game)[i])){
      auxl = i;
      flag = 1;
    }
    i++;
  }
  
  
  if(auxl == NO_ID){ /* Check that the link was found */
    return ERROR_;
  }
  
  space_id2 = link_get_space2(links(game)[auxl]);

  /* Check that the link is open */
  if(link_is_open(links(game)[auxl]) == TRUE_){
    game_set_player_location(game, player, space_id2);
    return OK_; 
  }

  return ERROR_; 
}



/**
@date 04-11-2016 
@author Guillermo Rodriguez

@brief callback_ROLL
Rolls a die of the game. It is used when the command is ROLL.

@param Game *game: the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_ROLL(Game *game){
  /* Check that the input is not empty and the die exists */
  if(!game || !die(game)){  
    return ERROR_;
   }
    
  /* Roll the die */  
  die_roll(die(game));

  return OK_;
}


/**
@date 02-12-2016 
@author Ricardo Riol

@brief callback_INSPECT
Tells the space's or object's information. It is used when the command is INSPECT.

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_INSPECT(Game *game, char *arg, int player){
  Space *space = NULL;
  Object *obj = NULL;
  Inventory *inv = NULL;
  Set *set_inv = NULL, *set_spc = NULL;
  Id id_space = NO_ID;
  int flag, i, illuminated = 0;
  char *description = NULL;
  char aux[WORD_SIZE] = "";

  /* Check that the inputs are not empty */
  if (!game || !arg || player < 0){
    return ERROR_;
  }

  id_space = game_get_player_location(game, player);
  space = game_get_space(game, id_space);   
  set_spc = space_get_object(space);

  inv = player_get_inventory(players(game)[player]);
  set_inv = inventory_get_bag(inv);

  if (space_is_illuminated (space) == TRUE_){
    illuminated = 1;
  } 

  /* Check if you want a space description or an object description */
  if(!strcmp (arg, "s") || !strcmp (arg, "space")){ /* space */
    description = space_get_printdesc(space);

    if (illuminated == 1){
      for (i=0; i < set_get_count(set_spc);i++){
        obj = game_get_object(game, set_get_object_at_position(set_spc, i));
        if (object_is_hidden(obj)==TRUE_){
          object_set_hidden(obj, FALSE_);
        } 
      }
      sprintf (aux, "%s The space is illuminated.\n", description);
    } else {
      sprintf (aux, "%s You can't see anything.\n", description);
    }

    if (!game_set_text(game, aux)){
      return ERROR_;
    }

    return OK_;

    } else {  /* object */
      for(i=0, flag=0; i < set_get_count(set_inv) && flag == 0; i++){
          obj = game_get_object(game, set_get_object_at_position(set_inv, i));
          if(!strcmp(object_get_name(obj), arg)){
            flag = 1;
          }
      }
    if(flag == 0){
      for(i=0, flag=0;i < set_get_count(set_spc) && flag == 0; i++){
        obj = game_get_object(game, set_get_object_at_position(set_spc, i));
        if(!strcmp(object_get_name(obj), arg)){
          flag = 1;
        }
      }
    }
  }


  if (illuminated == 0){
    sprintf(aux, " Error, the space is not iluminated.\n");
    if (!game_set_text(game, aux)){
      return ERROR_;
    }
    return OK_;
  }
 

  if (flag == 1 && illuminated == 1){
    sprintf(aux, "%s.\n", object_get_printdesc(obj));
    if (!game_set_text(game, aux)){
      return ERROR_;
    }
    return OK_;
  }

  sprintf(aux, " Error, the object has not been found.\n");
  if (!game_set_text(game, aux)){
    return ERROR_;
  }

  return ERROR_;
}


/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_TURNON
Turns on an object. It is used when the command is TURNON.

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_TURNON(Game *game, char *arg, int player){
  Id id_space = NO_ID;
  Object *obj = NULL;
  Inventory *inv = NULL;
  Set *set_inv = NULL;
  int flag, i;
  char aux[WORD_SIZE] = "";
  Space *space = NULL;

  /* Check that the inputs are not empty */
  if (!game || !arg || player < 0){
    return ERROR_;
        }

  id_space = game_get_player_location(game, player);
        space = game_get_space(game, id_space);

  inv = player_get_inventory(players(game)[player]);
  set_inv = inventory_get_bag(inv);
  for(i=0, flag=0; i < set_get_count(set_inv) && flag == 0; i++){
    obj = game_get_object(game, set_get_object_at_position(set_inv, i));
    if(!strcmp(object_get_name(obj), arg)){
      flag = 1;
    }
  }

  if (flag == 1){
    if(object_can_light(obj)){
      object_set_on(obj, TRUE_);
      space_set_illumination(space, TRUE_);
    }
    return OK_;
  } 
    
  sprintf(aux, "Error when you try to turn on an object.\n");
  if (!game_set_text(game, aux)){
    return ERROR_;
  }
  return ERROR_;
}


/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_TURNOFF
Turns on an object. It is used when the command is TURNOFF.

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_TURNOFF(Game *game, char *arg, int player){
  Id id_space = NO_ID;
  Object *obj = NULL;
  Inventory *inv = NULL;
  Set *set_inv = NULL;
  int flag, i;
  char aux[WORD_SIZE] = "";
  Space *space = NULL;
  BOOL_ il = TRUE_;

  /* Check that the inputs are not empty */
  if (!game || !arg || player < 0){
    return ERROR_;
  }
  
  id_space = game_get_player_location(game, player);
        space = game_get_space(game, id_space);
  il = space_is_illuminated(space);

  inv = player_get_inventory(players(game)[player]);
  set_inv = inventory_get_bag(inv);
  for(i=0, flag=0; i < set_get_count(set_inv) && flag == 0; i++){
    obj = game_get_object(game, set_get_object_at_position(set_inv, i));
    if(!strcmp(object_get_name(obj), arg)){
      flag = 1;
    }
  }

  if (flag == 1){
    if(object_can_light(obj)){
      object_set_on(obj, FALSE_);
      space_set_illumination(space, il);
    }
    return OK_;
  } 
    
  sprintf(aux, " Error when you try to turn off an object.\n");
  if (!game_set_text(game, aux)){
    return ERROR_;
  }
  return ERROR_;
}

/**
@date 02-12-2016 
@author Guillermo Rodriguez

@brief callback_OPENL
Opens a link. It is used when the command is OPENL.

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_OPENL(Game *game, char *arg, char *arg2, int player){
  Space *space = NULL;
  Object *obj = NULL;
  Inventory *inv = NULL;
  Set *set_inv = NULL;
  Id id_space = NO_ID, id_link = NO_ID;
  int flag, i, count;
  char aux[WORD_SIZE] = "";

  /* Check that the inputs are not empty */
  if (!game || !arg || !arg2 || player < 0){
    return ERROR_;
  }
  
  id_space = game_get_player_location(game, player);
  space = game_get_space(game, id_space);
 
  if(!strcmp(arg, "north") || !strcmp(arg, "n")){
    id_link = space_get_north(space);
  } else if(!strcmp(arg, "south") || !strcmp(arg, "s")){
    id_link = space_get_south(space);
  } else if(!strcmp(arg, "east") || !strcmp(arg, "e")){
    id_link = space_get_east(space);
  } else if(!strcmp(arg, "west") || !strcmp(arg, "w")){
    id_link = space_get_west(space);
  } else if(!strcmp(arg, "up") || !strcmp(arg, "u")){
    id_link = space_get_up(space);
  } else if(!strcmp(arg, "down") || !strcmp(arg, "d")){
    id_link = space_get_down(space);
  } else {
    return ERROR_;
  }

  inv = player_get_inventory(players(game)[player]);
  set_inv = inventory_get_bag(inv);
  count = set_get_count(set_inv);
  for(i=0, flag=0; i < count && flag == 0; i++){
    obj = game_get_object(game, set_get_object_at_position(set_inv, i));
    if(!strcmp(object_get_name(obj), arg2)){
      flag = 1;
    }
  }
  

  if (flag == 1 && object_can_open(obj) != NO_ID){
    for(i=0, flag=0; i < MAX_LINKS && links(game)[i] != NULL && flag == 0; i++){
        if(link_get_id(links(game)[i]) == id_link && space_is_linked_by(space, link_get_id(links(game)[i]))){
          flag = 1;
        }
    }
  }

  if(flag == 1){ 
    if(link_set_state(links(game)[i-1], OPEN) == OK_){
      return OK_;
    }
  }

  sprintf(aux, " Error when you try to open a link.\n");
  if (!game_set_text(game, aux)){
    return ERROR_;
  }
  return ERROR_;
} 


/**
@date 16-12-2016 
@author Alejandro Sanchez
@brief callback_SAVE
Makes a save of the game. It is used when the command is SAVE.
@param Game *game: the game.
@param char *path: the path of the file to make the save of the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_SAVE(Game *game, char *path){
  /* Check that the inputs are not empty */
  if(!game || !path){ 
    return ERROR_;
  }
    
  /* Save the game */ 
  return game_save(game, path);
}


/**
@date 16-12-2016 
@author Alejandro Sanchez
@brief callback_LOAD
Loads a save of the game. It is used when the command is LOAD.
@param Game *game: the game.
@param char *path: the path of the file to load the save of the game.
@param int die: die of the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_LOAD(Game *game, char *path, int die){
  /* Check that the inputs are not empty */
  if(!game || !path){ 
    return ERROR_;
  }

  game_destroy(game);

  game = game_init_from_file(path, die, FALSE_);
  if(!game){
    return ERROR_;
  }

  return OK_;
}


/**
@date 18-12-2016 
@author Guillermo Rodriguez

@brief callback_BUY
Buy an object from a shop. It is used when the command is BUY.

@param Game *game: the game.
@param char *arg: the name of the object to buy.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_BUY(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, aux2 = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Set *set = NULL;
  Object *object = NULL;
  double price = 0,money = 0,quit = 0;
  Space *space = NULL;
  char text[WORD_SIZE]= "";
  
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
    return ERROR_;
  } 
  
  /* Get player location */
  space_id = game_get_player_location(game, player);
  space = game_get_space(game, space_id); 

  /* Checks if the is space is dark */
  if (space_is_illuminated(space) == FALSE_){
    sprintf(text, " The space is dark, you can not see anything.\n");
    game_set_text(game, text);
    return ERROR_;
  }  
  
  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR_;
  }

  if(space_is_shop(spaces(game)[aux]) == FALSE_){
    return ERROR_;
  }

  /* Get the set of objects from that space */
  set = space_get_object(spaces(game)[aux]);
  if(!set){ /* Check that there is at least one object on that space */
    return ERROR_;
  }
  
  /* Get the number of objects on that space */
  count = set_get_count(set);

  /* Look for the object to buy */
  i = 0;
  while(i < count && flag == 1){
    object_id = set_get_object_at_position(set, i);
    object = game_get_object(game, object_id);
    if(strcmp(arg, object_get_name(object)) == 0){
      flag = 0;
    }
    i++;
  }

  if(flag == 1){  /* Check that the object was found */
    return ERROR_;
  }

  i = 0;
  flag = 0;
  while(i < MAX_OBJECTS && flag == 0){
    if(object_id == object_get_id(objects(game)[i])){
      aux2 = i;
      flag = 1;
    }
    i++;
  }


  if(aux2 == NO_ID){ /* Check that the space was found */
    return ERROR_;
  }
  

  /* Get the price of the object */
  price = object_get_price(objects(game)[aux2]);

  /* Get the money of the player */
  money = player_get_money(players(game)[player]);
  /* Check if the player has enough money to buy the object */
  if(money < price){ 
    return ERROR_;
  }
  
  /* Remove the price of the object from the money of the player who buys the object */
  quit -= price;
  if(player_set_money(players(game)[player],quit) == ERROR_){
    return ERROR_;
  }

  /* Set to the player the object with name "arg" which is on that space */
  if(player_add_object(players(game)[player], object_id) == ERROR_){
    return ERROR_;
  }

  /* Delete that object from that space */
  if(space_del_object(spaces(game)[aux], object_id) == ERROR_){
    return ERROR_;
  }

  /* Set that the object is held by a player */
  game_set_object_location(game, object_id, NO_ID);

  return OK_; 
} 


/**
@date 18-12-2016 
@author Guillermo Rodriguez

@brief callback_SELL
Sells an object to a shop . It is used when the command is SELL.

@param Game *game: the game.
@param char *arg: the name of the object to sell.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_SELL(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, aux2 = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  double price = 0;
  Inventory *inv = NULL;
  Object *object = NULL;
  Space *space = NULL;
  char text[WORD_SIZE]="";
 
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
    return ERROR_;
  } 

  /* Get the objects that the player have */
  inv = player_get_inventory(players(game)[player]);
  if(!inv){ /* Check that the player has at least one object */
    return ERROR_;
  }

  /* Get player location */
  space_id = game_get_player_location(game, player);
  space = game_get_space(game, space_id); 

  /* Checks if the is space is dark */
  if (space_is_illuminated(space) == FALSE_){
    sprintf(text, " The space is dark, you can not see anything.\n");
    game_set_text(game, text);
    return ERROR_;
  }  

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR_;
  }

  if(space_is_shop(spaces(game)[aux]) == FALSE_){
    return ERROR_;
  }

  /* Get the number of objects of the player */
  count = inventory_get_count(inv);

  /* Look for the object to sell */
  i = 0;
  while(i < count && flag == 1){
    object_id = set_get_object_at_position(inventory_get_bag(inv), i);
    object = game_get_object(game, object_id);
    if(strcmp(arg, object_get_name(object)) == 0){
      flag = 0;
    }
    i++;
  }

  if(flag == 1){  /* Check that the object was found */
    return ERROR_;
  }

  /* Get the price of the object */
  i = 0;
  flag = 0;
  while(i < MAX_OBJECTS && flag == 0){
    if(object_id == object_get_id(objects(game)[i])){
      aux2 = i;
      flag = 1;
    }
    i++;
  }


  if(aux2 == NO_ID){ /* Check that the space was found */
    return ERROR_;
  }
  price = object_get_price(objects(game)[aux2]);
   
  /* Set the money to the player who sells the object */
  if(player_set_money(players(game)[player],price) == ERROR_){
    return ERROR_;
  }

  /* Set the object to the space */
  if(space_add_object(spaces(game)[aux], object_id) == ERROR_){
    return ERROR_;
  }

  /* Set that the player does not have that object */
  if(player_del_object(players(game)[player], object_id) == ERROR_){
    return ERROR_;
  }

  /* Set that the object is on that space */
  game_set_object_location(game, object_id, space_id);

  return OK_;
}




/**
@date 18-12-2016 
@author Guillermo Rodriguez

@brief callback_ANSWER
Answer to a question . It is used when the command is ANSWER.

@param Game *game: the game.
@param char *arg: the answer of a question.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_ANSWER(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, choicef=-1;
  Id space_id,rule_id,person_id;
  char *choice;
  Space *space = NULL;
  char text[WORD_SIZE]= "";
  
 
  /* Check that the inputs are not empty */
  if(!game || !arg){
    return ERROR_;
  } 

  if(strcmp(arg,"yes") == 0 || strcmp(arg,"y") == 0){
    choicef = 0; 
  }
  
  if(strcmp(arg,"no") == 0 || strcmp(arg,"n") == 0){
    choicef = 1;
  }
  
  /* Check if the argument is right */
  if(choicef ==-1){
    return ERROR_;
  }
   
  
  /* Get player location */
  space_id = game_get_player_location(game, player);
  space = game_get_space(game, space_id); 

  /* Checks if the is space is dark */
  if (space_is_illuminated(space) == FALSE_){
    sprintf(text, " The space is dark, you can not see anything.\n");
    game_set_text(game, text);
    return ERROR_;
  }  

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR_;
  }
  
  /*Check if the space has a rule*/
  rule_id = space_get_rule(spaces(game)[aux]);
  person_id = space_get_person(spaces(game)[aux]);
  aux = NO_ID;
  i = 0;
  flag = 0;
  while(i < MAX_RULES && flag == 0){
    if(rule_id == rule_get_id(rules(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }
  
  /* If the space has a rule*/
  if(aux != NO_ID){
    if(choicef == 0){
      choice = rule_get_choice1(rules(game)[aux]);
      game_set_keyboard(game, FALSE_);
      return game_set_answer(game, choice);
    } else if(choicef == 1){
      choice = rule_get_choice2(rules(game)[aux]);
      game_set_keyboard(game, FALSE_);
      return game_set_answer(game, choice);
    }

    return ERROR_;
  }
  

  /* If the space has not a rule, check if the person in the space has a rule */
  if(NO_ID == person_id){
    return ERROR_;
  }

  aux = NO_ID;
  i = 0;
  flag = 0;
  while(i < MAX_PEOPLE && flag == 0){
    if(person_id == person_get_id(people(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the person was found */
    return ERROR_;
  }

  
  rule_id = person_get_rule(people(game)[aux]);
  if(rule_id == NO_ID){
    return ERROR_;
  }

  /* Find the rule of the person*/
  aux = NO_ID;
  i = 0;
  flag = 0;
  while(i < MAX_RULES && flag == 0){
    if(rule_id == rule_get_id(rules(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux != NO_ID){
    if(choicef == 0){
      choice = rule_get_choice1(rules(game)[aux]);  
      game_set_keyboard(game, FALSE_);
      return game_set_answer(game, choice); 
    } else if(choicef == 1){
      choice = rule_get_choice2(rules(game)[aux]);
      game_set_keyboard(game, FALSE_);
      return game_set_answer(game, choice);
    }
    return ERROR_;
  }

  return ERROR_;
}

/**
@date 21-12-2016 
@author Guillermo Rodriguez

@brief callback_TALK
Talk with a person . It is used when the command is TALK.

@param Game *game: the game.
@param int player: number of the player.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_TALK(Game *game, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0;
  Id space_id,rule_id,person_id;
  char *question;
  Space *space = NULL;
  char text[WORD_SIZE] = "";
  

  /* Get player location */
  space_id = game_get_player_location(game, player);
  space = game_get_space(game, space_id); 

  /* Checks if the is space is dark */
  if (space_is_illuminated(space) == FALSE_){
    sprintf(text, " The space is dark, you can not see anything.\n");
    game_set_text(game, text);
    return ERROR_;
  } 

  if(space_id == NO_ID){
    return ERROR_;
  } 

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return ERROR_;
  }
  
  person_id = space_get_person(spaces(game)[aux]);
  
  aux = NO_ID;
  i = 0;
  flag = 0;
  while(i < MAX_PEOPLE && flag == 0){
    if(person_id == person_get_id(people(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }
  rule_id = person_get_rule(people(game)[aux]);
   
  /* Find the rule of the person*/
  aux = NO_ID;
  i = 0;
  flag = 0;
  while(i < MAX_RULES && flag == 0){
    if(rule_id == rule_get_id(rules(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){
    return ERROR_;
  }
  
  question = rule_get_question(rules(game)[aux]);
  if(!question){
    return ERROR_;
  }

  if(ERROR_ == game_add_text(game,question)){ 
    return ERROR_;
  }
  return OK_;
}


/** 
@date 21-12-2016 
@author Alejandro Sanchez

@brief callback_NEXT
It is used to change turn. It is used when the command is NEXT.

@param Game *game: the game.
@param int *player: the number of the player.
@param int num: the number of players of the game.

@return STATUS_: OK_ if you do the operation well and ERROR_ in other cases.
*/
STATUS_ callback_NEXT(Game *game, int *player, int num){
  if(!game || !player || num < 0){
    return ERROR_;
  }
  
  *player = (*player + 1)%num;

  return OK_;
}
