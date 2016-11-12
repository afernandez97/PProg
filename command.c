/* ===================================================================
   File: command.c
   Version: 4.0
   Date: 05-11-2016 
   Author: Guillermo Rodriguez and Alejandro Sanchez

   Description: 
    It implements the command interpreter.

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"

/* Constant values description */
#define cmd(X) (X)->cmd
#define arg(X) (X)->arg

/*** The Command structure stores information of the different commands 
that can be used in the game ***/
struct _Command{
	T_Command cmd;	/* Type of command */
	char arg[CMD_LENGTH];	/* Input argument */
};


/*** Public functions definition ***/
/* --------------------------------------------------------------------
   Function: get_user_input
   Date: 05-11-2016 
   Author: Alejandro Sanchez

   Description: 
    Interprets the user's input. 
    Input must be typed: 
      <command><blank space><argument> (space and argument only if needed)

   Input: 

   Output: 
    Command *: interpretation of user's input or NULL on error.
   -------------------------------------------------------------------- */
Command * get_user_input(){
	Command *command = NULL;
	char input[CMD_LENGTH] = "", aux[CMD_LENGTH] = "";
	char *toks = NULL, *cmd = NULL, *arg = NULL;


  command = command_create();
  if(!command){   /* Check if memory has been allocated */
    return NULL;
  }

  /* Receive user's input from keyboard */
	fgets(input, CMD_LENGTH, stdin);
  /* Check that the user has entered at least 1 character */		
  if(strcmp(input, "\n") == 0){
    cmd(command) = NO_CMD;
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
    if(strtok(NULL, "^") != NULL){
      cmd(command) = UNKNOWN;
      return command;
    }
    if(!strcmp(cmd, "c") || !strcmp(cmd, "catch")){
      cmd(command) = CATCH; /* "Catch" case */;
      strcpy(arg(command), arg);
    } else if(!strcmp(cmd, "l") || !strcmp(cmd, "leave")){    
        cmd(command) = LEAVE; /* "Leave" case */
        strcpy(arg(command), arg);
    } else if(!strcmp(cmd, "g") || !strcmp(cmd, "go")){
				cmd(command) = GO;    /* Go case*/
        strcpy(arg(command) ,arg);
		} else{                           
        cmd(command) = UNKNOWN; /* Wrong input */
    }
  } else{  /* There isn't any argument */
    	if(!strcmp(toks, "q") || !strcmp(toks, "quit")){		 	
    		cmd(command) = QUIT;		/* "Quit" case */
    	} else if(!strcmp(toks, "r") || !strcmp(toks, "roll")){
    		  cmd(command) = ROLL;		/* "Roll" case */
    	} else{ 													
    		  cmd(command) = UNKNOWN;	/* Wrong input */
    	}
  }

	return command;
}



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
Command * command_create(){
  Command *command = NULL;

  command = (Command *)malloc(sizeof(Command));
  if(!command){   /* Check if memory has been allocated */
    return NULL;
  }

  /* Initialize structure fields */
  cmd(command) = NO_CMD;
  arg(command)[0] = '\0';

  return command;
}



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
STATUS command_destroy(Command *command){
  if(!command){   /* Check that the input is not empty */
    return ERROR;
  }

  free(command);    /* Eliminate the memory of the command */

  return OK;
}


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
T_Command command_get_cmd(Command *command){
  if(!command){   /* Check that the input is not empty */
    return NO_CMD;
  }

  return cmd(command);
}



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
char * command_get_arg(Command *command){
  if(!command){   /* Check that the input is not empty */
    return NULL;
  }

  return arg(command);
}
