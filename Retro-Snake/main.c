/**
* main.c
* @author Simon
* @description Retro Snake Game
* @created 2020-05-09T17:24:52.323Z+08:00
* @copyright https://blog.csdn.net/qq_40953281/article/details/79315254?ops_request_misc=&request_id=&biz_id=102&utm_term=c%E8%AF%AD%E8%A8%80%E8%B4%AA%E5%90%83%E8%9B%87&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-79315254
*            https://github.com/Joke-Lin/Retro-Snake
* 
* @last-modified 2020-05-09T21:44:28.754Z+08:00
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

// Define the direction burrons
#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'

void welcome();                          // 开始界面
void Finish();                           // 结束界面
void creatgraph();                       // 围墙打印
void gotoxy(int x, int y);               // 光标跳转，横为 X 0, 1, 2..
void gotoprint(int x, int y);            // 跳转打印
void gotodelete(int x, int y);           // 跳转删除
void creatfood();                        // 食物产生
int ClickControl();                      // 获取键盘信号
int Judge();                            // 游戏结束判断
void MovingBody();                       // 蛇的移动
void Eating();                           // 吃东西后身体伸长
void ChangeBody(int x, int y);           // 蛇的坐标变换

/* Global variables & Pretreatment */

// Snake Define
typedef struct Snakes
{
    int x;
    int y;
    struct Snakes* next;
}snake;

snake* head;   // 声明蛇头指针

// Define Food
struct Food
{
    int x;
    int y;
}food;

char name[20];      // 保存用户名
int score = 0;      // 分数
char click = 1;     // 记录敲击键盘的按键
int speed;          // 速度  <-->  延迟的毫秒数


/*******************************************************************************************************/


int main() {
    system("color 0B");           // 控制台的字体颜色
    welcome();                    // 欢迎界面
    creatgraph();                 // 创建地图
    creatfood();                  // 新建食物
    // 获取鼠标案件  ClickControl
    if (ClickControl() == 0)
    {
        return 0;
    }
    return 0;
}


/*******************************************************************************************************/


// 欢迎界面
void welcome() {
    gotoxy(15, 10);
    printf("/**********************************************/");
    gotoxy(15, 20);
    printf("/**********************************************/");
    gotoxy(20, 13);
    printf("WELCOME TO THE GAME OF RETRO SNAME");
    gotoxy(14, 16);
    printf("Please in the English input, if you go down at the beginning, which equals kill yourself ~ ('wasd' control, 'p' pause)");
    gotoxy(20, 18);
    printf("PLEASE ENTER YOUR NAME: ");
    scanf("%s", &name, 20);
    // Clear Screen
    system("cls");
}


/*******************************************************************************************************/


// 围墙打印
void creatgraph() {
    int i;
    /*
    注意这里的坐标每次 +2 ， 因为控制台字符宽高比为 1 : 2
    */
   for ( i = 0; i < 58; i += 2)
   {
       gotoprint(i, 0);
       gotoprint(i, 26);
   }
   for ( i = 1; i < 26; i++)
   {
       gotoprint(0, i);
       gotoprint(56, i);
   }
   gotoxy(63, 10);
   printf("Hello %s, Welcome To Play", name);
   gotoxy(63, 15);
   printf("Your Score Is: %d    (^人^)", score);
   gotoxy(63, 20);
   printf("This Game Is Created By Simon");
   head = (snake*)malloc(sizeof(snake));
   snake* p = (snake*)malloc(sizeof(snake));
   snake* q = (snake*)malloc(sizeof(snake));
   head->x = 16;
   head->y = 16;
   p->x = 16;
   p->y = 16;
   q->x = 16;
   q->y = 17;
   head->next = p;
   p->next = q;
   q->next = NULL;
}


/*******************************************************************************************************/


// 光标跳转，横为 X 0, 1, 2..
void gotoxy(int x, int y) {
    // 更新光标位置
    COORD pos;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOutput, pos);
    // 隐藏光标
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    SetConsoleCursorInfo(hOutput, &cursor);
}


/*******************************************************************************************************/


// 跳转打印
void gotoprint(int x, int y) {
    gotoxy(x, y);
    printf("■");
}


