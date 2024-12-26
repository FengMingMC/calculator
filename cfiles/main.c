#include "calculator.h"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(936);

   while (1) {
       printScreen();
       getCommand();
   }
}

