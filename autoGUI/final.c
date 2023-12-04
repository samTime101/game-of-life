#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "raylib.h"
#include "raymath.h"

int main()
{
    int COLS = 40;
    int ROWS = 40;
    int spaceC = 0;
    int screenWidth = 600;
    int screenHeight = 600;
    int cellWidth = screenWidth / COLS;
    int cellHeight = screenHeight / ROWS;
    int fps = 60;
    int mat[ROWS][COLS];
    int buffer[ROWS][COLS];          
    SetTargetFPS(fps);
    InitWindow(screenWidth, screenHeight, "try render");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat[i][j] = 0;
        }
    }

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mPos = GetMousePosition();
            int col = (int)mPos.x / cellWidth;
            int row = (int)mPos.y / cellHeight;
            if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                   /*        if(mat[row][col]!=1)
            {
              mouseC=1;
                mat[row][col]=1;
            }
              else if(mouseC==1&&mat[row][col]==1){
                   mouseC=0;
                  mat[row][col]=0;
               }*/
                 mat[row][col] ^= 1;
            }
        }

        if (IsKeyPressed(KEY_SPACE)) {
            spaceC++;
        }
        if (spaceC % 2 != 0) {
            if (fps != 8) {
                SetTargetFPS(fps = 3);
            }
            for (int k = 0; k < 1; k++) {
                for (int i = 0; i < ROWS; i++) {
                    for (int j = 0; j < COLS; j++) {
                        int up = (i - 1 + ROWS) % ROWS;
                        int down = (i + 1) % ROWS;
                        int right = (j + 1) % COLS;
                        int left = (j - 1 + COLS) % COLS;
                        int life = mat[up][left] + mat[up][j] + mat[up][right] +
                            mat[i][left] + mat[i][right] +
                            mat[down][j] + mat[down][left] + mat[down][right];
//-----------------------------------
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
//-----------------------------------------------------------                        
                    }
                }
                for (int i = 0; i < ROWS; i++) {
                    for (int j = 0; j < COLS; j++) {
                        mat[i][j] = buffer[i][j];
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
            
        
                if (mat[row][col] != 0) {
                    DrawRectangle(col * cellWidth, row * cellHeight, cellWidth, cellHeight, BLACK);
                }
        
                DrawRectangleLines(col * cellWidth, row * cellHeight, cellWidth, cellHeight, GRAY);
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}