#include<stdio.h>
#include<string.h>

void remove_specific_character(char str[101],char ch)
{
    int i=0;
    while(str[i]!='\0')
    {
        int ni=i;
        if(str[ni]==ch)
        {
            char temp=str[ni];
            while(str[ni+1]!='\0')
            {
                str[ni]=str[ni+1];
                ni++;
            }
            str[ni]='\0';
            i--;
        }
        i++;
    }
}

int main()
{
    char str[101];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';

    char ch;
    scanf("%c",&ch);

    remove_specific_character(str,ch);
    printf("%s",str);
    return 0;
}