#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_CHAR 256

bool anagram(char string1[101],char string2[101])
{
    if(strlen(string1)!=strlen(string2))
    {
        return false;
    }

    int charcount[MAX_CHAR]={0};
    for(int i=0;string1[i]!='\0';i++)
    {
        charcount[(unsigned char)string1[i]]++;
        charcount[(unsigned char)string2[i]]--;
    }

    for(int i=0;i<MAX_CHAR;i++)
    {
        if(charcount[i]!=0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char string1[101];
    fgets(string1,sizeof(string1),stdin);
    string1[strcspn(string1,"\n")]='\0';

    char string2[101];
    fgets(string2,sizeof(string2),stdin);
    string2[strcspn(string2,"\n")]='\0';

    if(anagram(string1,string2))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}