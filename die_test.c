/**
   @file die_test.c
   @version 1.0
   @date 18-10-2016 
   @author Guillermo Rodriguez and Alejandro Sanchez

   @brief It tests the operation of "die.c".

   @version Oct. 18, 2016  Version 1.0 (initial release)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "die.h"


int main(){
	Die *die = NULL;
  Id id = 1;
  int count = 0;

  srand(time(NULL));

  printf("Testing die:\n");

  die = die_create(id);
  if(!die){
  	printf("Error when you create a die\n");
    count++;
  }

  if(die_destroy(die) == _ERROR){
	  printf("Error when you destroy a die\n");
    count++;
  }

  /* You must always point the pointer to NULL when you free it */
  die = NULL;

  if(die_destroy(die) == _OK){
    printf("Error when you try to destroy a die two times\n");
    count++;
  }
  
  /* You must always point the pointer to NULL when you free it */
  die = NULL;

  die = die_create(id);
  if(!die){
  	printf("Error when you init a die\n");
    count++;
  }

  if(die_roll(die) == _ERROR){
		 printf("Error when you try to roll a die\n");
    count++;
	}
  
  if(die_get_value(die) < 1 || die_get_value(die) > 6){
    printf("Error when you try to get the last die value\n");
    count++;
  }

  if(die_print(die) == _ERROR){
		 printf("Error when you try to print a die\n");
    count++;
	}
  
  if(die_roll(die) == _ERROR){
     printf("Error when you try to roll a die\n");
    count++;
  }
  
  if(die_get_value(die) < 1 || die_get_value(die) > 6){
    printf("Error when you try to get the last die value\n");
    count++;
  }

  if(die_print(die) == _ERROR){
     printf("Error when you try to print a die\n");
    count++;
  }

  if(die_destroy(die) == _ERROR){
	  printf("Error when you destroy a die\n");
    count++;
  }

  if(die_roll(die) == _ERROR){
     printf("Error when you try to roll a die\n");
    count++;
  }
  
  if(die_get_value(die) < 1 || die_get_value(die) > 6){
    printf("Error when you try to get the last die value\n");
    count++;
  }
  
  if(die_print(die) == _ERROR){
     printf("Error when you try to print a die\n");
    count++;
  }
  /* You must always point the pointer to NULL when you free it */
  die = NULL;

  if(die_get_value(die) != -1){
    printf("Error when you try to get the last die value\n");
    count++;
  }

  if(count == 0){
    printf("Everything is correct\n");
  } else{
    printf("There have been %d errors\n", count);
  }  

  return 0;
}
























