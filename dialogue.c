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

/**
@def Constant values description 
*/
#define error_command_act(X) (X)->error_command_act
#define error_command_prev(X) (X)->error_command_prev
#define cadena(X) (X)->cadena
#define command_act(X) (X)->command_act
#define command_prev(X) (X)->command_prev

/*!< Data structures definition */
/**
@brief dialogue struct
The Dialogue struct contains the different Dialogues's fields.
*/
struct _Dialogue{
	_STATUS error_command_act; /*!< Check if the act command has been done succesfully */
	_STATUS error_command_prev; /*!< Check if the prev command had been done succesfully */
	char cadena[MAX_DIALOGUE]; /*!< Text to print */
	Command *command_act; /*!< The actual command */
	Command *command_prev; /*!< The previous command  */
}

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

	error_command_act(dialogue) = _OK;
	error_command_prev(dialogue) = _OK;
	cadena (dialogue) = "";
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
@return _STATUS: _ERROR if the input is NULL and _OK otherwise.
*/
_STATUS dialogue_destroy(Dialogue *dialogue){

	if (!dialogue){
		return _ERROR;
	}

	free(dialogue);
	return;
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
		return NO_CMD;
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
		return NO_CMD;
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
@return _STATUS: _ERROR if the input is NULL and _OK otherwise.
*/
_STATUS dialogue_set_command_act (Dialogue *dialogue, Command *command, _STATUS status){
	if (!dialogue || !command){
		return _ERROR;
	}

	command_act(dialogue) = command;
	error_command_act(dialogue) = status;

	return _OK;
}

/**
@brief dialogue_set_command_prev
Sets teh previously command of the game.
@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
Command* : The command that we wnat to set in the dialogue.
Status : Tells us if the command has been done sucessfully.
@return _STATUS: _ERROR if the input is NULL and _OK otherwise.
*/
_STATUS dialogue_set_command_prev (Dialogue *dialogue, Command *command, _STATUS status){
	if (!dialogue || !command){
		return _ERROR;
	}

	command_prev(dialogue) = command;
	error_command_prev(dialogue) = status;

	return _OK;
}

/**
@brief dialogue_get_cadena
Gets the string of the dialogue

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return char*: The text of the dialogue.
*/
char * dialogue_get_cadena (Dialogue* dialogue){
	if (!dialogue){
		return NULL;
	}

	return cadena(dialogue);
}

/**
@brief dialogue_set_cadena
Sets the string of the dialogue

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return _STATUS: _ERROR if the input is NULL and _OK otherwise.
*/
_STATUS dialogue_set_cadena (Dialogue *dialogue){
	T_Command cmd_act;
	char *arg;
	T_Command cmd_prev;
	char *arg2;
	if (!dialogue){
		return _ERROR;
	}

	cmd_act = command_get_cmd (command_act(dialogue));
	arg = command_get_arg (command_act(dialogue));
	argb = command_get_arg2 (command_act(dialogue));

	cmd_prev = command_get_cmd (command_prev(dialogue));
	arg2 = command_get_arg (command_prev(dialogue));

	switch(cmd_act){
    case UNKNOWN:
    	sprintf (cadena(dialogue), "This is not a valid action.Try again.\n");
      break;
    case QUIT:
    	sprintf (cadena(dialogue), "Ending Game.\n");
      break;
    case CATCH:
    	if (error_command_act(dialogue)==_OK){
    		sprintf(cadena(Dialogue), "Well done!!!.You have cought the object %s.\n", arg);
    	}
    	else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
    		sprintf (cadena(dialogue), "You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == _ERROR){
    		sprintf (cadena(dialogue), "You can not catch the object %s.\n", arg);
    	}
    	break;

    case LEAVE:
      	if (error_command_act(dialogue)==_OK){
    		sprintf(cadena(Dialogue), "Well done!!!.You have left the object %s.\n", arg);
    	}
    	else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
    		sprintf (cadena(dialogue), "You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == _ERROR){
    		sprintf (cadena(dialogue), "You can not leave the object %s.\n", arg);
    	}
      	break;

    case GO:
      	if (error_command_act(dialogue)==_OK){
    		sprintf(cadena(Dialogue), "You have gone %s.\n", arg);
    	}
    	else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
    		sprintf (cadena(dialogue), "You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == _ERROR){
    		sprintf (cadena(dialogue), "You can not go %s.\n", arg);
    	}
      	break;

    case ROLL:
     	if (error_command_act(dialogue)==_OK){
    		sprintf(cadena(Dialogue), "You have rolled the die!!!.\n");
    	}
    	else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev){
    		sprintf (cadena(dialogue), "You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == _ERROR){
    		sprintf (cadena(dialogue), "You can not roll the die, try again.\n");
    	}
      	break;  			  
    case INSPECT:
      	if (error_command_act(dialogue)==_OK){
    		sprintf(cadena(Dialogue), "You have inspected %s.\n", arg);
    	}
    	else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
    		sprintf (cadena(dialogue), "You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == _ERROR){
    		sprintf (cadena(dialogue), "You can not inspect %s.\n", arg);
    	}
      	break;

    case TURNON:
      	if (error_command_act(dialogue)==_OK){
    		sprintf(cadena(Dialogue), "Well done!!!.You have turned on %s", arg);
    	}
    	else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
    		sprintf (cadena(dialogue), "You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == _ERROR){
    		sprintf (cadena(dialogue), "You can not turn on %s.\n", arg);
    	}
      	break;

    case TURNOFF:
      	if (error_command_act(dialogue)==_OK){
    		sprintf(cadena(Dialogue), "Well done!!!.You have turned off %s", arg);
    	}
    	else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
    		sprintf (cadena(dialogue), "You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == _ERROR){
    		sprintf (cadena(dialogue), "You can not turn off %s.\n", arg);
    	}
      	break;

    case OPENL:
      	if (error_command_act(dialogue)==_OK){
    		sprintf(cadena(dialogue), "Well done!!!.You have opened the link %s with object %s", arg, arg2);
    	}
    	else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
    		sprintf (cadena(dialogue), "You have done this action before without success.\n");
    	}
    	else if (error_command_act(dialogue) == _ERROR){
    		sprintf (cadena(dialogue), "You can not open the link %s.You have used an invalid object.\n", arg);
    	}
      	break;

    case LOAD:
        if (error_command_act(dialogue)==_OK){
            sprintf(cadena(dialogue), "You have LOAD the game succesfully.\n");
        }
        else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
            sprintf (cadena(dialogue), "You have done this action before without success.\n");
        }
        else if (error_command_act(dialogue) == _ERROR){
            sprintf (cadena(dialogue), "You can not load the game .\n");
        }
        break;

    case SAVE:
        if (error_command_act(dialogue)==_OK){
            sprintf(cadena(dialogue), "You have SAVED the game succesfully.\n");
        }
        else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
            sprintf (cadena(dialogue), "You have done this action before without success.\n");
        }
        else if (error_command_act(dialogue) == _ERROR){
            sprintf (cadena(dialogue), "You can not saved the game.\n");
        }
        break;        
    
    case BUY:
        if (error_command_act(dialogue)==_OK){
            sprintf(cadena(dialogue), "Well done!!!.You have bought %s.\n", arg);
        }
        else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
            sprintf (cadena(dialogue), "You have done this action before without success.\n");
        }
        else if (error_command_act(dialogue) == _ERROR){
            sprintf (cadena(dialogue), "You can not buy %s.\n", arg);
        }
        break;

    case SELL:
        if (error_command_act(dialogue)==_OK){
            sprintf(cadena(dialogue), "Well done!!!.You have sold %s.\n", arg);
        }
        else if (error_command_prev(dialogue)==_ERROR && error_command_act(dialogue)==_ERROR && cmd_act == cmd_prev && strcmp(arg, arg2)==0){
            sprintf (cadena(dialogue), "You have done this action before without success.\n");
        }
        else if (error_command_act(dialogue) == _ERROR){
            sprintf (cadena(dialogue), "You can not sell %s.\n", arg);
        }
        break; 

    case ANSWER:
        break;
               
    case NO_CMD:
      	break;

    default: /* We must never arrive here */
     	 break;
	}

	return _OK;
}
