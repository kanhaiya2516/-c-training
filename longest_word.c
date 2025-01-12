#include<stdio.h>
#include<string.h>

int main()
{
    char input[101];
    scanf("%[^\n]s",input);
    int longest_length=0;
    char longest_word[101];
    char *token=strtok(input," ");
    while(token!=NULL)
    {
        int length=0;
        length=strlen(token);
        if(length>longest_length)
        {
            longest_length=length;
            strcpy(longest_word,token);
        }
        token=strtok(NULL," ");
    }

    printf("%s",longest_word);
    return 0;
}