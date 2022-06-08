#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *head, *newnode, *temp, *key;;

void insert(int a, int b, int c)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=b;
    newnode->next=a;
    newnode->prev=c;
    if(head==0)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
}

void print()
{
    printf("\nThe list is: ");
    temp=head;
    while(temp!=0)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}

int main()
{
    int i, j, n, x, y, z;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int next[n];
    printf("\nEnter the 'next' array: ");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&next[i]);
    }
    int key[n];
    printf("\nEnter the 'key' array: ");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&key[i]);
    }
    int prev[n];
    printf("\nEnter the 'prev' array: ");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&prev[i]);
    }

    for(j=1; j<=n; j++)
    {
        x=key[j];
        y=next[j];
        z=prev[j];
        insert(y, x, z);
    }
    print();
}
