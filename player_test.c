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
#include "player_test.h"

int main(int argc, char **argv){
  int test = 0, all = 1;

  if(argc < 2){
  	printf("Testing all:\n");
  } else{
    	test = atoi(argv[1]);
      all = 0;
      printf("Testing %d:\t", test);
      if(test < 1 || test > MAX_TEST){
  			printf("Unknown test\t");
        exit(EXIT_SUCCESS);
      }
    }

  if (all || test == 1)  test1_player_destroy();
  if (all || test == 2)  test1_player_get_id();
  if (all || test == 3)  test1_player_set_name();
  if (all || test == 4)  test1_player_get_name();
  if (all || test == 5)  test1_player_set_location();
  if (all || test == 6)  test1_player_get_location();
  if (all || test == 7)  test1_player_add_object();
  if (all || test == 8)  test1_player_del_object();
  if (all || test == 9)  test1_player_has_object();
  if (all || test == 10) test1_player_print();
  if (all || test == 11) test1_player_create();
  if (all || test == 12) test2_player_destroy();
  if (all || test == 13) test2_player_get_id();
  if (all || test == 14) test2_player_set_name();
  if (all || test == 15) test2_player_get_name();
  if (all || test == 16) test2_player_set_location();
  if (all || test == 17) test3_player_set_location();
  if (all || test == 18) test2_player_get_location();
  if (all || test == 19) test2_player_add_object();
  if (all || test == 20) test3_player_add_object();
  if (all || test == 21) test2_player_del_object();
  if (all || test == 22) test3_player_del_object();
  if (all || test == 23) test4_player_del_object();
  if (all || test == 24) test4_player_add_object();
  if (all || test == 25) test2_player_print();
  if (all || test == 26) test2_player_has_object();
  if (all || test == 27) test3_player_has_object();

  exit(EXIT_SUCCESS);
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
  Player *player = NULL;
	FUNCTION_IS_CORRECT(player_destroy(player) == ERROR);
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
	Player *player = NULL;
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
	Player *player = NULL;
  char name[WORD_SIZE] = "Adri";
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
	Player *player = NULL;
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
	Player *player = NULL;
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
	Player *player = NULL;
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
	Player *player = NULL;
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
	Player *player = NULL;
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
	Player *player = NULL;
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
	Player *player = NULL;
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
  Player *player = NULL;
	Id idplayer = 3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player != NULL);
  player_destroy(player);
  return;
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
  Player *player = NULL;
  Id idplayer = 3;
  player = player_create(idplayer);
	FUNCTION_IS_CORRECT(player_destroy(player) == OK);
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
	Player *player = NULL;
  Id idplayer = 3;
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
	Player *player = NULL;
  char name[WORD_SIZE] = "Adri";
  Id idplayer = 3;
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
	Player *player = NULL;
  char name[WORD_SIZE] = "Adri";
  Id idplayer = 3;
  player = player_create(idplayer);
  player_set_name(player, name);
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
	Player *player = NULL;
  Id idlocation = 345;
  Id idplayer = 3;
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
	Player *player = NULL;
  Id idlocation = NO_ID;
  Id idplayer = 3;
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
	Player *player = NULL;
  Id idlocation = 345;
  Id idplayer = 3;
  player = player_create(idplayer);
  player_set_location(player, idlocation);
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
	Player *player = NULL;
  Id idobj1 = 1;
  Id idplayer = 3;
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
	Player *player = NULL;
  Id idobj1 = NO_ID;
  Id idplayer = 3;
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
	Player *player = NULL;
  Id idobj1 = 3;
  Id idplayer = 3;
  player = player_create(idplayer);
  player_add_object(player, idobj1);
  FUNCTION_IS_CORRECT(player_del_object(player, idobj1) == OK);
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
	Player *player = NULL;
  Id idobj1 = 3;
  Id idplayer = NO_ID;
  player = player_create(idplayer);
  player_add_object(player, idobj1);
  FUNCTION_IS_CORRECT(player_del_object(player, idobj1) == ERROR);
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
	Player *player = NULL;
  Id idobj1 = 3;
  Id idplayer = 3;
  player = player_create(idplayer);
  player_add_object(player, idobj1);
  player_del_object(player, idobj1);
  FUNCTION_IS_CORRECT(player_del_object(player, idobj1) == ERROR);
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
	Player *player = NULL;
  Id idobj1 = 3;
  Id idplayer = 3;
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
	Player *player = NULL;
  Id idobj1 = 3,idobj2=5;
  Id idplayer = 3;
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
	Player *player = NULL;
  Id idobj1 = 3;
  Id idplayer = 3;
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
	Player *player = NULL;
  Id idplayer = 3;
  Id idobj1 = 3;
  player = player_create(idplayer);
  FUNCTION_IS_CORRECT(player_has_object(player,idobj1) == FALSE);
  player_destroy(player);
  return;
}





