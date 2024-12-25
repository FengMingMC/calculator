#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "calculator.h"
#include <ctype.h>

char GetChar() // 输入一个字符（非空格、非回车、ASCII码大于零）
{
    char c;
    do
    {
        c = getchar();
    } while (c == '\n' || c == ' ' || c < 0);
    return c;
}

void change()
{
    void temperature();
    void energy();
    void velocity();
    void angle();
    void change_printScreen();
    char input;
    change_printScreen();
    while (1)
    {
        input = GetChar(); // 用于输入一个字符（非空格、非回车、ASCII码大于零）

        if (toupper(input) == 'Q')
            break;
        switch (toupper(input))
        {
            case 'A':
                angle();
                break;
            case 'B':
                temperature();
                break;
            case 'C':
                energy();
                break;
            case 'D':
                velocity();
                break;
            default:
                printf("输入错误\n\n");
                change_printScreen();
                printf("1");
            // 如果输入的是其它字符，则输入错误
        }
    }
}

void change_printScreen()
{
    printf("************************\n");
    printf("*********单位转换********\n");
    printf("******A:角度 B:温度******\n");
    printf("******C:能量 D:速度******\n");
    printf("**********Q:退出*********\n");
    printf("请选择需要转换的对象:\n");
}

// 角度单位转换函数
void angle()
{
    float value, result;
    char unit;
        printf("请输入角度值和当前单位（d 表示度，r 表示弧度）：\n");
        scanf("%f %c", &value, &unit);

        switch (toupper(unit))
        {
        case 'D':
            // 度转弧度
            result = value * 3.14159265358979323846 / 180.0;
            printf("%.5f deg = %.5f rad\n", value, result);
            change_printScreen();
            break;
        case 'R':
            // 弧度转度
            result = value * 180.0 / 3.14159265358979323846;
            printf("%.5f rad = %.5f deg\n", value, result);
            change_printScreen();
            break;
        case 'Q':
            break;
        default:
            printf("输入的单位错误，请输入 d 或 r。\n");
        }
  
}

// 能量单位转换函数
void energy()
{
    float value, result;
    char unit;
    printf("请输入能量值和当前单位（j 表示焦耳，c 表示卡路里）：\n");
    scanf("%f %c", &value, &unit);
    switch (toupper(unit))
    {
    case 'J':
        // 焦耳转卡路里
        result = value / 4.184;
        printf("%.5f J = %.5f cal\n", value, result);
        change_printScreen();
        break;
    case 'C':
        // 卡路里转焦耳
        result = value * 4.184;
        printf("%.5f cal = %.5f J\n", value, result);
        change_printScreen();
        break;
    default:
        printf("输入的单位错误，请输入 J 或 cal。\n");
        change_printScreen();
    }
}

// 速度单位转换函数
void velocity()
{
    float value, result;
    char unit;
    printf("请输入速度值和当前单位（m 表示米每秒，k 表示千米每小时）：\n");
    scanf("%f %c", &value, &unit);
    switch (toupper(unit))
    {
    case 'M':
        // 米每秒转千米每小时
        result = value * 3.6;
        printf("%.5f m/s = %.5f km/h\n", value, result);
        change_printScreen();
        break;
    case 'K':
        // 千米每小时转米每秒
        result = value / 3.6;
        printf("%.5f km/h = %.5f m/s\n", value, result);
        change_printScreen();
        break;
    default:
        printf("输入的单位错误，请输入 m 或 k。\n");
        change_printScreen();
    }
}

// 温度单位转换函数
void temperature()
{
    float value, result;
    char unit;
    printf("请输入温度值和当前单位（C 表示摄氏度，F 表示华氏度，K 表示开尔文）：\n");
    scanf("%f %c", &value, &unit);
    switch (toupper(unit))
    {
    case 'C':
        // 摄氏度转华氏度
        result = value * 9.0 / 5.0 + 32.0;
        printf("%.5f C = %.5f F\n", value, result);
        // 摄氏度转开尔文
        result = value + 273.15;
        printf("%.5f C = %.5f K\n", value, result);
        change_printScreen();
        break;
    case 'F':
        // 华氏度转摄氏度
        result = (value - 32.0) * 5.0 / 9.0;
        printf("%.5f F = %.5f C\n", value, result);
        // 华氏度转开尔文
        result = (value + 459.67) * 5.0 / 9.0;
        printf("%.5f F = %.5f K\n", value, result);
        change_printScreen();
        break;
    case 'K':
        // 开尔文转摄氏度
        result = value - 273.15;
        printf("%.5f K = %.5f C\n", value, result);
        // 开尔文转华氏度
        result = value * 9.0 / 5.0 - 459.67;
        printf("%.5f K = %.5f F\n", value, result);
        change_printScreen();
        break;
    default:
        printf("输入的单位错误，请输入 C、F 或 K。\n");
        change_printScreen();
    }
}