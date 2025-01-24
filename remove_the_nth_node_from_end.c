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

void removeNthFromEnd(Node* head, int n) {
    Node *p;
    p=head;
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }

     if(count==n)
     {
        struct ListNode *temp;
        temp=head;
        head=head->next;
        free(temp);
     }
     else
     {
    int pos=count-n;
    Node *t,*r;
    t=head;
    r=NULL;
    for(int i=0;i<pos && t;i++)
    {
        r=t;
        t=t->next;
    }
    r->next=t->next;
    free(t);
     }
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
    int m;
    printf("Enter Number of Node:");
    scanf("%d",&m);
    create(arr,n);
    printf("original linked list:\n");
    display(first);
    removeNthFromEnd(first,m);
    printf("Resultant Linked list:\n")
    display(first);
    return 0;
}