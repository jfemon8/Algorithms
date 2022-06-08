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
    printf("\nData inserted successfully.\n\n");
}

void print()
{
    printf("\nThe list is: ");
    temp1=head;
    while(temp1!=0)
    {
        printf("%d ", temp1->data);
        temp1=temp1->next;
    }
    printf("\n\n");
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
            printf("\nItem found.\n\n");
            flag=1;
        }
        else
        {
            temp2=temp2->next;
        }
    }
    if(flag==0)
        printf("\nItem not found.\n\n");
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
    int choice, value;
    printf("Select an option from below.\n");
    while (1)
    {
        printf("1. Insert\n2. Search\n3. Delete\n4. Print\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("\nEnter the value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 3:
            printf("\nEnter the value to delete: ");
            scanf("%d", &value);
            del(value);
            printf("\nData deleted successfully.\n\n");
            break;
        case 4:
            print();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n\n");
        }
    }
}

