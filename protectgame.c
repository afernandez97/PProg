


/* Hay que meter Id person en la estructura de Space y en el load space para que cargue para que añada id rule y id person*/ /* y los saves y loads en el save y load general   falta #define rule(X) (x)->game en game*/ 

/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_set_person_at_position
Sets a person in a specific position.

@param Game *game: the game where the person is.
@param Person * person : the person you want to set
@param int position: the position where you want to set the person.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/






STATUS game_set_person_at_position(Game *game, Person *person, int position){
  if(!game || !person || position < 0){  /* Check that the inputs are not empty */
    return ERROR;
  }

  if(person(game)[position] != NULL){
    person_destroy(person(game)[position]);
  }

  person(game)[position] = person;

  return OK;
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
  
  return person(game)[position];
}


/**
   @date 16-12-2016 
   @author Guillermo Rodriguez
 
   @brief
    Set the person to a space. space_set_person()
 
   @param Space *space: the space where you want to change the person.
   @param Id id: the new person you want for the space.
 
   @return 
    STATUS: OK if you do the operation well and ERROR in other cases.
   */
STATUS space_set_person(Space *space, Id id){
  if(!space){             /* Check that the inputs are not empty */
    return ERROR;
  }
 
  person(space) = id;          /* Set the rule to the space */
  return OK;
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
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_add_person(Game *person, Person *person){
  int i = 0;  /* Initialize the counter */

  if(!game || !person){  /* Check that the inputs are not empty */
    return ERROR;
  }

  /* Increase the counter until finding an empty person */
  while(i < MAX_PERSON && game_get_person_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every person is not empty */
  if(i >= MAX_PERSON){
    return ERROR;
  }

  /* Set the new person */
  if(game_set_person_at_position(game,person, i) == ERROR){
    return ERROR;
	}

  return OK;
}



/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_load_person
Loads the person from a file.

@param Game *game: the game where you want to load the people .
@param char *filename: the file that contains the people.   
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS game_load_person(Game *game, char *filename){
  FILE *file = NULL;
  char name[WORD_SIZE] = "";
  Id id = NO_ID, location = NO_ID, rule = NO_ID;
  Person * person = NULL;
  Space *space = NULL;
  STATUS status = OK;	
  
  if(!game || !filename){ /* Check that the inputs are not empty */
    return ERROR;
  }
  
  file = fopen(filename, "r");   /* Open the file where the people are */
  if(!file){
    return ERROR;
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
  
  if(ferror(file)){ /* Test the error indicator for the file */ 
    status = ERROR;
  }
  
  fclose(file); /* Close the file */
  
  return status;
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_save_person
Saves the people of a game.

@param Game *game: the game you want to save its people.
@param char *filename: the filename that will contain the people of the game.   
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_save_person(Game *game, char *filename){
  FILE *f_per = NULL;
  Person *person = NULL;
  char name[WORD_SIZE] = "";
  Id id, location, rule;

  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR;
  }

  f_per = fopen(filename, "w");
  if(!f_per){
    return ERROR;
  }

  /* Print each line of the file until finding an empty person */
  while(i < MAX_PERSON && flag == 0){
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
    status = ERROR;
  }
  
  fclose(f_per);

  return status;
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_set_rule_at_position
Sets a rule in a specific position.

@param Game *game: the game where the rule is.
@param Rule * rule : the rule you want to set
@param int position: the position where you want to set the rule.

@return STATUS: OK if you do the operation well and ERROR in other cases.
*/






STATUS game_set_rule_at_position(Game *game, Rule *rule, int position){
  if(!game || !rule || position < 0){  /* Check that the inputs are not empty */
    return ERROR;
  }

  if(rule(game)[position] != NULL){
    rule_destroy(rule(game)[position]);
  }

  rule(game)[position] = rule;

  return OK;
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
  
  return rule(game)[position];
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_add_rule
Adds a rule to a game.

@param Game *game: the game where you add the rule.
@param Rule *rule: the rule you want to add to the game.  
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_add_rule(Game *game, Rule *rule){
  int i = 0;  /* Initialize the counter */

  if(!game || !rule){  /* Check that the inputs are not empty */
    return ERROR;
  }

  /* Increase the counter until finding an empty rule */
  while(i < MAX_RULE && game_get_rule_at_position(game, i) != NULL){
    i++;
  }

  /* Check if every rule is not empty */
  if(i >= MAX_RULE){
    return ERROR;
  }

  /* Set the new rule */
  if(game_set_rule_at_position(game,rule, i) == ERROR){
    return ERROR;
	}

  return OK;
}



/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_load_rules
Loads the rules from a file.

@param Game *game: the game where you want to load the rules .
@param char *filename: the file that contains the rules.   
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/

STATUS game_load_rules(Game *game, char *filename){
  FILE *file = NULL;
  char question[WORD_SIZE] = "", choice1[WORD_SIZE] = "", choice2[WORD_SIZE] = "";
  Id id = NO_ID;
  Rule * rule = NULL;	
  
  if(!game || !filename){ /* Check that the inputs are not empty */
    return ERROR;
  }
  
  file = fopen(filename, "r");   /* Open the file where the rules are */
  if(!file){
    return ERROR;
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
  
  if(ferror(file)){ /* Test the error indicator for the file */ 
    status = ERROR;
  }
  
  fclose(file); /* Close the file */
  
  return status;
}


/**
@date 16-12-2016 
@author Guillermo Rodriguez

@brief game_save_rules
Saves the rules of a game.

@param Game *game: the game you want to save its rules.
@param char *filename: the filename that will contain the rules of the game.   
@return STATUS: OK if you do the operation well and ERROR in other cases.
*/
STATUS game_save_rules(Game *game, char *filename){
  FILE *f_rul = NULL;
  Rule *rule = NULL;
  char question[WORD_SIZE] = "",choice1[WORD_SIZE] = "",choice2[WORD_SIZE] = "";
  Id id;

  if(!game || !filename){    /* Check that the inputs are not empty */
    return ERROR;
  }

  f_rul = fopen(filename, "w");
  if(!f_rul){
    return ERROR;
  }

  /* Print each line of the file until finding an empty rule */
  while(i < MAX_RULE && flag == 0){
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
    status = ERROR;
  }
  
  fclose(f_rul);

  return status;
}








