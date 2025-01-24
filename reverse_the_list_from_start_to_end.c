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

void reverse(Node *head,int start,int end,int n)
{
    Node *t1,*t2;
    t1=head;
    t2=head;

    for(int i=1;i<start-1;i++)
    {
        t1=t1->next;
    }
    for(int i=0;i<end;i++)
    {
        t2=t2->next;
    }

    Node *t;
    t=head;
    for(int i=1;i<start;i++)
    {
        t=t->next;
    }

    Node *p,*q,*r;
    p=t;
    q=NULL;
    r=NULL;
    for(int i=0;i<=end-start;i++)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }

    t1->next=q;
    t->next=t2;
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
    int start,end;
    printf("Enter the value of start and end:");
    scanf("%d%d",&start,&end);
    int arr[n];
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    create(arr,n);
    reverse(first,start,end,n);
    display(first);
    return 0;
}