/**
@file set_test.c
@version 1.0
@date 18-10-2016 
@authors Guillermo Rodriguez and Alejandro Sanchez

@brief 
It tests the operation of "set.c".

@version
Oct. 18, 2016  Version 1.0 (initial release)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

int main(){
	Set *set = NULL;
  Id id1 = 3, id2 = 4;
  int count = 0;

  printf("Testing set:\n");

  if(set_destroy(set) == OK_){
    printf("Error when you try to destroy an uninitialized set\n");
    count++;
  }

  /* You must always point the pointer to NULL when you free it */
  set = NULL;

  set = set_create();
  if(!set){
  	printf("Error when you init a set\n");
    count++;
   }
  if(set_destroy(set) == ERROR_){
	  printf("Error when you destroy a set\n");
    count++;
  }

  /* You must always point the pointer to NULL when you free it */
  set = NULL;

  if(set_destroy(set) == OK_){
    printf("Error when you try to destroy a set two times\n");
    count++;
  }
  
  /* You must always point the pointer to NULL when you free it */
  set = NULL;
  
  set = set_create();
  if(!set){
  	printf("Error when you init a set\n");
    count++;
  }

  if(set_add(set, id1) == ERROR_){
		 printf("Error when you try to add an object\n");
    count++;
	}
  
  if(set_del(set, id1) == ERROR_){
		 printf("Error when you try to delete an object\n");
    count++;
	}
  
  if(set_del(set, id1) == OK_){
		 printf("Error when you try to delete an object and there aren't objects in the set\n");
    count++;
	}
  
  if(set_is_empty(set) == FALSE_){
    printf("Error when you want to know is the set is empty\n");
    count++;
  }

  if(set_add(set, id1) == ERROR_){
		 printf("Error when you try to add an object\n");
    count++;
	}
  
  if(set_add(set, id2) == ERROR_){
		 printf("Error when you try to add an object\n");
    count++;
	}

  if(set_add(set, id1) != ERROR_){
     printf("Error when you try to add an object that is already in the set\n");
    count++;
  }

  if(set_get_count(set) != 2){
   printf("Error when you want to know the number of elements in the set\n");
    count++;
  }

  /* In the original version, we changed MAX_ID to 2 to complete the set, so 
  the function returned TRUE_ (we compare "== FALSE_") */
  if(set_is_full(set) != FALSE_){
    printf("Error when you want to know is the set is full\n");
    count++;
  }
  
  if(set_print(set) == ERROR_){
      printf("Error when you print a set\n");
    count++;
  }

  if(set_get_object_at_position(set, 1) != id2){
    printf("Error when you try to get an object from a position\n");
    count++;
  }

  if(set_get_object_at_position(set, MAX_ID) != NO_ID){
    printf("Error when you try to get an object from a position which is not in the set\n");
    count++;
  }

  if(set_is_object(set, id1) != TRUE_){
    printf("Error when you try to know if there is an specific object in the set\n");
    count++;
  }
  
  if(set_del(set, id1) == ERROR_){
		printf("Error when you try to del an object\n");
    count++;
	}
  
  if(set_del(set, id1) != ERROR_){
    printf("Error when you try to del an object that there is not in the set\n");
    count++;
  }

  if(set_is_object(set, id1) != FALSE_){
    printf("Error when you try to know if there is an specific object in the set\n");
    count++;
  }

  if(set_destroy(set) == ERROR_){
	  printf("Error when you destroy a set\n");
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



