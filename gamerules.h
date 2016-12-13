/**
   @file rule.h
   @version 1.0
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
    It implements a rule.
 
   @version
    Dec. 12, 2016  Version 1.0 (initial release)
*/

#ifndef RULE_H
#define RULE_H

#include "types.h"


/**
@def Constant values description
*/
#define MAX_RULES 100

/*!< Data structures definition */
typedef struct _Rules Rules;



/*!< Public functions description */

/**
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief Creates a rule. rule_create()
 
   @param 
    Id id: the id of the rule that is created.
   @return 
    Rule*: the rule created or NULL on error.
  */
Rule * rule_create(Id id);
 
 
 
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
STATUS rule_destroy(Rule * rule);




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
STATUS rule_set_ask(Rule *rule, char *ask);



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
STATUS rule_set_choice1(Rule *rule, char *choice1);
 

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
STATUS rule_set_choice2(Rule *rule, char *choice2);
 

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
char *rule_get_ask(Rule *rule);  


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
char *rule_get_choice1(Rule *rule);


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
char *rule_get_choice2(Rule *rule);


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

Id rule_get_id(Rule *rule);
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
STATUS rule_print(Rule * rule);



#endif
