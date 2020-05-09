/**
* stuSearch_Name.c
* @author bulbasaur
* @description 
* @created 2020-05-09T09:02:00.212Z+08:00
* @copyright None 
* None
* @last-modified 2020-05-09T09:06:57.998Z+08:00
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stu_StructNum.c"

// /* 学生结构 */
// struct Student
// {
//     /* data */
//     char ID[20];        // ID
//     char Name[20];     // 姓名
//     float C_Mark;     // C 成绩
// };

// /* 学生数组 & 学生数量 */
// struct Student students[100];
// int num = 0;

/* 通过 Name 返回数组下标 */
int Student_SearchByName(char name[]) {
    int i;
    for ( i = 0; i < num; i++)
    {
        /* code */
        if (strcmp(students[i].Name, name) == 0)
        {
            /* code */
            return i;
        }
        
    }
    return -1;
    
}