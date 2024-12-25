#include <stdio.h>
#include <stdbool.h>

bool preCalculate(const char* input) {
        if ((input[0] >= '0' && input[0] <= '9')|| input[0] == '-') {
        } else {
            printf("于第%d处发现错误，请检查\n", 1);
            return false;
        }
        for (int i = 0; input[i] != '\0'; i++) {
            if ((input[i] >= '0' && input[i] <= '9')
                || input[i] == '+'
                || input[i] == '-'
                || input[i] == '*'
                || input[i] == '/'
                || input[i] == '.'
                || input[i] == '^'
                || input[i] == 'e'
                || input[i] == 'p') {
                }else {
                    printf("于第%d处发现错误，请检查\n", i+1);
                    return false;
                }
        }
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == '+'
                || input[i] == '-'
                || input[i] == '*'
                || input[i] == '/'
                || input[i] == '.') {
                if (input[i+1] == '+'
                    || input[i+1] == '-'
                    || input[i+1] == '*'
                    || input[i+1] == '/'
                    || input[i+1] == '.'
                    || input[i+1] == '^'
                    || input[i+1] == 'e'
                    || input[i+1] == 'p') {
                    printf("于第%d处发现错误，请检查\n", i+2);
                    return false;
                    }
                }
        }
        return true;
    }



bool preCalculate_(const char* input) {
    if ((input[0] >= '0' && input[0] <= '9')|| input[0] == '-') {
    } else {
        return false;
    }
    for (int i = 0; input[i] != '\0'; i++) {
        if ((input[i] >= '0' && input[i] <= '9')
            || input[i] == '+'
            || input[i] == '-'
            || input[i] == '*'
            || input[i] == '/'
            || input[i] == '.') {
            }else {
                // printf("于第%d处发现错误，请检查\n", i+1);
                return false;
            }
    }
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '+'
            || input[i] == '-'
            || input[i] == '*'
            || input[i] == '/'
            || input[i] == '.') {
            if (input[i+1] == '+'
                || input[i+1] == '-'
                || input[i+1] == '*'
                || input[i+1] == '/'
                || input[i+1] == '.') {
                // printf("于第%d处发现错误，请检查2\n", i+2);
                return false;
                }
            }
    }
    return true;
}