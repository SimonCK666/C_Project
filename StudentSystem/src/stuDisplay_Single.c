/**
* stuDisplay_Single.c
* @author bulbasaur
* @description 
* @created 2020-05-09T09:04:12.039Z+08:00
* @copyright None 
* None
* @last-modified 2020-05-09T09:10:01.231Z+08:00
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

/* 显示单条学生记录 */
void Student_DisplaySingle(int index) {
    printf("%10s%10s%8s\n", "ID", "Name", "C Marks");
    printf("-------------------------------------------------------\n");
    printf("%10s%10s%8.2f\n", students[index].ID, students[index].Name, students[index].C_Mark);
}