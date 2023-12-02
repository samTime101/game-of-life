#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "raylib.h"
#include "raymath.h"

int main()
{
    int mat[20][20];
    int buffer[20][20];
    int up, down, left, right;
    int life;
    int k, i, j;
    int COLS = 20;
    int ROWS = 20;
    int spaceC = 0;
    int screenWidth = 600;
    int screenHeight = 600;
    int cellWidth = screenWidth / COLS;
    int cellHeight = screenHeight / ROWS;

    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "Game of Life");
//default
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            mat[i][j] = 0;
        }
    }

    while (!WindowShouldClose())
    {
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                if (mat[i][j] == 0)
                {
                    DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth, cellHeight, WHITE);
                }
                else
                {
                    DrawRectangle(i * cellWidth, j * cellHeight, cellWidth, cellHeight, BLACK);
                }
                DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth, cellHeight, GRAY);
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mPos = GetMousePosition();
            int x = mPos.x / cellWidth;
            int y = mPos.y / cellHeight;
            if (x >= 0 && x < 20 && y >= 0 && y < 20)
            {
            if(mat[x][y]!=1)
            {
                mat[x][y]=1;
            }
            }
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            spaceC++;
        }
        if (spaceC % 2 != 0)
        {
            SetTargetFPS(4);
            for (k = 0; k < 1; k++)
            {
                for (i = 0; i < 20; i++)
                {
                    for (j = 0; j < 20; j++)
                    {
                        right = (j + 1) % 20;
                        left = ((j - 1) + 20) % 20;
                        up = ((i - 1) + 20) % 20;
                        down = (i + 1) % 20;

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
                        else
                        {
                            buffer[i][j] = mat[i][j];
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
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
