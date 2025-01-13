#include <stdio.h>
#include <string.h>

char result[100][100];
int count=0;

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char str[101], int left, int right)
 {
    if (left == right)
    {
        strcpy(result[count],str);
        count++;
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(&str[left], &str[i]);
            permute(str, left + 1, right);
            swap(&str[left], &str[i]);
        }
    }

}

int main() {
    char str[101];
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    int n = strlen(str);
    printf("Permutations of the string:\n");
    permute(str, 0, n - 1);
     printf("[");
    for(int i=0;i<count;i++)
    {
        printf("\"%s\"",result[i]);
        if(i<count-1)
        {
            printf(",");
        }
    }
    printf("]");
    return 0;
}