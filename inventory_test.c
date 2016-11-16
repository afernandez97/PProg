/* ===================================================================
File: inventory_test.c
Version: 1.0
Date: Nov. 4, 2016
Authors: Ricardo Riol 

Description:
	Tests inventory's functions
Revision history:
	Nov. 4, 2016: Version 1.0 (initial release)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "set.h"

int main() {

 int contador;
 Inventory* inv=NULL;
 Set* set=NULL;

 contador = 0;

 inv = inventory_create();
 
 if (!inv){
	fpritnf(stderr, "Impossible to allocates memory for an inventory\n");
	contador++;
 }
 
 if (inventory_destroy(inv)==ERROR){
	fprintf(stderr, "Impossible to liberate the inventory variable\n");
	contador++;
 }
 
 inv = NULL;

 if (inventory_destroy(inv)==OK){
	fprintf(stderr, "Error, you destroy a non-existant inventory\n");
	contador++;
 }

 inv = inventory_create();
 
 if (!inv){
	fpritnf(stderr, "Impossible to allocates memory for an inventory\n");
	contador++;
 }

 if (inventory_set_bag(inv, set)== OK){
	fprintf(stderr, "Error, set is NULL\n");
	contador++;
 }

 set = set_create();

 if (!set){
	fprintf(stderr, "Error,set is NULL\n");
 }

 if (inventory_set_bag(inv, set)== ERROR){
	fprintf(stderr, "Error, the set should be set\n");
	contador++;
 }

 if (inventory_get_bag(inv)==NULL){
	fprintf(stderr, "Error, the set or the inventory is NULL\n");
	contador++;
 }

 if (inventory_add_object(inv, 0)==ERROR){
	fprintf (stderr, "Impossible to introduce the Id\n");
	contador++;
 }

 if (inventory_print (inv)==ERROR){
 	fprintf (stderr, "Impossibke to print the inventory\n");
 	contador++;
 }
 
 if (inventory_del_object(inv, 0)==ERROR){
	fprintf(stderr, "Impossible to delete an object\n");
	contador++;
 }
 
 if (inventory_del_object(inv, 0)==OK){
	fprintf(stderr, "There is not an object in the inventory\n");
	contador++;
 }

 if (inventory_add_object(inv, 0)==ERROR){
	fprintf (stderr, "Impossible to introduce the Id\n");
	contador++;
 }

 if (inventory_add_object(inv, 1)==ERROR){
	fprintf (stderr, "Impossible to introduce the Id\n");
	contador++;
 }
 
 if (inventory_add_object(inv, 2)==ERROR){
	fprintf (stderr, "Impossible to introduce the Id\n");
	contador++;
 }

 if (inventory_print (inv)==ERROR){
 	fprintf (stderr, "Impossibke to print the inventory\n");
 	contador++;
 }
 
 if (inventory_is_empty(Inventory *inv)==TRUE){
 	fprintf (stderr, "Error, there are some objects in the inventory\n");
 	contador++;
 }

 if (inventory_is_full(Inventory *inv)==TRUE){
 	fprintf (stderr, "Error, there are a few objects in the inventory\n");
 	contador++;
 }

if (inventory_is_object(inv, 0)==ERROR){
	printf (stderr, "Error, the object is in the inventory\n");
	contador++;
}

if (inventory_is_object(inv, 4)==OK){
	printf (stderr, "Error, the object is not in the inventory\n");
	contador++;
} 

if (inventory_destroy(inv)==ERROR){
	fprintf(stderr, "Impossible to liberate the inventory variable\n");
	contador++;
 }

if (contador == 0){
	fprintf (stdout, "Everything was correct\n");
} 

return contador;

}

