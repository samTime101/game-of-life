#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
    int mat[20][20];
    int buffer[20][20];
    int up, down, left, right;
    int life;
    int data;
    int x, y;
    int generation;
    int k, i, j;
    // default perm mat
    for (i = 0; i < 20; ++i)
    {
        for (j = 0; j < 20; ++j)
        {
            mat[i][j] = 0;
        }
    }
    // default temp mat
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            buffer[i][j] = 0;
        }
    }
    printf("Enter number of live cell to add:");
    scanf("%d", &data);
    for (int i = 0; i < data; i++)
    {
        printf("enter position for %d cell (format:row,column) best starting position(10,10):",i+1);
        scanf("%d,%d", &x, &y);
        mat[x][y] = 1;
    }
    printf("Enter the loops for rendering eg( 15 for 15 generation rendering):");
    scanf("%d", &generation);
    for (k = 0; k < generation; k++)
    {
        sleep(1);
        system("@cls||clear");
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                right = (j + 1) % 20;       //   19->0 20->1
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
                    printf("\t");
                }
                else
                    printf("#\t");
            }
            printf("\n");
        }
    }
    return 0;
}
