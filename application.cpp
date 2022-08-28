#include "functions.h"


#include <iostream>
#include <cstring>
 
int main ()
{
  char lotr[] = "_-=Властелин к0лец=-_";               // строка в которой будем искать символ 0
 
  std::cout << "Ищите кольцо всевластия в LOTR!!!n";
  char * ring = strchr(lotr, '0');                     // поиск символа 0 в строке lotr
 
  std::cout << "Моя прелесть находится в "
            << (ring - lotr + 1) << " квадратеn";     // определяем позицию символа
 
  return 0;
}