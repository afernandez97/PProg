/**
@file dialogue.c
@version 1.0
@date 12-12-2016 
@author Ricardo Riol

@brief
It implements the command's comments. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dialogue.h"
#include "command.h"


/**
@def Constant values description 
*/
#define error_command_act(X) (X)->error_command_act
#define error_command_prev(X) (X)->error_command_prev
#define text(X) (X)->text
#define command_act(X) (X)->command_act
#define command_prev(X) (X)->command_prev

/*!< Data structures definition */
/**
@brief dialogue struct
The Dialogue struct contains the different Dialogues's fields.
*/
struct _Dialogue{
	STATUS_ error_command_act; /*!< Check if the act command has been done succesfully */
	STATUS_ error_command_prev; /*!< Check if the prev command had been done succesfully */
	char text[WORD_SIZE]; /*!< Text to print */
	Command *command_act; /*!< The actual command */
	Command *command_prev; /*!< The previous command  */
};

/**
@brief dialogue_create
Creates a dialogue.

@date 14-12-2016 
@author Ricardo Riol
@param 
@return Dialogue*: the dialogue created or NULL on error.
*/
Dialogue* dialogue_create(){
	Dialogue *dialogue = NULL;

	dialogue = (Dialogue*) malloc (sizeof (Dialogue));
	if (!dialogue){
		return NULL;
	}

	error_command_act(dialogue) = OK_;
	error_command_prev(dialogue) = OK_;
	text(dialogue)[0] = '\0';
	command_act(dialogue) = NULL;
	command_prev(dialogue) = NULL;

	return dialogue;
}

/**
@brief dialogue_destroy
Destroys a dialogue.

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue to destroy.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/
STATUS_ dialogue_destroy(Dialogue *dialogue){

	if (!dialogue){
		return ERROR_;
	}
    command_destroy(command_prev(dialogue));
	free(dialogue);
	return OK_;
}

/**
@brief dialogue_get_command_act
Gets the actual command of the game

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return Command*: The actual command of the game.
*/
Command* dialogue_get_command_act (Dialogue *dialogue){
	if (!dialogue){
		return NULL;
	}

	return command_act(dialogue);
}

/**
@brief dialogue_get_command_prev
Gets the previously command of the game

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return Command*: The previously command of the game.
*/
Command* dialogue_get_command_prev (Dialogue *dialogue){
	if (!dialogue){
		return NULL;
	}

	return command_prev(dialogue);
}

/**
@brief dialogue_set_command_act
Sets the actual command of the game

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
Command* : The command that we want to set in the dialogue.
Status : Tells us if the command has been done sucessfully.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/
STATUS_ dialogue_set_command_act (Dialogue *dialogue, Command *command, STATUS_ status){
	if (!dialogue || !command){
		return ERROR_;
	}
	command_act(dialogue) = command;
	error_command_act(dialogue) = status;

	return OK_;
}

/**
@brief dialogue_set_command_prev
Sets teh previously command of the game.
@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
Command* : The command that we wnat to set in the dialogue.
Status : Tells us if the command has been done sucessfully.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/
STATUS_ dialogue_set_command_prev (Dialogue *dialogue, Command *command, STATUS_ status){
    if (!dialogue){
		return ERROR_;
	}
    command_destroy(command_prev(dialogue));
    command_prev(dialogue) = command_create();
    if (command_prev(dialogue)==NULL){
        return ERROR_;
    }
    command_set_cmd(command_prev(dialogue), command_get_cmd(command));
    command_set_arg (command_prev(dialogue), command_get_arg(command));
	error_command_prev(dialogue) = status;

	return OK_;
}

/**
@brief dialogue_get_text
Gets the string of the dialogue

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return char*: The text of the dialogue.
*/
char * dialogue_get_text (Dialogue* dialogue){
	if (!dialogue){
		return NULL;
	}

	return text(dialogue);
}

