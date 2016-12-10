/**
@file graphicengine_test.h
@version 1.0
@date 09-12-2016
@author Adrián Fernández

@brief
Contains the declaration of the functions used to test the screen data type.

@version
  Dec. 9, 2016 Version 1.0 (initial release)
*/

Screen * screen_create();

STATUS screen_destroy(Screen *scr);

STATUS screen_refresh(Screen *scr);

STATUS screen_print(Screen *scr);

STATUS screen_add_window(Screen *scr, Window *win);

STATUS screen_del_window(Screen *scr);

Window * screen_get_window(Screen *scr, int n);

Window * window_create(int nrows, int ncols, int begin_y, int begin_x);

STATUS window_destroy(Window *win);

STATUS window_refresh(Window *win);

STATUS window_print(Window * win);

int window_get_x(Window *win);

int window_get_y(Window *win);

int window_get_hight(Window *win);

int window_get_weight(Window *win);

STATUS window_set_text(Window *win, char *text);

char * window_get_text(Window *win);

char * screen_get_input(Window *win, char *input);
