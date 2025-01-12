#include<stdio.h>
#include<string.h>

int main()
{
    char input[101];
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]='\0';
    int n=strlen(input);

    int num=0;
    for(int i=0;i<n;i++)
    {
        if(input[i]>='1' && input[i]<='9')
        {
            num=num*10+(input[i]-'0');
        }
        else if(input[i]!='-')
        {
            printf("0");
            return 0;
        }
    }

    if(input[0]=='-')
    {
         printf("-%d",num);
    }
    else
    {
        printf("%d",num);
    }

    return 0;
}