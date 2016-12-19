/**
@file command.c
@version 5.1
@date 18-12-2016 
@author Guillermo Rodriguez and Alejandro Sanchez

@brief
It implements the command interpreter.
@version Sept. 23, 2016  Version 2.0 
	Commented the file.
@version Oct. 08, 2016 Version 2.1
	Added commands CATCH and LEAVE.	
@version Oct. 14, 2016 Version 2.2
	Added command JUMP.
@version Oct. 28, 2016 Version 3.0
	Created structure "Command".
	Added command ROLL.
@version Oct. 30, 2016 Version 3.1
	Created functions for ADT Command.
@version Nov. 04, 2016 Version 3.2
	Modified "get_user_input".
@version Nov. 05, 2016 Version 4.0
	Added command GO and removed commands NEXT, BACK and JUMP.
@version Dec. 8, 2016 Version 5.0
	Added commands TURNOFF, TURNON, OPENL, SAVE, LOAD.
@version Dec. 18, 2016 Version 5.1
	Added commands BUY, SELL, ANSWER.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"

/**
@def Constant values description 
*/
#define cmd(X) (X)->cmd
#define arg(X) (X)->arg
#define arg2(X) (X)->arg2

/**
@brief Command structure
Stores information of the different commands that can be used in the game
*/
struct _Command{
	T_Command cmd;	/*!< Type of command */
	char arg[CMD_LENGTH];	/*!< Input argument */
  char arg2[CMD_LENGHT]; /*!< Input argument for command open */
};


/*!< Public functions definition */

/**
@brief get_user_input
Interprets the user's input. 
Input must be typed: 
 <command><blank space><argument> (space and argument only if needed)

@date 05-11-2016 
@author Ricardo Riol
@param 

@return Command *: interpretation of user's input or NULL on error.
*/

Command * get_user_input(int flag,char* answer){
	Command *command = NULL;
	char input[CMD_LENGTH] = "", aux[CMD_LENGTH] = "";
	char *toks = NULL, *cmd = NULL,*cmd2 = NULL,*arg = NULL,*arg2 = NULL;


  command = command_create();
  if(!command){   /* Check if memory has been allocated */
    return NULL;
  }
  
  
  /* Receive user's input from keyboard */
  if (flag == 0){
		fgets(input, CMD_LENGTH, stdin);
  }
 
  /* Receive the answer of the question */
  if (flag == 1){
  	strcpy(input,answer);
  }
  /* Check that the user has entered at least 1 character */		
  if(strcmp(input, "\n") == 0 || strcmp(input, "") ){
    cmd(command) = NO_CMD;
    return command;
  }
  
  /* "Tokenize" input */
  /* Delete \n because it's always read at the end of the line */ 
  if(flag == 0){
  	toks = strtok(input, "\n");
  }
  else{
  	strcpy(toks,input); 
  }
  
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
      cmd(command) = UNKNOWN;
      return command;
    }*/
    if(!strcmp(cmd, "c") || !strcmp(cmd, "catch") || !strcmp(cmd, "grab")){
      cmd(command) = CATCH; /* "Catch" case */;
      strcpy(arg(command), arg);
    } else if(!strcmp(cmd, "l") || !strcmp(cmd, "leave")){    
        cmd(command) = LEAVE; /* "Leave" case */
        strcpy(arg(command), arg);
    }  else if(!strcmp(cmd, "b") || !strcmp(cmd, "buy")){
        cmd(command) = BUY; /* "Buy" case */;
        strcpy(arg(command), arg);
		} else if(!strcmp(cmd, "s") || !strcmp(cmd, "sell")){
        cmd(command) = SELL; /* "Sell" case */;
        strcpy(arg(command), arg);
    } else if(!strcmp(cmd, "a") || !strcmp(cmd, "answer")){
        cmd(command) = ANSWER ; /* "Sell" case */;
        strcpy(arg(command), arg);
    } 
      else if(!strcmp(cmd, "i") || !strcmp(cmd, "inspect")){    
        cmd(command) = INSPECT; /* "Inspect" case */
        strcpy(arg(command), arg);
 		}
      else if(!strcmp(cmd, "turnon")){    
        cmd(command) = TURNON; /* "Turnon" case */
        strcpy(arg(command), arg);
		}
      else if(!strcmp(cmd, "turnoff")){    
        cmd(command) = TURNOFF; /* "Turnoff" case */
        strcpy(arg(command), arg);
    } else if(!strcmp(cmd, "g") || !strcmp(cmd, "go")){
				cmd(command) = GO;    /* "Go" case*/
        strcpy(arg(command),arg);
    } else if(!strcmp(cmd, "open")){
        cmd2 = strtok(aux, " ");
        if(!strcmp(cmd2, "with")){
        	strcpy(arg(command), arg);
        	arg2 = strtok(aux, " ");
        	strcpy(arg2(command), arg2);
        	cmd(command) = OPENL;  /* "Openl" case*/
        }
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



/**
@brief command_create
Creates a command.

@date 30-10-2016 
@author Alejandro Sanchez
@param 
@return Command *: the command created or NULL on error.
*/

Command * command_create(){
  Command *command = NULL;

  command = (Command *)malloc(sizeof(Command));
  if(!command){   /* Check if memory has been allocated */
    return NULL;
  }

  /* Initialize structure fields */
  cmd(command) = NO_CMD;
  arg(command)[0] = '\0';
  arg2(command)[0] = '\0';
  return command;
}



/**
@brief command_destroy
Destroys a command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command to destroy.
@return _STATUS: _ERROR if the input is NULL and _OK otherwise.
*/

_STATUS command_destroy(Command *command){
  if(!command){   /* Check that the input is not empty */
    return _ERROR;
  }

  free(command);    /* Eliminate the memory of the command */

  return _OK;
}


/**
@brief command_get_cmd
Returns the type of the command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command which you want the type of.
@return T_Command: the command's type or NO_CMD on error.
*/
T_Command command_get_cmd(Command *command){
  if(!command){   /* Check that the input is not empty */
    return NO_CMD;
  }

  return cmd(command);
}



/**
@brief command_get_arg
Gives the information of the argument of the command.

@date 30-10-2016 
@author Alejandro Sanchez
@param Command *command: the command that you want to know the argument.

@return char *: the argument of the command or NULL on error.
*/
char * command_get_arg(Command *command){
  if(!command){   /* Check that the input is not empty */
    return NULL;
  }

  return arg(command);
}


/**
@brief command_get_arg2
Gives the information of the second argument of the command.

@date 02-12-2016 
@author Guillermo Rodriguez
@param Command *command: the command that you want to know the second argument.

@return char *: the  second argument of the command or NULL on error.
*/
char * command_get_arg2(Command *command){
  if(!command){   /* Check that the input is not empty */
    return NULL;
  }

  return arg2(command);
}





