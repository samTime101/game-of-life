#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "raylib.h"
#include "raymath.h"
int main()
{
    int mat[20][20] =
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int buffer[20][20];
    int up, down, left, right;
    int life;
    int data;
    int x, y;
    int generation;
    int k, i, j;
    int COLS = 20;
    int ROWS = 20;

    int screenWidth = 600;
    int screenHeight = 600;
    int cellWidth = screenWidth / COLS;
    int cellHeight = screenHeight / ROWS;

    SetTargetFPS(2);
    InitWindow(screenWidth, screenHeight, "trial render");
    while (!WindowShouldClose())
    {
        BeginDrawing();

        // default temp mat
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {

                buffer[i][j] = 0;
            }
        }

        for (k = 0; k < 4; k++)
        {
            // sleep(1);
            //  system("@cls||clear");

            ClearBackground(WHITE);

            for (i = 0; i < 20; i++)
            {

                for (j = 0; j < 20; j++)
                {
                    right = (j + 1) % 20; //   19->0 2

                    left = ((j - 1) + 20) % 20; // 0->19 1->20
                    up = ((i - 1) + 20) % 20;   // 0->19 1->20
                    down = (i + 1) % 20;        // 20-->1 19-->0
                    // add 8 dir
                    life = mat[down][j] + mat[i][left] + mat[up][left] + mat[up][j] + mat[up][right] + mat[i][right] + mat[down][right] + mat[down][left];
                    if (mat[i][j] == 1 && (life < 2 || life > 3))
                    {
                        buffer[i][j] = 0;
                    }
                    else if (mat[i][j] == 1 && (life == 2 || life == 3))
                    {
                        buffer[i][j] = 1;
                    }
                    else if (mat[i][j] == 0 && life == 3)
                    {
                        buffer[i][j] = 1;
                    }
                }
            }
            for (i = 0; i < 20; i++)
            {
                for (j = 0; j < 20; j++)
                {
                    mat[i][j] = buffer[i][j];
                }
            }

            for (i = 0; i < 20; i++)
            {
                for (j = 0; j < 20; j++)
                {

                    if (mat[i][j] == 0)
                    {

                        DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth, cellHeight, BLUE);
                    }

                    else
                    {

                        DrawRectangle(i * cellWidth, j * cellHeight, cellWidth, cellHeight, RED);
                    }
                }
            }

            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}
