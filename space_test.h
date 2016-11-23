/* ===================================================================
File: space_test.h
Version: 2.0
Date: Nov. 12, 2016
Authors: Adrián Fernández

Description:
    Contains the headers of the functions used to test the functions
    implemented in space.c.

Revision history:
    Nov. 23, 2016: Version 2.0 (initial release)
=================================================================== */

#ifndef LINK_TEST_H
#define LINK_TEST_H

#include "space.h"

#define FUNCTION_IS_CORRECT(x)\
    if(x){\
        fprintf(stdout,"%s %d %s OK\n", __FILE__, __LINE__, __FUNCTION__);\
    } else{\
        (fprintf(stdout,"%s %d %s ERROR\n", __FILE__, __LINE__, __FUNCTION__));\
    }


/*** Public functions description ***/

void space_create_test1();

void space_create_test2();

void space_destroy_test1();

void space_destroy_test2();

void space_get_id_test1();

void space_get_id_test2();

void space_set_name_test1();

void space_set_name_test2();

void space_set_name_test3();

void space_get_name_test1();

void space_get_name_test2();

void space_set_north_test1();

void space_set_north_test2();

void space_set_north_test3();

void space_get_north_test1();

void space_get_north_test2();

void space_set_south_test1();

void space_set_south_test2();

void space_set_south_test3();

void space_get_south_test1();

void space_get_south_test2();

void space_set_east_test1();

void space_set_east_test2();

void space_set_east_test3();

void space_get_east_test1();

void space_get_east_test2();

void space_set_west_test1();

void space_set_west_test2();

void space_set_west_test3();

void space_get_west_test1();

void space_get_west_test2();

void space_add_object_test1();

void space_add_object_test2();

void space_add_object_test3();

void space_del_object_test1();

void space_del_object_test2();

void space_del_object_test3();

void space_get_object_test1();

void space_get_object_test2();

void space_is_object_test1();

void space_is_object_test2();

void space_is_object_test3();

void space_set_desc_test1();

void space_set_desc_test2();

void space_set_desc_test3();

void space_get_desc_test1();

void space_get_desc_test2();

void space_set_gdesc_test1();

void space_set_gdesc_test2();

void space_set_gdesc_test3();

void space_get_gdesc_test1();

void space_get_gdesc_test2();

void space_print_test1();

void space_print_test2();

void space_print_gdesc_test1();

void space_print_gdesc_test2();

#endif
