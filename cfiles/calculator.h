#pragma once
#include <stdbool.h>
#ifndef CALCULATOR_H
#define CALCULATOR_H

double calculate(char* input);
bool preCalculate(char* input);
bool preCalculate_(char* input);
void getCommand();
void printScreen();
void change();

#endif //CALCULATOR_H
