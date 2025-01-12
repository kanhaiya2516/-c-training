#include<stdio.h>
#include<string.h>

int main()
{
    char string[101];
    fgets(string,sizeof(string),stdin);
    string[strcspn(string,"\n")]='\0';
    int n=strlen(string);

    char substring[101];
    fgets(substring,sizeof(substring),stdin);
    substring[strcspn(substring,"\n")]='\0';

    char *ptr=strstr(string,substring);
    if(ptr!=NULL)
    {
        int index=0;
        char *stringptr=string;
        while(*stringptr!='\0')
        {
            if(stringptr==ptr)
            {
               printf("%d",index);
               return 0;
            }
            stringptr++;
            index++;
        }
    }
    else
    {
        printf("-1");
        return 0;
    }

    return 0;
}