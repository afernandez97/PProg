/* ===================================================================
   File: command.h
   Version: 4.0
   Date: 04-11-2016 
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description: 
	  It defines the command interpreter.

   Revision history:
	  Sept. 23, 2016  Version 1.0 (initial release)
    Sept. 23, 2016  Version 2.0 
      Commented the file.
    Oct. 08, 2016 Version 2.1
      Added commands CATCH and LEAVE.
    Oct. 14, 2016 Version 2.2
    	Added command JUMP.
		Oct. 28, 2016 Version 3.0
			Created structure "Command".
			Added command ROLL.
    Oct. 30, 2016 Version 3.1
      Created functions for ADT Command.
    Nov. 04, 2016 Version 3.2
      Modified "get_user_input".
    Nov. 05, 2016 Version 4.0
      Added command GO and removed commands NEXT, BACK and JUMP.
   =================================================================== */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"
      
/*** Constant values description ***/
#define CMD_LENGTH 30

typedef enum enum_Command{
  NO_CMD = -2,  /* No Command */
  UNKNOWN,  /* Unknown Command */
  QUIT, /* Command to quit from the game */
  CATCH, /* Command to catch an object from a space */
  LEAVE, /* Command to leave an object on a space */
  GO,	     /* Command to go to another space */
  ROLL   /* Command to roll the die */ 
} T_Command;

/*** Data structures definition ***/
typedef struct _Command Command;


/*** Public functions description ***/
/* --------------------------------------------------------------------
   Function: get_user_input
   Date: 04-11-2016 
   Author: Alejandro Sanchez

   Description: 
    Interprets the user's input. 
    Input must be typed: 
      <command><blank space><argument> (space and argument only if needed)

   Input: 

   Output: 
    Command *: interpretation of user's input or NULL on error.
   -------------------------------------------------------------------- */
Command * get_user_input();



/* --------------------------------------------------------------------
   Function: command_create
   Date: 30-10-2016 
   Author: Alejandro Sanchez
 
   Description: 
    Creates a command.
 
   Input: 
    
   Output: 
    Command *: the command created or NULL on error.
   -------------------------------------------------------------------- */
Command * command_create();



/* --------------------------------------------------------------------
   Function: command_destroy
   Date: 30-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Destroys a command.

   Input: 
    Command *command: the command to destroy.
   Output: 
    STATUS: ERROR if the input is NULL and OK otherwise.
   -------------------------------------------------------------------- */
STATUS command_destroy(Command *command);



/* --------------------------------------------------------------------
   Function: command_get_cmd
   Date: 30-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Returns the type of the command.

   Input: 
    Command *command: the command which you want the type of.
   Output: 
    T_Command: the command's type or NO_CMD on error.
   -------------------------------------------------------------------- */
T_Command command_get_cmd(Command *command);



/* --------------------------------------------------------------------
   Function: command_get_arg
   Date: 30-10-2016 
   Author: Alejandro Sanchez

   Description: 
    Gives the information of the argument of the command.

   Input: 
    Command *command: the command that you want to know the argument.

   Output: 
    char *: the argument of the command or NULL on error.
   -------------------------------------------------------------------- */
char * command_get_arg(Command *command);

#endif
