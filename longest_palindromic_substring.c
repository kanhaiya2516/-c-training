#include<stdio.h>
#include<string.h>

int find_palindromic_substring_length(char str[101],int start,int end)
{
    while(start>=0 && end<strlen(str) && str[start]==str[end])
    {
        start--;
        end++;
    }
    return end-start-1;
}

void longest_palindromic_substring(char str[101],int n)
{
    if(n==0)
    {
        printf("%s",str);
        return 0;
    }

    int start=0;
    int end=0;

    for(int i=0;i<n;i++)
    {
        int len1=find_palindromic_substring_length(str,i,i);
        int len2=find_palindromic_substring_length(str,i,i+1);
        int len=(len1>len2)?len1:len2;

        if(len>end-start)
        {
            start=i-(len-1)/2;
            end=i+len/2;
        }
    }
    char result[101];
    strncpy(result,str+start,end-start+1);
    result[end-start+1]='\0';
    printf("%s",result);
}

int main()
{
    char str[101];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    int n=strlen(str);

    longest_palindromic_substring(str,n);
    return 0;
}