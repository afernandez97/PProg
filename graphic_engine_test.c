/**
@file graphicengine_test.c
@version 1.0
@date 09-12-2016
@author Adrián Fernández

@brief
Contains the implementation of the functions used to test the screen data type.

@version
Dec. 9, 2016 Version 1.0 (initial release)
@version
Dec. 10, 2016 Version 1.1
  Added tests for window_add_text.
*/

#include "graphicengine_test.h"

int main(int argc, char **argv){

	int all = 1, test;

	if (argc < 2) {
		printf("Testing all:\n");
	} else {
		test = atoi(argv[1]);
		all = 0;
		printf("Testing %d:\n", test);
		if (test < 1 || test > MAX_TEST_GE) {
			printf("Unknown test\n");
			return 1; 
		}
	}

	if (all || test == 1) test1_screen_create();
	if (all || test == 2) test1_screen_destroy();
	if (all || test == 3) test2_screen_destroy();
	if (all || test == 4) test1_screen_refresh();
	if (all || test == 5) test2_screen_refresh();
	if (all || test == 6) test1_screen_print();
	if (all || test == 7) test2_screen_print();
	if (all || test == 8) test1_screen_add_window();
	if (all || test == 9) test2_screen_add_window();
	if (all || test == 10) test3_screen_add_window();
	if (all || test == 11) test1_screen_del_window();
	if (all || test == 12) test2_screen_del_window();
	if (all || test == 13) test1_screen_get_window();
	if (all || test == 14) test2_screen_get_window();
	if (all || test == 15) test1_window_create();
	if (all || test == 16) test2_window_create();
	if (all || test == 17) test3_window_create();
	if (all || test == 18) test4_window_create();
	if (all || test == 19) test5_window_create();
	if (all || test == 20) test1_window_destroy();
	if (all || test == 21) test2_window_destroy();
	if (all || test == 22) test1_window_refresh();
	if (all || test == 23) test2_window_refresh();
	if (all || test == 24) test1_window_print();
	if (all || test == 25) test2_window_print();
	if (all || test == 26) test1_window_get_x();
	if (all || test == 27) test2_window_get_x();
	if (all || test == 28) test1_window_get_y();
	if (all || test == 29) test2_window_get_y();
	if (all || test == 30) test1_window_get_height();
	if (all || test == 31) test2_window_get_height();
	if (all || test == 32) test1_window_get_weight();
	if (all || test == 33) test2_window_get_weight();
	if (all || test == 34) test1_window_set_text();
	if (all || test == 35) test2_window_set_text();
	if (all || test == 36) test3_window_set_text();
	if (all || test == 37) test1_window_add_text();
	if (all || test == 38) test2_window_add_text();
	if (all || test == 39) test3_window_add_text();
	if (all || test == 40) test1_window_get_text();
	if (all || test == 41) test2_window_get_text();

	return 0;
}

/*!< Public functions implementation */

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_create
Tests if you can successfully create a screen.

