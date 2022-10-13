#ifndef SQUARESOLVER_H
#define SQUARESOLVER_H


#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*!
\file
\brief Заголовочный файл с описанием библиотечных функций
*/


struct{
    int STRING = 1;
    int CHAR = 2;
    int INT = 3;
    int DOUBLE = 4;
} TYPE_EL;


struct{
    int data_type = TYPE_EL.STRING;
    int reverse = false;
} params;


#define ASSERT(cond)\
    do {            \
	    if (!(cond))\
		    printf("\tError in line %d\n\tof the file %s\n\tcondinion (%s) is false\n", __LINE__, __FILE__, #cond);\
    } while(0)

/*!
	\brief Функция считывает целую строку, сохраняя адрес буфера, содержащего текст, в *lineptr.
	\param[in] str Указатель на копируемую строку.
    \param[in] lineptr Двойной указатель на копируемую строку.
    \param[in] stream Указатель на файловый поток.
	\return Указатель на строку назначения(NULL в случае ошибки)

    Буфер завершается null и содержит символ новой строки, если был найден разделитель для новой строки.

    Если *lineptr равно NULL, то процедура getline() будет создавать буфер для содержимого строки, который затем должен быть высвобожден программой пользователя. Как альтернатива, перед вызовом getline(), *lineptr может содержать указатель на буфер, размещенный через malloc() с размером *n байтов. Если буфер недостаточно велик для размещения всей считанной строки, то getline() изменяет размер буфера с помощью realloc(), обновляя *lineptr и *n при необходимости. В любом случае при успехном вызове *lineptr и *n будут обновлены для отражения адреса буфера и его размера соответственно.
*/

int Compare_Elements(const void* el_1, const void* el_2);

int Compare_Strings(char* str1, char* str2);

int Reversed_Compare_Strings(char* str1, char* str2);

int is_letter(int c);

#endif