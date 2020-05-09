/**
* studentSystem.c
* @author Simon
* @description Student System
* @created 2020-05-08T19:53:36.477Z+08:00
* @copyright 
* https://blog.csdn.net/hpf247/article/details/75716059
* @last-modified 2020-05-09T09:07:38.341Z+08:00
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

/* 通过 ID 返回数组下标 */
int Student_searchByIndex(char id[]) {
    int i;
    for ( i = 0; i < num; i++)
    {
        /* code */
        if (strcmp(students[i].ID, id) == 0)
        {
            /* code */
            return i;
        }
        
    }
    return -1;
    
}