@param
@return
*/
void test1_screen_create(){
    Screen *scr = NULL;

    scr = screen_create();
    FUNCTION_IS_CORRECT(scr != NULL);
    screen_destroy(scr);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_destroy
Tests if you can successfully destroy a screen.

@param
@return
*/
void test1_screen_destroy(){
    Screen *scr = NULL;

    scr = screen_create();
    FUNCTION_IS_CORRECT(screen_destroy(scr) == OK);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_destroy
Tests if you can destroy an uninitialised screen.

@param
@return
*/
void test2_screen_destroy(){
    Screen *scr = NULL;

    FUNCTION_IS_CORRECT(screen_destroy(scr) == ERROR);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_refresh
Tests if you can successfully refresh a screen.

@param
@return
*/
void test1_screen_refresh(){
	Screen *scr = NULL;

    scr = screen_create();
    FUNCTION_IS_CORRECT(screen_refresh(scr) == OK);
	screen_destroy(scr);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_refresh
Tests if you can refresh an uninitialised screen.

@param
@return
*/
void test2_screen_refresh(){
    Screen *scr = NULL;

    FUNCTION_IS_CORRECT(screen_refresh(scr) == ERROR);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_print
Tests if you can successfully print a screen.

@param
@return
*/
void test1_screen_print(){
	Screen *scr = NULL;

    scr = screen_create();
    FUNCTION_IS_CORRECT(screen_print(scr) == OK);
	screen_destroy(scr);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_print
Tests if you can print an uninitialised screen.

@param
@return
*/
void test2_screen_print(){
    Screen *scr = NULL;

    FUNCTION_IS_CORRECT(screen_print(scr) == ERROR);
    return;	
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_add_window
Tests if you can successfully add a window to a screen.

@param
@return
*/
void test1_screen_add_window(){
	Screen *scr = NULL;
	Window *win = NULL;

	scr = screen_create();
	win = window_create();
    FUNCTION_IS_CORRECT(screen_add_window(scr, win) == OK);
	screen_destroy(scr);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_add_window
Tests if you can add a window to an uninitialised screen.

@param
@return
*/
void test2_screen_add_window(){
	Screen *scr = NULL;
	Window *win = NULL;

	win = window_create();
    FUNCTION_IS_CORRECT(screen_add_window(scr, win) == ERROR);
	window_destroy(win);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test3_screen_add_window
Tests if you can add an uninitialised window to a screen.

@param
@return
*/
void test3_screen_add_window(){
	Screen *scr = NULL;
	Window *win = NULL;

	scr = screen_create();
    FUNCTION_IS_CORRECT(screen_add_window(scr, win) == ERROR);
	screen_destroy(scr);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_del_window
Tests if you can successfully delete the last window of a screen.

@param
@return
*/
void test1_screen_del_window(){
	Screen *scr = NULL;
	Window *win = NULL;

	scr = screen_create();
	win = window_create();
	screen_add_window(scr, win);
    FUNCTION_IS_CORRECT(screen_del_window(scr) == OK);
	screen_destroy(scr);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_del_window
Tests if you can add delete the last window of an uninitialised screen.

@param
@return
*/
void test2_screen_del_window(){
	Screen *scr = NULL;

    FUNCTION_IS_CORRECT(screen_del_window(scr) == ERROR);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_screen_get_window
Tests if you can successfully get the window in position n of a screen.

@param
@return
*/
void test1_screen_get_window(){
	Screen *scr = NULL;
	Window *win = NULL;

	scr = screen_create();
	win = window_create();
	screen_add_window(scr, win);
    FUNCTION_IS_CORRECT(screen_get_window(scr, 0) != NULL);
	screen_destroy(scr);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_screen_get_window
Tests if you can get the window in position n of an uninitialised screen.

@param
@return
*/
void test2_screen_get_window(){
	Screen *scr = NULL;

    FUNCTION_IS_CORRECT(screen_get_window(scr, 0) == NULL);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_create
Tests if you can successfully create a window.

@param
@return
*/
void test1_window_create(){
	Window *win = NULL;
	int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;

	win = window_create(nrows, ncols, begin_y, begin_x);
	FUNCTION_IS_CORRECT(win != NULL);
	window_destroy(win);
	return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_create
Tests if you can create a screen if nrows isn't valid.

@param
@return
*/
void test2_window_create(){
	Window *win = NULL;
	int nrows = -1, ncols = 1, begin_y = 0, begin_x = 0;

	win = window_create(nrows, ncols, begin_y, begin_x);
	FUNCTION_IS_CORRECT(win == NULL);
	window_destroy(win);
	return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test3_window_create
Tests if you can create a screen if ncols isn't valid.

@param
@return
*/
void test3_window_create(){
	Window *win = NULL;
	int nrows = 1, ncols = -1, begin_y = 0, begin_x = 0;

	win = window_create(nrows, ncols, begin_y, begin_x);
	FUNCTION_IS_CORRECT(win == NULL);
	window_destroy(win);
	return;

}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test4_window_create
Tests if you can create a screen if begin_y isn't valid.

@param
@return
*/
void test4_window_create(){
	Window *win = NULL;
	int nrows = 1, ncols = 1, begin_y = -1, begin_x = 0;

	win = window_create(nrows, ncols, begin_y, begin_x);
	FUNCTION_IS_CORRECT(win == NULL);
	window_destroy(win);
	return;

}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test5_window_create
Tests if you can create a screen if begin_x isn't valid.

@param
@return
*/
void test5_window_create(){
	Window *win = NULL;
	int nrows = 1, ncols = 1, begin_y = 0, begin_x = -1;

	win = window_create(nrows, ncols, begin_y, begin_x);
	FUNCTION_IS_CORRECT(win == NULL);
	window_destroy(win);
	return;

}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_destroy
Tests if you can successfully destroy a window.

@param
@return
*/
void test1_window_destroy(){
    Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_destroy(win) == OK);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_destroy
Tests if you can destroy an uninitialised window.

@param
@return
*/
void test2_window_destroy(){
    Window *win = NULL;

    FUNCTION_IS_CORRECT(window_destroy(win) == ERROR);
    return;	
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_refresh
Tests if you can successfully refresh a window.

@param
@return
*/
void test1_window_refresh(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_refresh(win) == OK);
	window_destroy(win);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_refresh
Tests if you can refresh an uninitialised window.

@param
@return
*/
void test2_window_refresh(){
	Window *win = NULL;

    FUNCTION_IS_CORRECT(windown_refresh(win) == ERROR);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_print
Tests if you can successfully print a window.

@param
@return
*/
void test1_window_print(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_print(win) == OK);
	window_destroy(win);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_print
Tests if you can print an uninitialised window.

@param
@return
*/
void test2_window_print(){
	Window *win = NULL;

    FUNCTION_IS_CORRECT(windown_print(win) == ERROR);
    return;	
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_x
Tests if you can successfully get the begin_x field of a window.

@param
@return
*/
void test1_window_get_x(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_get_x(win) != -1);
	window_destroy(win);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_x
Tests if you can get the begin_x field of an uninitialised window.

@param
@return
*/
void test2_window_get_x(){
	Window *win = NULL;

    FUNCTION_IS_CORRECT(window_get_x(win) == -1);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_y
Tests if you can successfully get the begin_y field of a window.

@param
@return
*/
void test1_window_get_y(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_get_y(win) != -1);
	window_destroy(win);
    return;	
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_y
Tests if you can get the begin_y field of an uninitialised window.

@param
@return
*/
void test2_window_get_y(){
	Window *win = NULL;

    FUNCTION_IS_CORRECT(window_get_y(win) == -1);
    return;	
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_height
Tests if you can successfully get the nrows field of a window.

@param
@return
*/
void test1_window_get_height(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_get_height(win) != -1);
	window_destroy(win);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_height
Tests if you can get the nrows field of an uninitialised window.

@param
@return
*/
void test2_window_get_height(){
	Window *win = NULL;

    FUNCTION_IS_CORRECT(window_get_height(win) == -1);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_weight
Tests if you can successfully get the ncols field of a window.

@param
@return
*/
void test1_window_get_weight(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_get_weight(win) != -1);
	window_destroy(win);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_weight
Tests if you can get the ncols field of an uninitialised window.

@param
@return
*/
void test2_window_get_weight(){
	Window *win = NULL;

    FUNCTION_IS_CORRECT(window_get_weight(win) == -1);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_set_text
Tests if you can successfully set the text field of a window.

@param
@return
*/
void test1_window_set_text(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;
    char text[WORD_SIZE] = "text";

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_set_text(win, text) == OK);
    window_destroy(win);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_set_text
Tests if you can set the text field of an uninitialised window.

@param
@return
*/
void test2_window_set_text(){
	Window *win = NULL;
    char text[WORD_SIZE] = "text";

    FUNCTION_IS_CORRECT(window_set_text(win, text) == ERROR);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test3_window_set_text
Tests if you can set the text field of a window if the string is not valid.

@param
@return
*/
void test3_window_set_text(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;
    char *text = NULL;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_set_text(win, text) == ERROR);
    window_destroy(win);
    return;	
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_add_text
Tests if you can successfully add a string to the text field of a window.

@param
@return
*/
void test1_window_add_text(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;
    char text[WORD_SIZE] = "text";

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_add_text(win, text) == OK);
    window_destroy(win);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_addt_text
Tests if you can add a string to the text field of an uninitialised window.

@param
@return
*/
void test2_window_add_text(){
	Window *win = NULL;
    char text[WORD_SIZE] = "text";

    FUNCTION_IS_CORRECT(window_add_text(win, text) == ERROR);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test3_window_add_text
Tests if you can add a string to the text field of a window if the string is not valid.

@param
@return
*/
void test3_window_add_text(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;
    char *text = NULL;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_add_text(win, text) == ERROR);
    window_destroy(win);
    return;	
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test1_window_get_text
Tests if you can successfully get the text field of a window.

@param
@return
*/
void test1_window_get_text(){
	Window *win = NULL;
    int nrows = 1, ncols = 1, begin_y = 0, begin_x = 0;

    win = window_create(nrows, ncols, begin_y, begin_x);
    FUNCTION_IS_CORRECT(window_get_text(win) != NULL);
	window_destroy(win);
    return;
}

/**
@author Adrián Fernández
@date 09-12-2016

@brief test2_window_get_text
Tests if you can get the text field of an uninitialised window.

@param
@return
*/
void test2_window_get_text(){
	Window *win = NULL;

    FUNCTION_IS_CORRECT(window_get_text(win) == NULL);
    return;
}
