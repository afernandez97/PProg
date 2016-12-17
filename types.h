/**
@file types.h
@version 1.0
@date 13-01-2015
@authors Profesores PPROG

@brief 
It defines common types.

@version
	Jan. 13, 2015  Version 1.0 (initial release)
*/

#ifndef TYPES_H
#define TYPES_H

/**
@def Macros
Definition of the macros used.
*/
#define WORD_SIZE 1000
#define NO_ID -1

/**
@brief Data types
Implementation of the data types used.
*/
typedef long Id;

typedef enum {
  _FALSE, _TRUE
} _BOOL;

typedef enum {
  _ERROR, _OK
} _STATUS;

typedef enum {
  N, S, E, W
} DIRECTION;

#endif
