


/* Hay que meter Id person en la estructura de Space y en el load space para que cargue para que añada id rule y id person*/ /* y los saves y loads en el save y load general   falta #define rule(X) (x)->game en game*/ 



/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief
    Set the person to a space. space_set_person()
 
   @param Space *space: the space where you want to change the person.
   @param Id id: the new person you want for the space.
 
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS space_set_person(Space *space, Id id){
  if(!space){             /* Check that the inputs are not empty */
    return _ERROR;
  }
 
  person(space) = id;          /* Set the rule to the space */
  return _OK;
}
 
 
 
/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Gives the information of the person of the space.space_get_person()
 
   @param 
    Space *space: the space you want to know the person.
 
   @return 
    Id: the person of the space or NO_ID on error.
   */
Id space_get_person(Space *space){
  if(!space){                     /* Check that the input is not empty */
    return NO_ID;
  }
 
  return person(space);
}






/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_add_person
Adds an person to a game.

@param Game *game: the game where you add the person.
@param Person *person: the person you want to add to the game.  
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS game_add_person(Game *person, Person *person){
  int i = 0;  /* Initialize the counter */

  if(!game || !person){  /* Check that the inputs are not empty */
    return _ERROR;
  }

  /* Increase the counter until finding an empty person */
  while(i < MAX_PEOPLE && game_get_person_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every person is not empty */
  if(i >= MAX_PEOPLE){
    return _ERROR;
  }

  /* Set the new person */
  if(game_set_person_at_position(game,person, i) == _ERROR){
    return _ERROR;
	}

  return _OK;
}



/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_load_people
Loads the people from a file.

@param Game *game: the game where you want to load the people.
@param char *filename: the file that contains the people.   
@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/

_STATUS game_load_people(Game *game, char *filename){
  FILE *file = NULL;
  char name[WORD_SIZE] = "";
  Id id = NO_ID, location = NO_ID, rule = NO_ID;
  Person * person = NULL;
  Space *space = NULL;
  _STATUS status = _OK;	
  
  if(!game || !filename){ /* Check that the inputs are not empty */
    return _ERROR;
  }
  
  file = fopen(filename, "r");   /* Open the file where the people are */
  if(!file){
    return _ERROR;
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
				person_set_rule(person, location);
				

	
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
    status = _ERROR;
  }
  
  fclose(file); /* Close the file */
  
  return status;
}





















