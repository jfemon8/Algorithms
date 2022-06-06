#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *head, *newnode, *temp, *temp1, *temp2, *temp3, *temp4, *temp5;

void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=0;
    newnode->next=0;
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
    temp1=head;
    while(temp1!=0)
    {
        printf("%d ", temp1->data);
        temp1=temp1->next;
    }
}

void search(int sdata)
{
    temp2=head;
    int flag=0;
    while(temp2!=0)
    {
        if(temp2->data==sdata)
        {
            temp2=temp2->next;
            printf("\nItem found.");
            flag=1;
        }
        else
        {
            temp2=temp2->next;
        }
    }
    if(flag==0)
        printf("\nItem not found.");
}

void del(int rdata)
{
     while(head!=0 && head->data==rdata)
    {
        temp3=head;
        head=head->next;
        free(temp3);
        return;
    }
    temp3=head;
    temp4=0;
    temp5=temp3->next;
    while (temp3!=NULL)
    {
        if (temp3->data==rdata)
        {
            if (temp4!=0)
            {
                temp4->next=temp3->next;
                temp5->prev=temp3->prev;
            }
            free(temp3);
            return;
        }

        temp4=temp3;
        temp3=temp5;
        temp5=temp5->next;
    }
}

int main()
{
    int i, n, m, x, y;
    printf("How many data do you want to insert: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf("\nEnter the node %d: ", i);
        scanf("%d", &m);
        insert(m);
    }
    printf("\nHere is the list: ");
    print();
    printf("\n");

    printf("\nEnter data which you want to search: ");
    scanf("%d", &x);
    search(x);
    printf("\n");

    printf("\nEnter data which you want to delete from the list: ");
    scanf("%d", &y);
    del(y);
    printf("\nThe new list is: ");
    print();
    printf("\n");
}

