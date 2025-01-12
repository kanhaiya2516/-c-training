#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void readMatrix(char *input, int matrix[10][10], int *rows, int *cols) {
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

void spiral(int m, int n, int arr[10][10]) 
{
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int result[100], index = 0; 

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++) {
            result[index++] = arr[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result[index++] = arr[i][right];
        }
        right--;

        if (top <= bottom) 
        {
            for (int i = right; i >= left; i--) 
            {
                result[index++] = arr[bottom][i];
            }
            bottom--;
        }
       
        if (left <= right) 
        {
            for (int i = bottom; i >= top; i--)
            {
                result[index++] = arr[i][left];
            }
            left++;
        }
    }

    printf("[");
    for (int i = 0; i < index; i++) {
        printf("%d", result[i]);
        if (i < index - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

int main() {
     char input[200];
    int matrix[10][10];
    int rows, cols;
    scanf("%[^\n]", input);
    readMatrix(input, matrix, &rows, &cols);
    spiral(rows,cols,matrix);
    return 0;
}