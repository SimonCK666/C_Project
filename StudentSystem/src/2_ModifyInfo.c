/**
* 2_ModifyInfo.c
* @author bulbasaur
* @description 
* @created 2020-05-09T09:18:22.607Z+08:00
* @copyright None 
* None
* @last-modified 2020-05-09T09:44:26.647Z+08:00
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stu_StructNum.c"
#include "stuSearch_ID.c"
#include "stuDisplay_Single.c"

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

/* 2. 修改学生信息 */
void Student_Modify() {
    while ( 1 )
    {
        /* code */
        char id[20];
        int index;
        printf("Please input the ID you wanna modify: ");
        scanf("%s", &id);
        getchar();
        index = Student_searchByIndex(id);
        if (index == -1)
        {
            /* code */
            printf("The student is not exist!\n");
        } else
        {
            /* code */
            printf("The modified student's information: \n");
            Student_DisplaySingle(index);
            printf("-- Please input new information --\n");
            printf("Please input ID: ");
            scanf("%s", &students[index].ID);
            getchar();
            printf("Please input Name: ");
            scanf("%s", &students[index].Name);
            getchar();
            printf("Please input C Mark: ");
            scanf("%s", &students[index].C_Mark);
            getchar();
        }

        printf("Continue or Not(Y/N), Please choose: ");
        if (getchar() == 'N')
        {
            /* code */
            break;
        }
        
        
    }
    
}