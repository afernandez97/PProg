/**
   @file game_rules.h
   @version 1.0
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
    It implements the game rules.
 
   @version
    Dec. 12, 2016  Version 1.0 (initial release)
*/

#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "types.h"


/**
@def Constant values description
*/
#define MAX_RULES 100

/*!< Data structures definition */
typedef struct _Rule Rule;



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
    _STATUS: _ERROR if the input is NULL and _OK otherwise.
   */
_STATUS rule_destroy(Rule *rule);


/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the id of the rule.rule_get_id()

   @param
    Rule *rule: the rule you want to know its id.

   @return 
    char *: the id of the rule or NO_ID on error.
 */

Id rule_get_id(Rule *rule);

/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets the question for the player. rule_set_question()

   @param Rule *rule: the rule you want to change its question.
    char *question: the new question of the rule.
  
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS rule_set_question(Rule *rule, char *question);



/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets the first choice for the player. rule_set_choice1()

   @param Rule *rule: the rule you want to change its first choice.
    char *choice1: the new first choice of the rule.
  
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS rule_set_choice1(Rule *rule, char *choice1);
 

/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Sets the second choice for the player. rule_set_choice2()

   @param Rule *rule: the rule you want to change its second choice.
    char *choice2: the new second choice of the rule.
  
   @return 
    _STATUS: _OK if you do the operation well and _ERROR in other cases.
   */
_STATUS rule_set_choice2(Rule *rule, char *choice2);
 

/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the question of the rule.rule_get_question()

   @param
    Rule *rule: the rule you want to know its question.

   @return 
    char *: the question of the rule or NULL on error.
 */
char * rule_get_question(Rule *rule);  


/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the first choice of the rule.rule_get_choice1()

   @param
    Rule *rule: the rule you want to know its first choice.

   @return 
    char *: the first choice of the rule or NULL on error.
 */
char * rule_get_choice1(Rule *rule);


/**
   @date 12-12-2016 
   @author Guillermo Rodriguez

   @brief 
    Gives the information of the second choice of the rule.rule_get_choice2()

   @param
    Rule *rule: the rule you want to know its second choice.

   @return 
    char *: the second choice of the rule or NULL on error.
 */
char * rule_get_choice2(Rule *rule);



/**
   @date 12-12-2016 
   @author Guillermo Rodriguez
 
   @brief 
    Prints a rule on the screen.rule_print()
 
   @param 
    Rule *rule: the rule you want to print.
   @return 
    _STATUS: _ERROR if the input is NULL and _OK otherwise.
   */
_STATUS rule_print(Rule *rule);



#endif
