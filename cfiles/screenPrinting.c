#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "calculator.h"
#include <ctype.h>



const char help[101] = "help";
const char about[101] = "about";
const char history[101] = "history";
char input[101];
const char c[101] = "change";
const char quit[101] = "quit";
char historyFormula[20][101];
double historyOutput[20];
//存储历史计算过程

void printScreen()//输出主屏幕
{
    printf("**************************\n");
    printf("*   输入式子以开始计算   *\n");
    printf("**************************\n");
    printf("change 单位换算\n");
    printf("help 获取帮助\n");
    printf("about 关于开发\n");
    printf("history 历史计算数据\n");
    printf("quit 退出\n");
    printf("请输入式子或所需功能：\n");
}



void getCommand() {
    void printHelp();
    void printAbout();
    void printHistory();
    void getInput();
    void roll();

    getInput();
    if (strcmp(input, help) == 0) {
        printHelp();
    }
    else if (strcmp(input, about) == 0) {
        printAbout();
    }
    else if (strcmp(input, history) == 0) {
        printHistory();
    }
    else if (strcmp(input, quit) == 0) {
        printf("谢谢使用");
        exit(1);
    }
    else if (strcmp(input, c) == 0)
    {
        change();
    }else {
        if(preCalculate(input)) {
            double result = calculate(input);
            printf("%s=%lf\n",input,result);
            roll();
            strcpy(historyFormula[0],input);
            historyOutput[0] = result;
            memset(input, 0, sizeof(input));
        }
    }
}

void printHelp() {
    printf("帮助\n");
    printf("基本功能：输入式子直接计算\n");
    printf("示例：2*3+4*6\n");
    printf("圆周率请使用p,自然常数数请使用e\n");
}

void printAbout() {
    printf("关于\n");
    printf("双鸭山大学程序设计大作业????计算器\n");
    printf("开发名单；\n");
    printf("cjl xmh\n");
    printf("fyh hzl\n");
    printf("gqh dsw\n");
    printf("版权所有 ? 2024 [fengming]\n本软件由 中山大学 程序设计大作业 计算器小组 开发\n并遵守 Mozilla Public License 2.0 (MPL 2.0) 的条款发布。您可以自由使用、修改和分发本软件，但必须遵守许可证的规定。\n关于MPL 2.0 的详细信息，请参阅https://www.mozilla.org/en-US/MPL/2.0/\n");
    printf("Github仓库地址:https://github.com/fengmingmc/calculator\n");
}

void printHistory() {
    for (int i = 0; i <20 && historyFormula[i][0] != '\0'; i++) {

            printf("%s=%lf\n", historyFormula[i],historyOutput[i]);

    }
}


void getInput() {
    // free(input);
    scanf("%s", input);
}


void roll() {
    for (int i = 18; i > -1; i--) {
        strcpy(historyFormula[i+1],historyFormula[i]);
    }
    for (int i = 18; i > -1; i--) {
        historyOutput[i+1] = historyOutput[i];
    }
}

