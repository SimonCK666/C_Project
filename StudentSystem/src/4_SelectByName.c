/**
* 4_SelectByName.c
* @author bulbasaur
* @description 
* @created 2020-05-09T09:33:58.823Z+08:00
* @copyright None 
* None
* @last-modified 2020-05-09T09:44:15.012Z+08:00
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
// int num = 0;

/* 4. 按姓名查询 */
void Student_Select() {
    while ( 1 )
    {
        /* code */
        char name[20];
        int index;

        printf("Please input the student name you wanna select: ");
        scanf("%s", &name);
        getchar();
        index = Student_SearchByName(name);

        if (index == -1)
        {
            /* code */
            printf("The selected student is not exist!\n");
        } else
        {
            /* code */
            printf("The selected student information is: ");
            Student_DisplaySingle(index);
        }
        
        printf("Continue or Not(Y/N), Please choose: ");
        if (getchar() == 'N')
        {
            /* code */
            break;
        }
        
    }
    
}