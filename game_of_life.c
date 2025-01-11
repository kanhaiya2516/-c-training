#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void readMatrix(char *input, int matrix[25][25], int *rows, int *cols)
{
    int row = 0, col = 0, num = 0;
    char *ptr = input;

    while (*ptr != '\0') {
        
        if (*ptr == '[') 
        {
            col = 0; 
        }
        else if (*ptr >= '0' && *ptr <= '9') 
        {
            num = 0;
            while (*ptr >= '0' && *ptr <= '9')
            {
                num = num * 10 + (*ptr - '0');
                ptr++;
            }
            matrix[row][col++] = num;
            ptr--; 
        }
        else if (*ptr == ']')
        {
            if (col > 0) 
            {
                row++;
            }
        }
        ptr++;
    }

    *rows = row-1;
    *cols = col;
}

void game_of_life(int matrix[25][25],int m,int n)
{
    int temp[25][25]={0};
    int x[]={0,1,1,1,0,-1,-1,-1};
    int y[]={1,1,0,-1,-1,-1,0,1};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int zero=0;
            int one=0;
            for(int k=0;k<8;k++)
            {
                int ni=i+x[k];
                int nj=j+y[k];
                if(ni>=0 && ni<m && nj>=0 && nj<n)
                {
                    if(matrix[ni][nj]==1)
                    {
                        one++;
                    }
                    else
                    {
                        zero++;
                    }
                }
            }
            if(matrix[i][j]==1)
            {
                if(one<2 || one>3)
                {
                    temp[i][j]=0;
                }
                else
                {
                    temp[i][j]=1;
                }
            }
            else
            {
                if(one==3)
                {
                    temp[i][j]=1;
                }
                else
                {
                    temp[i][j]=0;
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           matrix[i][j]=temp[i][j];
        }
    }
}

int main() {

    char input[1000];
    int matrix[25][25];
    int rows, cols;
    scanf("%[^\n]", input);
    readMatrix(input, matrix, &rows, &cols);
    game_of_life(matrix,rows,cols);
    printf("[");
    for(int i=0;i<rows;i++)
    {
         printf("[");
        for(int j=0;j<cols;j++)
        {
            if(j!=0&&j!=cols)
            {
                printf(" ");
            }
            printf("%d",matrix[i][j]);
        }
        printf("]");
        if(i!=rows-1)
        {
            printf(",");
        }
    }
    printf("]");
    
    return 0;
}