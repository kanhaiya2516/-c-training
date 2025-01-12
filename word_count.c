#include<stdio.h>
#include<string.h>

int main()
{
    char input[101];
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]='\0';
    int n=strlen(input);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(input[i]==' ')
        {
            count++;
        }
    }
    count++;
    printf("%d",count);
    return 0;
}