


 /*Comentarios: Ahora command_get_user_input va a tner dos argumentos de entrada un primero entero flag para decidir si el comando le viene desde el teclado (0) o no (1) (caso answer que viene de una cadena de caracteres de rule) entonces en game loop hay que poner get_user_command_input(0,NULL). tarea del superusuario
Creo que la parte de codigo de command.c de la linea 113-117 ya no hace falta por que no dejaria user el comando open with 
Creo que el campo bought de object no es necesario porque tenemos en space un campo shop para saber si es un espacio para comprar y vender objetos o simplemete coger y dejar
Hay que añadir estos comanos al game y declaras los 3 ultimos callback en donde funciones privada y eso.Superusuario 
Adri tienes que hacer que al imprimir la pantalla salga la pregunta del espacio o en su defecto si no tiene regla el espacio la de la persona que este en el espacio.
*/
  

/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_CATCH
Catches an object from a space. It is used when the command is CATCH.

@param Game *game: the game.
@param char *arg: the name of the object to catch.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_CATCH(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Set *set = NULL;
  Object *object = NULL;
  
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
  	return _ERROR;
  } 
  
  /* Get player location */
  space_id = game_get_player_location(game, player); 

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
  	if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
    	flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return _ERROR;
  }

  if(space_is_shop(space(game)[aux]) == _TRUE){
  	return _ERROR;
  }

  /* Get the set of objects from that space */
  set = space_get_object(spaces(game)[aux]);
  if(!set){ /* Check that there is at least one object on that space */
    return _ERROR;
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
    return _ERROR;
  }

  /* Set to the player the object with name "arg" which is on that space */
  if(player_add_object(players(game)[player], object_id) == _ERROR){
    return _ERROR;
  }

  /* Delete that object from that space */
  if(space_del_object(spaces(game)[aux], object_id) == _ERROR){
    return _ERROR;
  }

  /* Set that the object is held by a player */
  game_set_object_location(game, object_id, NO_ID);

  return _OK; 
} 


/**
@date 30-10-2016 
@author Alejandro Sanchez

@brief callback_LEAVE
Leaves an object on a space. It is used when the command is LEAVE.

@param Game *game: the game.
@param char *arg: the name of the object to leave.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_LEAVE(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Inventory *inv = NULL;
  Object *object = NULL;
 
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
    return _ERROR;
  } 

  /* Get the objects that the player have */
  inv = player_get_inventory(players(game)[player]);
  if(!inv){ /* Check that the player has at least one object */
    return _ERROR;
  }

  /* Get player location */
  space_id = game_get_player_location(game, player); 

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return _ERROR;
  }

  if(space_is_shop(space(game)[aux]) == _TRUE){
  	return _ERROR;
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
    return _ERROR;
  }

  /* Set the object to the space */
  if(space_add_object(spaces(game)[aux], object_id) == _ERROR){
    return _ERROR;
  }

  /* Set that the player does not have that object */
  if(player_del_object(players(game)[player], object_id) == _ERROR){
    return _ERROR;
  }

  /* Set that the object is on that space */
  game_set_object_location(game, object_id, space_id);

  return _OK;
}




/**
@date 18-12-2016 
@author Guillermo Rodriguez

@brief callback_BUY
Buy an object from a shop. It is used when the command is BUY.

@param Game *game: the game.
@param char *arg: the name of the object to buy.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_BUY(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  Set *set = NULL;
  Object *object = NULL;
  double price = 0,money = 0,quit = 0;
  
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
  	return _ERROR;
  } 
  
  /* Get player location */
  space_id = game_get_player_location(game, player); 
  
  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
  	if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
    	flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return _ERROR;
  }

  if(space_is_shop(space(game)[aux]) == _FALSE){
  	return _ERROR;
  }

  /* Get the set of objects from that space */
  set = space_get_object(spaces(game)[aux]);
  if(!set){ /* Check that there is at least one object on that space */
    return _ERROR;
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
    return _ERROR;
  }

   price = object_get_price(objects(game)[i-1]);
   money = player_get_money(players(game)[player]);
   if (money < price){
   	return _ERROR;
   }
   quit -= price;

   /* Quit  the money to a player who buy the object*/
   if(_ERROR == player_set_money(players(game)[player],quit){
   		return _ERROR;
   }

  /* Set to the player the object with name "arg" which is on that space */
  if(player_add_object(players(game)[player], object_id) == _ERROR){
    return _ERROR;
  }

  /* Delete that object from that space */
  if(space_del_object(spaces(game)[aux], object_id) == _ERROR){
    return _ERROR;
  }

  /* Set that the object is held by a player */
  game_set_object_location(game, object_id, NO_ID);

  return _OK; 
} 