/**
@brief dialogue_set_text
Sets the string of the dialogue

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return STATUS_: ERROR_ if the input is NULL and OK_ otherwise.
*/
STATUS_ dialogue_set_text (Dialogue *dialogue){
	T_Command cmd_act;
	char *arg = NULL, *arg2 = NULL, *arg_prev = NULL;
	T_Command cmd_prev;
	if (!dialogue){
		return ERROR_;
	}

	cmd_act = command_get_cmd (command_act(dialogue));
	arg = command_get_arg (command_act(dialogue));
	arg2 = command_get_arg2 (command_act(dialogue));

	cmd_prev = command_get_cmd (command_prev(dialogue));
	arg_prev = command_get_arg (command_prev(dialogue));

	switch(cmd_act){
    case UNKNOWN:
    	sprintf (text(dialogue), " This is not a valid action.Try again.\n");
      break;
    case QUIT:
    	sprintf (text(dialogue), " Ending Game.\n");
      break;
    case CATCH:
    	if (error_command_act(dialogue)==OK_){
    		sprintf(text(dialogue), " Well done!!!.You have cought the object %s.\n", arg);
    	}
    	else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
    		sprintf (text(dialogue), " You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == ERROR_){
    		sprintf (text(dialogue), " You can not catch the object %s.\n", arg);
    	}
    	break;

    case LEAVE:
      	if (error_command_act(dialogue)==OK_){
    		sprintf(text(dialogue), " Well done!!!.You have left the object %s.\n", arg);
    	}
    	else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
    		sprintf (text(dialogue), " You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == ERROR_){
    		sprintf (text(dialogue), " You can not leave the object %s.\n", arg);
    	}
      	break;

    case GO:
      	if (error_command_act(dialogue)==OK_){
    		sprintf(text(dialogue), " You have gone %s.\n", arg);
    	}
    	else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
    		sprintf (text(dialogue), " You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == ERROR_){
    		sprintf (text(dialogue), " You can not go %s.\n", arg);
    	}
      	break;

    case ROLL:
     	if (error_command_act(dialogue)==OK_){
    		sprintf(text(dialogue), " You have rolled the die!!!.\n");
    	}
    	else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev){
    		sprintf (text(dialogue), " You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == ERROR_){
    		sprintf (text(dialogue), " You can not roll the die, try again.\n");
    	}
      	break;  			  
    case INSPECT:
      	if (error_command_act(dialogue)==OK_){
    		sprintf(text(dialogue), " You have inspected the actual spaces.\n");
    	}
    	else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
    		sprintf (text(dialogue), " You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == ERROR_){
    		sprintf (text(dialogue), " You can not inspect this space.\n");
    	}
      	break;

    case TURNON:
      	if (error_command_act(dialogue)==OK_){
    		sprintf(text(dialogue), " Well done!!!.You have turned on %s", arg);
    	}
    	else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
    		sprintf (text(dialogue), " You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == ERROR_){
    		sprintf (text(dialogue), " You can not turn on %s.\n", arg);
    	}
      	break;

    case TURNOFF:
      	if (error_command_act(dialogue)==OK_){
    		sprintf(text(dialogue), " Well done!!!.You have turned off %s", arg);
    	}
    	else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
    		sprintf (text(dialogue), " You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == ERROR_){
    		sprintf (text(dialogue), " You can not turn off %s.\n", arg);
    	}
      	break;

    case OPENL:
      	if (error_command_act(dialogue)==OK_){
    		sprintf(text(dialogue), " Well done!!!.You have opened the link %s with object %s", arg, arg2);
    	}
    	else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
    		sprintf (text(dialogue), " You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == ERROR_){
    		sprintf (text(dialogue), " You can not open the link %s.You have used an invalid object.\n", arg);
    	}
      	break;

    case LOAD:
        if (error_command_act(dialogue)==OK_){
            sprintf(text(dialogue), " You have LOAD the game succesfully.\n");
        }
        else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
            sprintf (text(dialogue), " You have done this action before without success.\n");
        }
        else if (error_command_act(dialogue) == ERROR_){
            sprintf (text(dialogue), " You can not load the game .\n");
        }
        break;

    case SAVE:
        if (error_command_act(dialogue)==OK_){
            sprintf(text(dialogue), " You have SAVED the game succesfully.\n");
        }
        else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
            sprintf (text(dialogue), " You have done this action before without success.\n");
        }
        else if (error_command_act(dialogue) == ERROR_){
            sprintf (text(dialogue), " You can not saved the game.\n");
        }
        break;        
    
    case BUY:
        if (error_command_act(dialogue)==OK_){
            sprintf(text(dialogue), " Well done!!!.You have bought %s.\n", arg);
        }
        else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
            sprintf (text(dialogue), " You have done this action before without success.\n");
        }
        else if (error_command_act(dialogue) == ERROR_){
            sprintf (text(dialogue), " You can not buy %s.\n", arg);
        }
        break;

    case SELL:
        if (error_command_act(dialogue)==OK_){
            sprintf(text(dialogue), " Well done!!!.You have sold %s.\n", arg);
        }
        else if (error_command_prev(dialogue)==ERROR_ && error_command_act(dialogue)==ERROR_ && cmd_act == cmd_prev && strcmp(arg, arg_prev)==0){
            sprintf (text(dialogue), " You have done this action before without success.\n");
        }
        else if (error_command_act(dialogue) == ERROR_){
            sprintf (text(dialogue), " You can not sell %s.\n", arg);
        }
        break; 

    case ANSWER:
        break;
               
    case NO_CMD:
      	break;

    default: /* We must never arrive here */
     	 break;
	}

	return OK_;
}
