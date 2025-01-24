#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    int data;
   struct Node *next;
}Node;
Node *first=NULL;

void create(int arr[],int n)
{
    Node *last,*t;
    first=(Node*)malloc(sizeof(Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(Node*)malloc(sizeof(Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void middleNode(Node* head) {
    Node *p;
    p=head;
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }

    int pos=count/2+1;
    Node *t,*r;
    t=head;
    r=NULL;
    for(int i=0;i<pos-1;i++)
    {
        t=t->next;
    }
    r=t;
    printf("The value of middle node:%d",r->data);
}

void display(Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    int n;
    printf("Number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    create(arr,n);
    middleNode(first);
    return 0;
}