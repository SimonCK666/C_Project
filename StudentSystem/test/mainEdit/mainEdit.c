/**
* studentSystem.c
* @author Simon
* @description Student System
* @created 2020-05-08T19:53:36.477Z+08:00
* @copyright 
* https://blog.csdn.net/hpf247/article/details/75716059
* https://github.com/SimonCK666/C_Project/tree/master/StudentSystem
* @last-modified 2020-05-12T21:18:46.276Z+08:00
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #include "src/stu_StructNum.c"
// #include "src/stuSearch_ID.c"
// #include "src/stuSearch_Name.c"
// #include "src/stuDisplay_Single.c"
// #include "src/1_InsertInfo.c"
// #include "src/2_ModifyInfo.c"
// #include "src/3_DeleteInfo.c"
// #include "src/4_SelectByName.c"
// #include "src/5_SortBycMark.c"


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


/* 显示单条学生记录 */
void Student_DisplaySingle(int index) {
    printf("%10s%10s%8s\n", "ID", "Name", "C Marks");
    printf("-------------------------------------------------------\n");
    printf("%10s%10s%8.2f\n", students[index].ID, students[index].Name, students[index].C_Mark);
}

/* 1. 增加学生信息 */
void Student_Insert() {
    while ( 1 )
    {
        /* code */
        // printf("Please input ID: ");
        // scanf("%s", &students[num].ID);
        // getchar();
        // printf("Please input Name: ");
        // scanf("%s", &students[num].Name);
        // getchar();
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

/* 显示学生信息 */
void Student_Display() {
    int i;
    printf("%10s%10s%8s\n", "ID", "Name", "Grade");
    printf("----------------------------------------------\n");

    for ( i = 0; i < num; i++)
    {
        /* code */
        printf("%10s%10s%8.2f\n", students[i].ID, students[i].Name, students[i].C_Mark);
    }
    
}

/* 将学生信息从文件 (Database.txt) 中读出 */
void IO_ReadInfo() {
    FILE *fp;
    int i;

    if ((fp = fopen("Database.txt", "rb")) == NULL)
    {
        /* code */
        printf("Cannot open file!\n");
        return;
    }

    if (fread(&num, sizeof(int), 1, fp) != 1)
    {
        /* code */
        num = -1;
    } else
    {
        /* code */
        for ( i = 0; i < num; i++)
        {
            /* code */
            fread(&students[i], sizeof(struct Student), 1, fp);
        }
        
    }
    
    fclose(fp);
}

/* 将学生信息写入文件 (Database.txt) */
void IO_WriteInfo() {
    FILE *fp;
    int i;
    if ((fp = fopen("Database.txt", "wb")) == NULL)
    {
        /* code */
        printf("Cannot open file!\n");
        return;
    }

    if (fwrite(&num, sizeof(int), 1, fp) != 1)
    {
        /* code */
        printf("Written Error!\n");
    }
    for ( i = 0; i < num; i++)
    {
        /* code */
        if (fwrite(&students[i], sizeof(struct Student), 1, fp) != 1)
        {
            /* code */
            printf("Written Error!\n");
        }
        
    }
    
    fclose(fp);
}

void Quit() {
    exit(0);
}

void function_list();

/************ 主程序 ***********/
void main() {
    int choice;
    
    IO_ReadInfo();           // 读取文件
    
    function_list();

    // return 0;
}


void function_list() {
    int i;
    do {

        printf("\t\t|###############################################|\n");
        printf("\t\t|                                               |\n");
        printf("\t\t|    Welcome to Use Grade management System     |\n");
        printf("\t\t|                                               |\n");
        printf("\t\t|   Please Select The Following Functions:      |\n");
        printf("\t\t|                                               |\n");
        printf("\t\t|   $$ 1 -Import grades for a course            |\n");
        printf("\t\t|   $$ 2 -Delete a course                       |\n");
        printf("\t\t|   $$ 3 -Calculate GPA                         |\n");
        printf("\t\t|   $$ 4 -Export file with GPA                  |\n");
        printf("\t\t|   $$ 5 -Quit                                  |\n");
        printf("\t\t|                                               |\n");
        printf("\t\t|###############################################|\n");

        printf("\n\n\n\n");

        printf("Please Input Number:");
        scanf("%d", &i);

        switch (i) {

            case 1: Student_Insert(); break;
            case 2: Student_Modify(); break;
            case 3: Student_Delete(); break;
            case 4: Student_Select(); break;
            case 5: 
                    Student_SortByAverage(students);
                    Student_Display();
                    break;
            case 6: Quit(); break;
            default: printf("Number should between 1 -- 5!\n");
        }

        IO_WriteInfo();

    } while (1);
}