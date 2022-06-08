#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=0, *newnode, *temp;

void push(int input)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=input;
    if(top==0)
    {
        newnode->next=0;
    }
    else
    {
        newnode->next=top;
    }
    top=newnode;
    printf("\nNew node is inserted.\n\n");
}

int pop()
{
    if(top==0)
    {
        printf("\nStack Underflow.\n");
    }
    else
    {
        temp=top;
        int temp_value=top->data;
        top=top->next;
        free(temp);
        return temp_value;
    }
}

void print()
{
    if(top==0)
    {
        printf("\nStack Underflow.\n");
    }
    else
    {
        printf("\nThe Stack is: ");
        temp=top;
        while(temp->next!=0)
        {
            printf("%d, ", temp->data);
            temp=temp->next;
        }
        printf("%d \n\n", temp->data);
    }
}

int main()
{
    int choice, value;
    printf("Select an option from below.\n");
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("\nPopped element is: %d\n\n", pop());
            break;
        case 3:
            print();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n\n");
        }
    }
}
