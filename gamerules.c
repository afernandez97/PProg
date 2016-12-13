/**
   @file gamerules.c
   @version 1.0
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
    It implements a rule .
 
   @version
    Dec. 12, 2016  Version 1.0 (initial release)
  */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule.h"

/**
@def Constant values description 
*/
#define id(X) (X)->id
#define ask(X) (X)->ask
#define choice1(X) (X)->choice1
#define choice2(X) (X)->choice2


 
/** @brief The Rule structure stores information of the different rules that there are in the game */
struct _Space{
  Id id; /*!< Identifier of the rule */
  char ask[WORD_SIZE + 1]  /*!< The ask for the player*/ 
  char choice1[WORD_SIZE + 1]; /*!< The action if the player choice the first option*/ 
  char choice2[WORD_SIZE + 1]; /*!< The action if the player choice the second option*/
  
};
 
 
/*!< Public functions definition */
/**
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief Creates a rule. rule_create()
 
   @param 
    Id id: the id of the rule that is created.
   @return 
    Rule*: the rule created or NULL on error.
  */
Rule * rule_create(Id id){
  Rule * rule = NULL;
 
  if(id == NO_ID){       /* Check that the input is not empty */
    return NULL;
  }
 
  rule = (Rule *)malloc(sizeof(Rule));
  if(!rule){  /* Check if memory has been allocated */
    return NULL;
  }    
     
 
  /* Initialize structure fields */
  id(rule) = id;
 
  ask(rule)[0] = '\0';
  choice1(rule)[0] = '\0';
  choice2(rule)[0] = '\0';
  
  return rule;
}
 
 
 
/**
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Destroys a rule. rule_destroy()
 
   @param 
    Rule *rule: the rule to destroy.
   @return 
    STATUS: ERROR if the input is NULL and OK otherwise.
   */
STATUS rule_destroy(Rule * rule){
  if(!rule){         /* Check that the input is not empty */
    return ERROR;
  }
  
  free(rule);      /* Eliminate the memory of the rule */      
  
  return OK;
}




/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets the ask for the player. rule_set_ask()

   @param Rule *rule: the rule you want to change its ask.
    char *ask: the new ask of the rule.
  
   @return 
    STATUS: OK if you do the operation well and ERROR in other cases.
   */
STATUS rule_set_ask(Rule *rule, char *ask){
  if(!rule || !ask){   /* Check if the inputs are not empty */
    return ERROR;
  }

  /* Set the ask and check if it has worked */
  if(!strcpy(ask(rule), ask)){
    return ERROR;
  }  
  
  return OK;
}



/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets the first choice for the player. rule_set_choice1()

   @param Rule *rule: the rule you want to change its ask.
    char *choice1: the new first choice of the rule.
  
   @return 
    STATUS: OK if you do the operation well and ERROR in other cases.
   */
STATUS rule_set_choice1(Rule *rule, char *choice1){
  if(!rule || !choice1){   /* Check if the inputs are not empty */
    return ERROR;
  }

  /* Set the ask and check if it has worked */
  if(!strcpy(choice1(rule), choice1)){
    return ERROR;
  }  
  
  return OK;
}
 

/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets the second choice for the player. rule_set_choice2()

   @param Rule *rule: the rule you want to change its ask.
    char *choice2: the new second choice of the rule.
  
   @return 
    STATUS: OK if you do the operation well and ERROR in other cases.
   */
STATUS rule_set_choice2(Rule *rule, char *choice2){
  if(!rule || !choice2){   /* Check if the inputs are not empty */
    return ERROR;
  }

  /* Set the ask and check if it has worked */
  if(!strcpy(choice2(rule), choice2)){
    return ERROR;
  }  
  
  return OK;
}
 

/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the ask of the rule.rule_get_ask()

   @param
    Rule * rule: the rule you want to know its ask.

   @return 
    char *: the ask of the rule or NULL on error.
 */
char *rule_get_ask(Rule *rule){
  if(!rule){  /* Check that the input is not empty */
   return NULL;
  }

  return ask(rule); 
}   


/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the first choice of the rule.rule_get_choice1()

   @param
    Rule * rule: the rule you want to know its first choice.

   @return 
    char *: the first choice of the rule or NULL on error.
 */
char *rule_get_choice1(Rule *rule){
  if(!rule){  /* Check that the input is not empty */
   return NULL;
  }

  return choice1(rule); 
}   



/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the second choice of the rule.rule_get_choice2()

   @param
    Rule * rule: the rule you want to know its second choice.

   @return 
    char *: the second choice of the rule or NULL on error.
 */
char *rule_get_choice2(Rule *rule){
  if(!rule){  /* Check that the input is not empty */
   return NULL;
  }

  return choice2(rule); 
}   



/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the id of the rule.rule_get_id()

   @param
    Rule * rule: the rule you want to know its id.

   @return 
    char *: the id of the rule or NO_ID on error.
 */

Id rule_get_id(Rule *rule){
  if(!rule){       /* Check that the input is not empty */
    return NO_ID;
  }
 
  return id(rule);
}

/**
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Prints a rule on the screen.rule_print()
 
   @param 
    Rule *rule: the rule you want to print.
   @return 
    STATUS: ERROR if the input is NULL and OK otherwise.
   */
STATUS rule_print(Rule * rule){
  
  if(!rule){                   /* Check that the input is not empty */
    return ERROR;
  }
 
  /* Print each field of the Rule structure */
    fprintf(stdout, "--> Rule (Id: %ld; Ask: %s; Choice1: %s; Choice2: %s)\n", 
      id(rule), ask(rule),choice1(rule),choice2(rule));

  return OK;
}

