// SAMIP REGMI : SAM TIME 101
// AFTER 2 YEARS 


#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "./include/raylib.h"
#include "./include/raymath.h"
#include <stdbool.h>

#define COLS 40
#define ROWS 40
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define CELL_WIDTH (SCREEN_WIDTH / COLS)
#define CELL_HEIGHT (SCREEN_HEIGHT / ROWS)
#define FPS 60

int main()
{
    int mat[ROWS][COLS];
    int buffer[ROWS][COLS];
    bool PLAY = 0;
    
    SetTargetFPS(FPS);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "AFTER 2 FREAKING YEARS!!");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            mat[i][j] = 0;
        }
    }

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mPos = GetMousePosition();
            int col = (int)mPos.x / CELL_WIDTH;
            int row = (int)mPos.y / CELL_HEIGHT;
            if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
            {
                mat[row][col] ^= 1;
            }
        }
        if(IsKeyPressed(KEY_SPACE)){
            PLAY ^= 1;
        }
        if (PLAY){
        for (int k = 0; k < 1; k++)
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    int up = (i - 1 + ROWS) % ROWS;
                    int down = (i + 1) % ROWS;
                    int right = (j + 1) % COLS;
                    int left = (j - 1 + COLS) % COLS;
                    int life = mat[up][left] + mat[up][j] + mat[up][right] +
                                mat[i][left] + mat[i][right] +
                                mat[down][j] + mat[down][left] + mat[down][right];
                    if (mat[i][j] == 1 && (life < 2 || life > 3))
                    {
                        buffer[i][j] = 0;
                    }
                    else if (mat[i][j] == 1 && (life == 2 || life == 3) || (mat[i][j] == 0 && life == 3))
                    {
                        buffer[i][j] = 1;
                    }
                    else
                    {
                        buffer[i][j] = mat[i][j];
                    }
                }
            }
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    mat[i][j] = buffer[i][j];
                }
            }
        }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (mat[row][col] != 0)
                {
                    DrawRectangle(col * CELL_WIDTH, row * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, BLACK);
                }
                DrawRectangleLines(col * CELL_WIDTH, row * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, GRAY);
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
