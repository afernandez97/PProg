/* ===================================================================
File: link_test.c
Version: 1.0
Date: Nov. 5, 2016
Authors:Ricardo Riol

Description:
	Contains the tests of the functions associated to the
	Link data type.
Revision history:
	Nov. 5, 2016: Version 1.0 (initial release)
=================================================================== */

#include "link.h"

int main(){

int contador;
Link* link =NULL;
contador = 0;

link = link_create(1, 2, 3);

if (!link){
	contador++;
}

if (link_destroy (link)==ERROR){
	fprintf (stderr, "Error, imposible to delete the link\n");
	contador++;
}

if (link_destroy (link)==OK){
	fprintf (stderr, "Error, imposible to delete a non-existant link\n");
	contador++;
}

link = link_create(1, 2, 3);

if (!link){
	contador++;
}

if (link_print(link)==ERROR){
	fprintf(stderr, "Imposiible to print the link\n");
	contador++;
}

if (link_get_id (link)== NO_ID){
	fprintf (stderr, "Impossible to show the link's id\n");
	contador++;
}

if (link_set_name(link, 2)==ERROR){
	fprintf (stderr, "Imposiible to change the name\n");
	contador++;
}

if (link_print(link)==ERROR){
	fprintf(stderr, "Imposiible to print the link\n");
	contador++;
}

if (link_get_name(link)==NULL){
	fprintf(stderr, "Impossible to get the link's name\n");
	contador++;
}

if (link_get_space1(link)==NO_ID){
	fprintf (stderr, "Impossible to get the space1's id\n");
	contador++;
}

if (link_get_space2(link)==NO_ID){
	fprintf (stderr, "Impossible to get the space2's id\n");
	contador++;
}

if (link_set_state (link, OPEN)==ERROR){
	fprintf (stderr, "Imposiible to set the link's state\n");
	contador++;
}

if (link_print(link)==ERROR){
	fprintf(stderr, "Imposiible to print the link\n");
	contador++;
}

if (link_get_state(link)==NO_STATE){
	fprintf (stderr, "Imposiible to get the link's state\n");
	contador++;
}

if (contador == 0){
	fprintf (stdout, "Everything was correct\n");
}

return contador;
}	