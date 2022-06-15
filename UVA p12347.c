#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    struct root *left;
    struct root *right;
    long long int data;
};
struct node *root,*newnode,*temp,*parent;
void insert(long long int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=0;
    newnode->right=0;
    parent=0;
    if(root==0)
    {
        root=temp=newnode;
    }

    else
    {
        temp=root;
        while(temp!=0)
        {
            parent=temp;
            if(data>temp->data)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;

            }


        }
        temp=parent;
        if(data<parent->data)
        {
            parent->left=newnode;
        }
        if(data>parent->data)
        {
            parent->right=newnode;
        }
    }
}

void postorder(struct node* root)
{
    if(root==0)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%lld\n",root->data);

}


int main()
{
    long long int n;
    root=0;

    while(scanf("%lld",&n)==1)
    {
        insert(n);
    }
    postorder(root);
    return 0;
}
