/**
* 5_SortBycMark.c
* @author bulbasaur
* @description 
* @created 2020-05-09T09:39:12.590Z+08:00
* @copyright None 
* None
* @last-modified 2020-05-09T09:52:47.679Z+08:00
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stu_StructNum.c"
#include "stuSearch_ID.c"
#include "stuDisplay_Single.c"
#include "src/stuSearch_Name.c"


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
// int num = 0

/* 5. 按 C 成绩排序 */
void Student_SortByAverage(struct Student students[]) {
    int i, j;
    struct Student tmp;
    
    for ( i = 0; i < num; i++)
    {
        /* code */
        for ( j = 1; j < num - i; j++)
        {
            /* code */
            if (students[j - 1].C_Mark < students[j].C_Mark)
            {
                /* code */
                tmp = students[j - 1];
                students[j - 1] = students[j];
                students[j] = tmp;
            }
            
        }
        
    }
    
}