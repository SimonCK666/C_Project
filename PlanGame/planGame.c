/**
* planGame.c
* @author Simon Yang
* @description 
Plan Game 
* @created 2020-04-28T14:23:07.291Z+08:00
* @copyright None 
* None
* @last-modified 2020-04-28T16:52:40.677Z+08:00
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define high 25                                // Canvas Height
#define width 50                               // Canvas Width
#define border -1                              // Border
#define blank 0                                // Blank
#define plane 1                                // Plane
#define bullet 2                               // Bullet
#define enemy 3                                // Enemy planes
#define destroy 4                              // Destory Marks

int canvas[high + 2][width + 2];               // Canvas height and width
int pos_h, pos_w;                              // Plane place
int enemynum;                                  // Number of the enemies
int interval;                                  // Time to simulate the interval
int itv_move;                                  // The time interval between enemy aircraft movements
int itv_new;                                   // Enemy aircraft refresh interval
int score;                                     // Scores
int IsOver;                                    // Determine if the game is over

void Startup();                                // Game value initialization
void Show();                                   // Game interface output
void UpdateInput();                            // Game status updates due to input
void UpdateNormal();                           // Game status updates unrelated to input


int main() {
    /* Initialize */
    Startup();

    /* Game Loop */
    while (IsOver)
    {
        
        UpdateInput();
        UpdateNormal();
        Show();
    }
    
    printf("\t\tGame Over!\n");
    
    // Pause game end screen (milliseconds)
    Sleep(2500);
    
    system("pause");
    
    return 0;
}


/* Game value initialization */
void Startup() {
    IsOver = 1;
    
    // Initialization score
    score = 0;
    
    /* Initialization Canvas */
    for (int i = 0; i < high + 2; i++)
    {
        
        for (int j = 0; j < width + 2; j++)
        {
            
            if (i == 0 || i == high + 1 || j == 0 || j == width + 1)
            {
                
                canvas[i][j] = border;
            } else
            {
                
                canvas[i][j] = blank;
            }
            
            
        }
        
    }

    pos_h = high / 2;                                                // Initializes the plane's vertical coordinates
    pos_w = width / 2;                                               // Initializes the plane's horizontal coordinates
    canvas[pos_h][pos_w] = plane;                                    // Initializes the aircraft position
    enemynum = 3;                                                    // Number of enemies planes
    
    /* Creat Random numbers */
    srand(time(NULL));
    
    interval = 4;                                                    // Initialize the aircraft position initialize the time interval count
    itv_move = 5;                                                    // Initializes the enemy movement interval
    itv_new = 40;                                                    // Initializes the enemy refresh interval
    
}


/* Game interface output */
void Show() {
    HideCursor();                                                    // Hide Cursor
    gotoxy(1, 1);                                                    // Callback cursor, refresh screen
    
    for (int i = 0; i < high + 2; i++)
    {
        
        for (int j = 0; j < width + 2; j++)
        {
            
            if (canvas[i][j] == plane)                               // The current position is the aircraft position
            {
                
                printf("*");
            }
            else if (canvas[i][j] == bullet)                         // The current position is the bullet position
            {
                printf("|");
            }
            else if (canvas[i][j] == enemy)                          // The current position is the enemy plane
            {
                printf("@");
            }
            else if (canvas[i][j] == border)                         // The current position is the border position
            {
                printf("#");
            }
            else if (canvas[i][j] == blank)                          // The current position with nothing, and in the border
            {
                printf(" ");
            }
            else if (canvas[i][j] == destroy)                        // The current position with nothing, and in the border
            {
                printf("x");
            }
        }
        printf("\n");
        
    }
    printf("\nScores: %d", score);
    
}

