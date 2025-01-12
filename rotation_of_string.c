#include<stdio.h>
#include<string.h>

void rotation(char str[101],int n,int k)
{
    while(k!=0)
    {
       char first=str[0];
       for(int i=1;i<n;i++)
       {
           str[i-1]=str[i];
       }
       str[n-1]=first;
       k--;
     }
}

int main()
{
    char str[101];
    printf("Enter the string:");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    int n=strlen(str);
    int k;
    printf("Enter number of rotation perform in string:");
    scanf("%d",&k);

    rotation(str,n,k);
    printf("%s",str);
    return 0;
}