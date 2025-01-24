#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d",&n);

    int count=0;
    if(n<=1)
    {
        printf("%d is not a prime number.",n);
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                count++;
            }
        }

    if(count>2)
    {
        printf("%d is not a prime number.",n);
    }
    else
    {
        printf("%d is a prime number.",n);
    }
    }
    return 0;
}