/**
* 3_DeleteInfo.c
* @author bulbasaur
* @description 
* @created 2020-05-09T09:26:48.487Z+08:00
* @copyright None 
* None
* @last-modified 2020-05-09T09:33:14.862Z+08:00
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

/* 3. 删除学生信息 */
void Student_Delete() {
    int i;
    while ( 1 )
    {
        /* code */
        char id[20];
        int index;
        printf("Please input the ID you wanna delete: ");
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
            printf("The deleted student's information is: ");
            Student_DisplaySingle(index);
            printf("Really Delete? (Y/N)");
            if (getchar() == 'Y')
            {
                /* code */
                for ( i = index; i < num - 1; i++)
                {
                    /* code */
                    students[i] = students[i + 1];      // 将后面的对象前移
                }
                num--;
                
            }
            getchar();
            printf("Delete Correctly!\n");
            
        }
        
        printf("Continue or Not(Y/N), Please choose: ");
        if (getchar() == 'N')
        {
            /* code */
            break;
        }
        
    }
    
}