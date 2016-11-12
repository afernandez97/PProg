/* ===================================================================
   File: player_test.c
   Version: 1.0
   Date: 05-11-2016 
   Author: Guillermo Rodriguez 

   Description: 
    It tests the operation of "player.c".

   Revision history:
    Nov. 5, 2016  Version 1.0 (initial release)
   =================================================================== */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include player_test.h 

int main(int argc,char**argv){
	Player *player = NULL;
  Id idplayer = 1, idlocation = 2, wrong_id = NO_ID, idobj1 = 3, idobj2 = 4;
  int count = 0,test =0,todas = 1;
  char *name = "player1", *wrong_name = NULL;
  Inventory *inv = NULL;

  printf("Testing player:\n");
  if(arc<2){
  	printf("Pasando todas las pruebas al modulo Space :\t");
  }
  else{
  	test = atoi(argv[1]);
    todas = 0;
    printf("Pasando prueba %d:\t",test);
    if(test<1 && test > MAX_TEST){
			printf("Error prueba no reconocida");
      exit(EXIT_SUCESS);
      }
    }
if (todas || test == 1)  test1_player_destroy();
if (todas || test == 2)  test1_player_get_id();
if (todas || test == 3)  test1_player_set_name();
if (todas || test == 4)  test1_player_get_name();
if (todas || test == 5)  test1_player_set_location();
if (todas || test == 6)  test1_player_get_location();
if (todas || test == 7)  test1_player_add_object();
if (todas || test == 8)  test1_player_del_object();
if (todas || test == 9)  test1_player_has_object();
if (todas || test == 10) test1_player_print();
if (todas || test == 11) test1_player_create();
if (todas || test == 12) test2_player_destroy();
if (todas || test == 13) test2_player_get_id();
if (todas || test == 14) test2_player_set_name();
if (todas || test == 15) test2_player_get_name();
if (todas || test == 16) test2_player_set_location();
if (todas || test == 17) test3_player_set_location();
if (todas || test == 18) test2_player_get_location();
if (todas || test == 19) test2_player_add_object();
if (todas || test == 20) test3_player_add_object();
if (todas || test == 21) test2_player_del_object();
if (todas || test == 22) test3_player_del_object();
if (todas || test == 23) test4_player_del_object();
if (todas || test == 24) test4_player_add_object();
if (todas || test == 25) test2_player_print();
if (todas || test == 26) test2_player_has_object();
if (todas || test == 27) test3_player_has_object();

exit(EXIT_SUCESS);

if(player_destroy(player) == OK){
    printf("Error when you try to destroy an uninitialized player\n");
    count++;
  }

  /* You must always point the pointer to NULL when you free it */
  player = NULL;

  if(player_get_id(player) != NO_ID){
    printf("Error when you try to get the player's id from an uninitialized player\n");
    count++;
  }

  if(player_set_name(player, name) != ERROR){
    printf("Error when you try to set a name for an uninitialized player\n");
    count++;
  } 

  if(player_get_name(player) != NULL){
    printf("Error when you try to get the player's name from an uninitialized player\n");
    count++;
  }

  if(player_set_location(player, idlocation) != ERROR){
    printf("Error when you try to set a location for an uninitialized player\n");
    count++;
  } 

  if(player_get_location(player) != NO_ID){
    printf("Error when you try to get the player's location from an uninitialized player\n");
    count++;
  }  

  if(player_add_object(player, idobj1) != ERROR){
    printf("Error when you try to add an object to an uninitialized player\n");
    count++;
  }
  
  if(player_del_object(player, idobj1) != ERROR){
    printf("Error when you try to delete an object from an uninitialized player\n");
    count++;
  }

  if(player_has_object(player, idobj1) != FALSE){
    printf("Error when you try to know if there is an specific object in the bag of an uninitialized player\n");
    count++;
  }
  if(player_print(player) != ERROR){
    printf("Error when you try to print an uninitialized player\n");
    count++;
  }


  player = player_create(idplayer);
  if(!player){
    printf("Error when you init a player\n");
    count++;
  }

  if(player_destroy(player) == ERROR){
    printf("Error when you destroy a player\n");
    count++;
  }

  /* You must always point the pointer to NULL when you free it */
  player = NULL;

  if(player_destroy(player) == OK){
    printf("Error when you try to destroy a player two times\n");
    count++;
  }
  
  /* You must always point the pointer to NULL when you free it */
  player = NULL;
  
  player = player_create(idplayer);
  if(!player){
  	printf("Error when you init a player\n");
    count++;
  }

  if(player_get_id(player) == NO_ID){
    printf("Error when you try to get player's id\n");
    count++;
  }

  if(player_set_name(player, name) == ERROR){
    printf("Error when you try to set a name for a player\n");
    count++;
  }  

  if(player_set_name(player, wrong_name) != ERROR){
    printf("Error when you try to set an empty name for a player\n");
    count++;
  }  

  if(strcmp(player_get_name(player), name) != 0){
    printf("Error when you try to get the player's name\n");
    count++;
  }

  if(player_set_location(player, idlocation) == ERROR){
    printf("Error when you try to set a location for a player\n");
    count++;
  } 

  if(player_set_location(player, wrong_id) != ERROR){
    printf("Error when you try to set an empty location for a player\n");
    count++;
  }   

  if(player_get_location(player) != idlocation){
    printf("Error when you try to get the player's location\n");
    count++;
  }  

  if(player_add_object(player, idobj1) == ERROR){
		printf("Error when you try to add an object\n");
    count++;
	}

  if(player_add_object(player, wrong_id) != ERROR){
    printf("Error when you try to add an empty object\n");
    count++;
  }
  
  if(player_del_object(player, idobj1) == ERROR){
		printf("Error when you try to delete an object\n");
    count++;
	}

  if(player_del_object(player, wrong_id) != ERROR){
    printf("Error when you try to delete an empty object\n");
    count++;
  }  
  
  if(player_del_object(player, idobj1) == OK){
		printf("Error when you try to delete an object and there aren't objects in the player\n");
    count++;
	}
  
  if(player_add_object(player,idobj1) == ERROR){
		printf("Error when you try to add an object\n");
    count++;
	}
  
  if(player_add_object(player,idobj2) == ERROR){
		printf("Error when you try to add an object\n");
    count++;
	}

  if(player_add_object(player, idobj1) != ERROR){
    printf("Error when you try to add an object that is already in the bag of the player\n");
    count++;
  }

  if(player_print(player) == ERROR){
    printf("Error when you print a player\n");
    count++;
  }

  if(player_has_object(player, idobj1) != TRUE){
    printf("Error when you try to know if there is an specific object in the bag of the player\n");
    count++;
  }
  
  if(player_del(player, idobj1) == ERROR){
		printf("Error when you try to del an object\n");
    count++;
	}
  
  if(player_del(player, idobj1) != ERROR){
    printf("Error when you try to del an object that there is not in the bag of the player\n");
    count++;
  }

  if(player_has_object(player, idobj1) != FALSE){
    printf("Error when you try to know if there is an specific object in the bag of the player\n");
    count++;
  }

  if(player_destroy(player) == ERROR){
	  printf("Error when you destroy a player\n");
    count++;
  }

  /* You must always point the pointer to NULL when you free it */
  set = NULL;
  
  if(count == 0){
    printf("Everything is correct\n");
  } else{
    printf("There have been %d errors\n", count);
  }

  return 0;
}
/*** Public functions description ***/
/* --------------------------------------------------------------------
   Function: test1_player_destroy 
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors you try to destroy an uninitialized player
 
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_destroy(){
  Player * player = NULL;
	FUNCTION_IS_CORRECT(player_destroy(player)) == ERROR);
  return;
}

/* --------------------------------------------------------------------
   Function: test1_player_get_id
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's id 
   from an uninitialized player
 
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_get_id(){
	Player * player = NULL;
  FUNCTION_IS_CORRECT(player_get_id(player) == NO_ID);
  return;

}
/* --------------------------------------------------------------------
   Function: test1_player_set_name
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set a name 
   for an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_set_name(){
	Player * player = NULL;
  char name[10] = "Adri";
  FUNCTION_IS_CORRECT(player_set_name(player, name) == ERROR);
  return;

}


/* --------------------------------------------------------------------
   Function: test1_player_get_name
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's name 
   from an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_get_name(){
	Player * player = NULL;
  FUNCTION_IS_CORRECT(player_get_name(player) == NULL);
  return;

}

/* --------------------------------------------------------------------
   Function: test1_player_set_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set a location 
   for an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_set_location(){
	Player * player = NULL;
  Id idlocation = 345;
  FUNCTION_IS_CORRECT(player_set_location(player, idlocation) == ERROR);
  return;
}


/* --------------------------------------------------------------------
   Function: test1_player_get_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's location 
   from an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_get_location(){
	Player * player = NULL;
  FUNCTION_IS_CORRECT(player_get_location(player) == NO_ID);
  return;
}


/* --------------------------------------------------------------------
   Function: test1_player_add_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to add an object to 
   an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_add_object(){
	Player * player = NULL;
  Id idobj1 = 1;
  FUNCTION_IS_CORRECT(player_add_object(player, idobj1) == ERROR);
  return;
}

/* --------------------------------------------------------------------
   Function: test1_player_del_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to delete an object 
   from an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_del_object(){
	Player * player = NULL;
  Id idobj1 = 1;
  FUNCTION_IS_CORRECT(player_del_object(player, idobj1) == ERROR);
  return;
}

/* --------------------------------------------------------------------
   Function: test1_player_has_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to know if there is an 
   specific object in the bag of an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_has_object(){
	Player * player = NULL;
  Id idobj1 = 1;
  FUNCTION_IS_CORRECT(player_has_object(player, idobj1) == FALSE);
  return;
}

/* --------------------------------------------------------------------
   Function: test1_player_print
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to print an uninitialized player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_print(){
	Player * player = NULL;
  FUNCTION_IS_CORRECT(player_print(player) == ERROR);
  return;
}

/* --------------------------------------------------------------------
   Function: test1_player_create
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you init a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test1_player_create(){
  Player*player=NULL;
	Id idplayer =3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player !=NULL);
  player_destroy(player);
  return
}

/* --------------------------------------------------------------------
   Function: test2_player_destroy 
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors you try to destroy a player
 
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_destroy(){
  Player * player = NULL;
  Id idplayer =3;
  player = player_create(idplayer);
	FUNCTION_IS_CORRECT(player_destroy(player)) == OK);
  return;
}

/* --------------------------------------------------------------------
   Function: test2_player_get_id
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's id 
   from a player
 
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_get_id(){
	Player * player = NULL;
  Id idplayer =3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player_get_id(player) == idplayer);
  player_destroy(player);
  return;
  }



/* --------------------------------------------------------------------
   Function: test2_player_set_name
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set a name 
   for a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_set_name(){
	Player * player = NULL;
  char name[10] = "Adri";
  Id idplayer =3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player_set_name(player, name) == OK);
  player_destroy(player);
  return;

}

/* --------------------------------------------------------------------
   Function: test2_player_get_name
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's name
   Input:
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_get_name(){
	Player * player = NULL;
  char name[10] = "Adri";
  Id idplayer =3;
  player = player_create(idplayer);
  player_set_name(player, name)
  FUNCTION_IS_CORRECT(strcmp(player_get_name(player), name) == 0);
  player_destroy(player);
  return;

}


/* --------------------------------------------------------------------
   Function: test2_player_set_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set a location 
   for  a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_set_location(){
	Player * player = NULL;
  Id idlocation = 345;
  Id idplayer =3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player_set_location(player, idlocation) == OK);
  player_destroy(player);
  return;
}

/* --------------------------------------------------------------------
   Function: test3_player_set_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to set an empty 
   location for a player
   for  a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test3_player_set_location(){
	Player * player = NULL;
  Id idlocation = NO_ID;
  Id idplayer =3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player_set_location(player, idlocation) == ERROR);
  player_destroy(player);
  return;
}

/* --------------------------------------------------------------------
   Function: test2_player_get_location
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to get the player's location 
   from  a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_get_location(){
	Player * player = NULL;
  Id idlocation = 345;
  Id idplayer =3;
  player = player_create(idplayer);
  player_set_location(player, idlocation)
  FUNCTION_IS_CORRECT(player_get_location(player) != NO_ID);
  player_destroy(player);
  return;
}

/* --------------------------------------------------------------------
   Function: test2_player_add_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to add an object to 
   a player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_add_object(){
	Player * player = NULL;
  Id idobj1 = 1;
  Id idplayer =3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player_add_object(player, idobj1) == OK);
  player_destroy(player);
  return;
}



/* --------------------------------------------------------------------
   Function: test3_player_add_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to add an empty object
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test3_player_add_object(){
	Player * player = NULL;
  Id idobj1 = NO_ID;
  Id idplayer =3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player_add_object(player, idobj1) == ERROR);
  player_destroy(player);
  return;
}


/* --------------------------------------------------------------------
   Function: test2_player_del_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to delete an object
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_del_object(){
	Player * player = NULL;
  Id idobj1 = 3;
  Id idplayer =3;
  player = player_create(idplayer);
  player_add_object(player, idobj1);
  FUNCTION_IS_CORRECT(player_del_object(player, idobj1) == OK));
  player_destroy(player);
  return;
}



/* --------------------------------------------------------------------
   Function: test3_player_del_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you try to delete an empty object
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test3_player_del_object(){
	Player * player = NULL;
  Id idobj1 = 3;
  Id idplayer = NO_ID;
  player = player_create(idplayer);
  player_add_object(player, idobj1);
  FUNCTION_IS_CORRECT(player_del_object(player, idobj1) == ERROR));
  player_destroy(player);
  return;
}


/* --------------------------------------------------------------------
   Function: test4_player_del_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to delete an object 
   and there aren't objects in the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test4_player_del_object(){
	Player * player = NULL;
  Id idobj1 = 3;
  Id idplayer = 3;
  player = player_create(idplayer);
  player_add_object(player, idobj1);
  player_del_object(player, idobj1);
  FUNCTION_IS_CORRECT(player_del_object(player, idobj1) == ERROR));
  player_destroy(player);
  return;
}

/* --------------------------------------------------------------------
   Function: test4_player_add_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to add an object that 
   is already in the bag of the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test4_player_add_object(){
	Player * player = NULL;
  Id idobj1 = 3;
  Id idplayer =3;
  player = player_create(idplayer);
  player_add_object(player, idobj1);
  FUNCTION_IS_CORRECT(player_add_object(player, idobj1) == ERROR);
  player_destroy(player);
  return;
}


/* --------------------------------------------------------------------
   Function: test2_player_print
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors  when you print a player
   is already in the bag of the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_print(){
	Player * player = NULL;
  Id idobj1 = 3,idobj2=5;
  Id idplayer =3;
  player = player_create(idplayer);
  player_add_object(player, idobj1);
  player_add_object(player, idobj2);
  FUNCTION_IS_CORRECT(player_print(player) == OK);
  player_destroy(player);
  return;
}


/* --------------------------------------------------------------------
   Function: test2_player_has_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to know if there 
   is an specific object in the bag of the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */
void test2_player_has_object(){
	Player * player = NULL;
  Id idobj1 = 3;
  Id idplayer =3;
  player = player_create(idplayer);
  player_add_object(player, idobj1);
  FUNCTION_IS_CORRECT(player_has_object(player,idobj1) == TRUE);
  player_destroy(player);
  return;
}

/* --------------------------------------------------------------------
   Function: test3_player_has_object
   Date: 05-10-2016 
   Author: Guillermo Rodriguez
 
   Description: 
   Check if there aren't any errors when you try to know if there is 
   an specific object in the bag of the player
   Input: 
    
 
   Output: 
    
   -------------------------------------------------------------------- */

void test3_player_has_object(){
	Player * player = NULL;
  Id idplayer =3;
  Id idobj1 = 3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player_has_object(player,idobj1) == FALSE);
  player_destroy(player);
  return;
}