/**
@date 18-12-2016 
@author Guillermo Rodriguez

@brief callback_SELL
Sell an object on a shop . It is used when the command is SELL.

@param Game *game: the game.
@param char *arg: the name of the object to sell.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_LEAVE(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count;
  Id space_id, object_id;
  double price = 0,money = 0;
  Inventory *inv = NULL;
  Object *object = NULL;
 
  /* Check that the inputs are not empty */
  if(!game || !arg || player < 0){ 
    return _ERROR;
  } 

  /* Get the objects that the player have */
  inv = player_get_inventory(players(game)[player]);
  if(!inv){ /* Check that the player has at least one object */
    return _ERROR;
  }

  /* Get player location */
  space_id = game_get_player_location(game, player); 

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return _ERROR;
  }

  if(space_is_shop(space(game)[aux]) == _FALSE){
  	return _ERROR;
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
    return _ERROR;
  }

   price = object_get_price(objects(game)[i-1]);
   
   /* Set  the money to a player who sells the object*/
   if(_ERROR == player_set_money(players(game)[player],price){
   		return _ERROR;
   }


  /* Set the object to the space */
  if(space_add_object(spaces(game)[aux], object_id) == _ERROR){
    return _ERROR;
  }

  /* Set that the player does not have that object */
  if(player_del_object(players(game)[player], object_id) == _ERROR){
    return _ERROR;
  }

  /* Set that the object is on that space */
  game_set_object_location(game, object_id, space_id);

  return _OK;
}



/**
@date 18-12-2016 
@author Guillermo Rodriguez

@brief callback_ANSWER
Answer to a question . It is used when the command is ANSWER.

@param Game *game: the game.
@param char *arg: the answer of a question.
@param int player: number of the player.

@return _STATUS: _OK if you do the operation well and _ERROR in other cases.
*/
_STATUS callback_ANSWER(Game *game, char *arg, int player){
  /* Initialize the auxiliary variable, the counter and the flag */
  int aux = NO_ID, i = 0, flag = 0, count,choicef=-1;
  Id space_id,rule_id,person_id;
  char * choice;
  
 
  /* Check that the inputs are not empty */
  if(!game || !arg)
    return _ERROR;
  } 

  if(strcmp(arg,"YES") == 0 || strcmp(arg,"Y") == 0){
  	choicef = 0;
    
  }
  
  if(strcmp(arg,"NO") == 0 || strcmp(arg,"N") == 0){
  	choicef = 1;
  }
  
  /*The argument is not right*/

  if(choicef ==-1){
  	return _ERROR;
  }
   
   

 

  /* Get player location */
  space_id = game_get_player_location(game, player); 

  /* Look for the space where the player is */
  while(i < MAX_SPACES && flag == 0){
    if(space_id == space_get_id(spaces(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux == NO_ID){ /* Check that the space was found */
    return _ERROR;
  }
  
  /*Check if the space has a rule*/
  rule_id = space_get_rule(spaces(game)[aux]);
  person_id = space_get_person(spaces(game)[aux]);
  aux = NO_ID;
  i = 0;
  flag = 0;
  while(i < MAX_RULE && flag == 0){
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
      return get_user_input(1,choice);    
    }
    else{
    	choice = rule_get_choice2(rules(game)[aux]);
      return get_user_input(1,choice);    
    }

  }
  

  /* If the space has not a rule check if the person in the space has a rule*/

  if(NO_ID == person_id){
  	return _ERROR
  }

  aux = NO_ID;
  i = 0;
  flag = 0;
  while(i < MAX_PERSON && flag == 0){
    if(person_id == person_get_id(person(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

	if(aux == NO_ID){ /* Check that the person was found */
    return _ERROR;
  }

  
  rule_id = person_get_rule(persons(game)[aux]);
  if(rule_id == NO_ID){
  	return _ERROR;
  }
  /* Find the rule of the person*/
  aux = NO_ID;
  i = 0;
  flag = 0;
  while(i < MAX_RULE && flag == 0){
    if(rule_id == rule_get_id(rules(game)[i])){
      aux = i;
      flag = 1;
    }
    i++;
  }

  if(aux != NO_ID){
  	if(choicef == 0){
    	choice = rule_get_choice1(rules(game)[aux]);
      return get_user_input(1,choice);    
    }
    else{
    	choice = rule_get_choice2(rules(game)[aux]);
      return get_user_input(1,choice);    
    }

  }

   

  return _ERROR;
}








