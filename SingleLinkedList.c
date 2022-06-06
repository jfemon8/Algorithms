#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *head, *temp, *temp1, *temp2, *temp3, *temp4;

void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    if(head==0)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
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
    while (temp3!=NULL)
    {
        if (temp3->data==rdata)
        {
            if (temp4!=0)
                temp4->next=temp3->next;
            free(temp3);
            return;
        }

        temp4=temp3;
        temp3=temp3->next;
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    print();
    search(15);
}
