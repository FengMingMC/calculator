#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define naturalConst 2.718
#define Pi 3.14159

double calculate(const char* input) {
    double number[101];
    char operation[101];
    int nIndex = 0;
    memset(number, 0, sizeof(number));
    memset(operation, 0, sizeof(operation));
    for (int i = 0; input[i] != '\0'; i++) {
        char charNumber[101];
        while ((input[i] >= '0' && input[i] <= '9')|| input[i] == '-') {
            int jIndex = 0;
            charNumber[jIndex] = input[i];
            jIndex++;
            i++;
            while ((input[i] >= '0' && input[i] <= '9') || input[i] == '.') {
                charNumber[jIndex] = input[i];
                jIndex++;
                i++;
            }
            charNumber[jIndex] = '\0';
            char *endptr;
            number[nIndex] = strtod(charNumber,&endptr);
            nIndex++;
        }
    }
    int oIndex = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '+'
            ||input[i] == '-'
            ||input[i] == '*'
            ||input[i] == '/'
            ||input[i] == '^')
        {
            operation[oIndex] = input[i];
            oIndex++;
        }
    }

    for (int i = 0; operation[i] != '\0'; i++) {
        if (operation[i] == '*') {
            // printf("%d\n", i);
            const double product = number[i] * number[i+1];
            // printf("%lf\n", product);
            number[i + 1] = product ;
            number[i] = 0;
            // printf("%lf\n", number[i]);
            // printf("%lf\n", number[i+1]);
        }else if (operation[i] == '/') {
            const double dividend = number[i] / number[i+1];
            number[i + 1] = dividend;
            number[i] = 0;
        }else if (operation[i] == '^') {
            double power = pow(number[i], number[i+1]);
            if (number[i] < 0 ) {
                if ((int)number[i+1] % 2 == 1) {
                } else {
                    power = - power;
                }
            }
            number[i + 1] = power;
            number[i] = 0;
        }
    }


    for (int i = 0; number[i] != '\0'; i++) {
        printf("%lf\n", number[i]);
    }
    double sum = 0;
    for (int i = 0; i<101; i++) {
        sum = sum + number[i];
    }

    return sum;
}