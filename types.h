/* ===================================================================
   File: types.h
   Version: 1.0
   Date: 13-01-2015
   Author: Profesores PPROG

   Description: 
		It defines common types.

   Revision history:
		Jan. 13, 2015  Version 1.0 (initial release)
   =================================================================== */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000
#define NO_ID -1

typedef long Id;

typedef enum {
  FALSE, TRUE
} BOOL;

typedef enum {
  ERROR, OK
} STATUS;

typedef enum {
  N, S, E, W
} DIRECTION;

#endif
