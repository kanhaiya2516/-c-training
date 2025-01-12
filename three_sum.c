#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

void threeSum(int* nums, int numsSize) 
{
    qsort(nums, numsSize, sizeof(int), compare);
    int found=0;
     printf("[");
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) 
        {
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) 
            {
                if(found)
                {
                  printf(",");
                }
                printf("[%d %d %d]",nums[i],nums[left],nums[right]);
                found=1;
                while (left < right && nums[left] == nums[left + 1]) 
                {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) 
                {
                    right--;
                }
                left++;
                right--;
            } 
            else if (sum < 0)
            {
                left++;  
            } 
            else
            {
                right--;  
            }
        }
    }
    printf("]");
}

int main() {
    
    char input[1000];
    fgets(input,sizeof(input),stdin);
    int nums[3000];
    int n=0;
    char *token=strtok(input,"[] ");
    while(token!=NULL)
    {
        nums[n++]=atoi(token);
        token=strtok(NULL," ");
    }
    threeSum(nums, n);

    return 0;
}