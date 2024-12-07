#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;
struct Node* top=NULL;
int push(int data);
void Display();
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    Display();
    return 0;
}
int push(int data)
{
    if(top==NULL)
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->data=data;
        temp->next=NULL;
        top=temp;
    }
   else
   {
       node* temp=(node*)malloc(sizeof(node));
       temp->data=data;
       temp->next=top;

       top=temp;
   }
}
void pop()
{
    if(top==NULL)
    {
        printf("stack bos\n");
    }
    else
    {
        node* index=top;
        top=top->next;
        free(index);
    }
}
void Display()
{
    node* index=top;
    while(index!=NULL)
    {
        printf("%d\n",index->data);
        index=index->next;
    }
}
