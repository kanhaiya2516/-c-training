#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool rotation(char string1[101],char string2[101])
{
    if(strlen(string1)!=strlen(string2))
    {
        return false;
    }

     char concat[2*strlen(string1)+1];
     strcpy(concat,string1);
     strcat(concat,string1);

     if(strstr(concat,string2))
     {
         return true;
     }
     else
        {
          return false;
        }
}

int main()
{
    char string1[101];
    fgets(string1,sizeof(string1),stdin);
    string1[strcspn(string1,"\n")]='\0';

    char string2[101];
    fgets(string2,sizeof(string2),stdin);
    string2[strcspn(string2,"\n")]='\0';

    if(rotation(string1,string2))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}