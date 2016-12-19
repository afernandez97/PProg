/**
@file dialogue.h
@version 1.0
@date 12-12-2016 
@author Ricardo Riol

@brief
It implements the command's comments. 
*/


#ifndef DIALOGUE_H
#define DIALOGUE_H

#include "types.h"

/**
@def Constant values description 
*/
#define MAX_DIALOGUE 1000

/*!< Data structures definition */
/**
@brief dialogue struct
The Dialogue struct contains the different Dialogues's fields.
*/
typedef struct _Dialogue Dialogue;

/*!< Public functions description */

/**
@brief dialogue_create
Creates a dialogue.

@date 14-12-2016 
@author Ricardo Riol
@param 
@return Dialogue*: the dialogue created or NULL on error.
*/
Dialogue* dialogue_create();

/**
@brief dialogue_destroy
Destroys a dialogue.

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue to destroy.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/
STATUS dialogue_destroy(Dialogue *dialogue);

/**
@brief dialogue_get_command_act
Gets the actual command of the game

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return Command*: The actual command of the game.
*/
Command* dialogue_get_command_act (Dialogue *dialogue);

/**
@brief dialogue_get_command_prev
Gets the previously command of the game

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return Command*: The previously command of the game.
*/
Command* dialogue_get_command_prev (Dialogue *dialogue);

/**
@brief dialogue_set_command_act
Sets the actual command of the game

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
Command* : The command that we want to set in the dialogue.
Status : Tells us if the command has been done sucessfully.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/
STATUS dialogue_set_command_act (Dialogue *dialogue, Command *command, STATUS status);

/**
@brief dialogue_set_command_prev
Sets teh previously command of the game.
@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
Command* : The command that we wnat to set in the dialogue.
Status : Tells us if the command has been done sucessfully.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/
STATUS dialogue_set_command_prev (Dialogue *dialogue, Command *command, STATUS status);

/**
@brief dialogue_get_cadena
Gets the string of the dialogue

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return char*: The text of the dialogue.
*/
char * dialogue_get_cadena (Dialogue* dialogue);

/**
@brief dialogue_set_cadena
Sets the string of the dialogue

@date 14-12-2016 
@author Ricardo Riol
@param Dilogue *dialogue: the dialogue.
@return STATUS: ERROR if the input is NULL and OK otherwise.
*/
STATUS dialogue_set_cadena (Dialogue *dialogue)
 




#endif