/*******************************************************************************************************/


// 跳转删除
void gotodelete(int x, int y) {
    gotoxy(x, y);
    printf("  ");
}


/*******************************************************************************************************/


// 食物产生
void creatfood() {
    // 随机产生一个食物
    bool flag = false;
    while ( !flag )
    {
        flag = true;
        srand((int)time(NULL));
        food.y = rand() % (25 - 1 + 1) + 1;
        food.x = rand() % (54 - 2 + 1) + 2;
        if ( food.x % 2 != 0)
        {
            food.x = food.x + 1;
        }
        snake* judge = head;
        while ( 1 )
        {
            if (judge->next == NULL)
            {
                break;
            }
            if (food.x == judge->x && food.y == judge->y)
            {
                flag = false;
            }
            judge = judge->next;
        }
    }
    gotoxy(food.x, food.y);
    printf("⊙");
}


/*******************************************************************************************************/


// 获取鼠标，游戏主循环
int ClickControl() {
    char c;
    while ( 1 )
    {
        if (Judge() == 0)
        {
            return 0;
        }
        if (_kbhit())
        {
            click = _getch();
        }
        MovingBody();
        Eating();
    }
    return 1;
}


/*******************************************************************************************************/


// 蛇的移动
void MovingBody() {
    int x = head->x, y = head->y;
    snake* p = head;
    // 通过先清空后打印实现动画效果
    while (p->next != NULL)
    {
        p = p->next;
    }
    gotodelete(p->x, p->y);     // 清除尾节点
    switch (click)
    {
    case up:
        y -= 1;
        break;
    case down:
        y += 1;
        break;
    case left:
        x -= 2;
        break;
    case right:
        x += 2;
        break;
    default:
        break;
    }
    if (x != head->x || y != head->y)
    {
        /* 改变坐标时更新 暂停游戏停止 更新蛇 */
        ChangeBody(x, y);
    }
    p = head;
    // 打印蛇头
    gotoprint(p->x, p->y);
    // 蛇速度控制
    int count = score / 10;
    if (count <= 10)
    {
        speed = 150;
    } else if (count > 10 && count <= 20)
    {
        speed = 100;
    } else if (count > 20 && count <= 40)
    {
        speed = 50;
    } else
    {
        speed = 10;
    }
    Sleep(speed);
}


/*******************************************************************************************************/


// 吃到食物， 添加一个尾巴
void Eating() {
    if (head->x == food.x && head->y == food.y)
    {
        creatfood();
        snake* _new = (snake*)malloc(sizeof(snake));
        snake* p;
        p = head;
        while ( 1 )
        {
            if (p->next == NULL)
            {
                break;
            }
            p = p->next;
        }
        p->next = _new;
        _new->next = NULL;
        score += 10;
        gotoxy(77, 15);
        printf("%d", score);
    }
}


/*******************************************************************************************************/


// 更新蛇体坐标  只需要消除尾节点  然后把新坐标节点置为头节点即可
void ChangeBody(int x, int y) {
    snake* p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
    snake* new_head = (snake*)malloc(sizeof(snake));
    new_head->x = x;
    new_head->y = y;
    new_head->next = head;
    head = new_head;
}


/*******************************************************************************************************/


// 判断游戏是否结束
int Judge() {
    if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
    {
        Finish();
        return 0;
    }
    snake* p = head->next;
    while ( 1 )
    {
        if (p == NULL)
        {
            break;
        }
        if (head->x == p->x && head->y == p->y)
        {
            Finish();
            return 0;
        }
        p = p->next;
    }
    return 1;
}


/*******************************************************************************************************/


// 结束界面
void Finish() {
    system("cls");
    gotoxy(15, 10);
    printf("/**********************************************/");
    gotoxy(15, 20);
    printf("/**********************************************/");
    gotoxy(18, 14);
    printf("GAME   OVER        o(*￣▽￣*)o");
    gotoxy(20, 16);
    printf("YOUR SCORE IS %d        hiahiahia", score);
    gotoxy(18, 18);
    printf("Great ~~~,       Come on(ง •_•)ง");
    gotoxy(0, 27);
    // 释放空间
    snake* p = head, * q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    system("pause");
}