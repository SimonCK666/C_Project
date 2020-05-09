/**
* stu_StructNum.c
* @author bulbasaur
* @description 
* @created 2020-05-09T09:05:34.972Z+08:00
* @copyright None 
* None
* @last-modified 2020-05-09T09:05:46.502Z+08:00
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 学生结构 */
struct Student
{
    /* data */
    char ID[20];        // ID
    char Name[20];     // 姓名
    float C_Mark;     // C 成绩
};

/* 学生数组 & 学生数量 */
struct Student students[100];
int num = 0;