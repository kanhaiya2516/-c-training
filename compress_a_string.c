#include<stdio.h>
#include<string.h>

int main()
{
    char input[101];
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]='\0';
    int n=strlen(input);
    char result[101];
    int index=0;
    result[index++]=input[0];
    for(int i=1;i<n;i++)
    {
        char *ptr=strchr(result,input[i]);
        if(ptr==NULL)
        {
            result[index++]=input[i];
        }
    }
    printf("%s\n",result);
    return 0;
}