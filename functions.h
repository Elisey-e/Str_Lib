#ifndef SQUARESOLVER_H
#define SQUARESOLVER_H


#include <assert.h>
#include <math.h>
#include <stdio.h>

#define ASSERT(cond)\
    do {            \
	    if (!(cond))\
		    printf("\tError in line %d\n\tof the file %s\n\tcondinion (%s) is false\n", __LINE__, __FILE__, #cond);\
    } while(0)

int PUTS(const char* line);


char* STRCHR(char* string, int symbol);


size_t STRLEN(const char* string);


char* STRCPY (char* destination, const char* source);


char* STRNCPY (char* destination, const char* source, size_t n);


char* STRCAT(char* destptr, const char* srcptr);


char* STRNCAT(char* destptr, const char* srcptr, size_t num);


char* FGETS(char* string, int num, FILE* filestream);


char* STRDUP(const char* str);


#endif