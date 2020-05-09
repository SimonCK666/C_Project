/**
* 1_InsertInfo.c
* @author bulbasaur
* @description 
* @created 2020-05-09T09:12:33.171Z+08:00
* @copyright None 
* None
* @last-modified 2020-05-09T09:17:56.194Z+08:00
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


/* 1. 增加学生信息 */
void Student_Insert() {
    while ( 1 )
    {
        /* code */
        printf("Please input ID: ");
        scanf("%s", &students[num].ID);
        getchar();
        printf("Please input Name: ");
        scanf("%s", &students[num].Name);
        getchar();
        printf("Please input C mark: ");
        scanf("%f", &students[num].C_Mark);
        getchar();
        
        if (54 < students[num].C_Mark && students[num].C_Mark < 60)      // 55 ~ 59 之间成绩 + 5
        {
            /* code */
            students[num].C_Mark += 5;
        }

        num++;

        printf("Continue or Not(Y/N), Please choose: ");
        if (getchar() == 'N')
        {
            /* code */
            break;
        }
        
        
    }
    
}