/* Game status updates due to input */
void UpdateInput() {
    char key_W = GetKeyState('W'),                                   // Monitor whether the W key is pressed
         key_S = GetKeyState('S'),                                   // Monitor whether the S key is pressed
         key_A = GetKeyState('A'),                                   // Monitor whether the A key is pressed
         key_D = GetKeyState('D'),                                   // Monitor whether the D key is pressed
         key_attack = GetKeyState(' ');                              // Monitor whether the Space key is pressed
    
    /* When a key is pressed */
    if (kbhit())
    {
        /* When pess the W, Go up */
        if (key_W < 0)
        {
            
            if (pos_h > 1)
            {
                canvas[pos_h][pos_w] = blank;
                
                /* Next place is the enemy. Crash */
                if (canvas[pos_h - 1][pos_w] == enemy)
                {
                    canvas[pos_h - 1][pos_w] = destroy;
                    IsOver = 0;
                } else
                {
                    canvas[--pos_h][pos_w] = plane;
                }
                
            }
            
        }
        
        /* When pess the S, Go down */
        if (key_S < 0)
        {
            
            if (pos_h < high)
            {
                canvas[pos_h][pos_w] = blank;

                /* Next place is the enemy. Crash */
                if (canvas[pos_h + 1][pos_w] == enemy)
                {
                    canvas[pos_h + 1][pos_w] = destroy;
                    IsOver = 0;
                } else
                {
                    canvas[++pos_h][pos_w] = plane;
                }
                
            } 
            
        }
        
        /* When pess the A, Go left */
        if (key_A < 0)
        {
            
            if (pos_w > 1)
            {
                canvas[pos_h][pos_w] = blank;

                /* Next place is the enemy. Crash */
                if (canvas[pos_h][pos_w - 1] == enemy)
                {
                    canvas[pos_h][pos_w - 1] = destroy;
                    IsOver = 0;
                } else
                {
                    canvas[pos_h][--pos_w] = plane;
                }
                
            }
            
        }
        
        /* When pess the D, Go right */
        if (key_D < 0)
        {
            
            if (pos_w < width)
            {
                canvas[pos_h][pos_w] = blank;
                
                /* Next place is the enemy. Crash */
                if (canvas[pos_h][pos_w + 1] == enemy)
                {
                    canvas[pos_h][pos_w + 1] = destroy;
                    IsOver = 0;
                } else
                {
                    canvas[pos_h][++pos_w] = plane;
                }
                
            }
            
        }

        /* When the space is pressed, fire the bullet */
        if (key_attack < 0)
        {
            
            if (pos_h != 1)
            {
                
                canvas[pos_h - 1][pos_w] = bullet;
            }
            
        }
        
    }
    
}


/* Game status updates unrelated to input */
void UpdateNormal() {
    // A temporary array used to determine the original position
    int temp[high + 2][width + 2];
    
    for (int i = 0; i <= high; i++)
    {
        
        for (int j = 0; j <= width; j++)
        {
            
            temp[i][j] = canvas[i][j];
        }
        
    }

    // Iterate through the temporary array and modify the canvas
    for (int i = 0; i <= high; i++)
    {
        
        for (int j = 0; j <= width; j++)
        {
            // The current position is enemy aircraft
            if (temp[i][j] == enemy && interval % itv_move == 0)
            {
                
                canvas[i][j] = blank;

                // Down Here are the Bullets. The Enemy plane was hit
                if (temp[i + 1][j] == bullet)
                {
                    
                    canvas[i + 1][j] = blank;
                    score++;
                    
                    /* The sound of being Hit */
                    printf("\a");
                }
                else if (i < high)
                {
                    canvas[i + 1][j] = enemy;
                }
                
                // Down Here are the Planes, The player plane was destroied
                if (i + 1 == pos_h && j == pos_w)
                {
                    
                    canvas[i + 1][j] = destroy;
                    IsOver = 0;
                }
                
            }

            // The current position is bullet
            if (temp[i][j] == bullet)
            {
                
                canvas[i][j] = blank;
                
                // Down Here are the enemy planes, Enemy plane was hit
                if (temp[i - 1][j] == enemy)
                {
                    
                    canvas[i - 1][j] = blank;
                    score++;
                    
                    printf("\a");
                }
                else if (i > 1)
                {
                    canvas[i - 1][j] = bullet;
                }
                
            }
            
            
        }
        
    }
    
    // Just in time interval
    if (interval % itv_new == 0)
    {
        /* New enemy aircraft group */
        for (int i = 0; i < enemynum; i++)
        {
            
            canvas[rand() % 2 + 1][rand() % width + 1] = enemy;
        }
        
    }

    // Time interval counts
    if (interval <= 100)
    {
        
        interval++;
    } else
    {
        /* Time interval count zero */
        interval = 0;
    }
    
}

// Callback the cursor
void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x - 1;
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Hidden cursor function
void HideCursor() {
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}
