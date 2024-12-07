#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct  Node* next;
}node;
struct Node* front=NULL;
struct Node* rear=NULL;
int enqueue(int data);
int main()
{
    enqueue(1);
    enqueue(12);
    enqueue(22);
    enqueue(24);
    enqueue(25);
    Display();
    printf("\n");
    dequeue();
    Display();
    return 0;
}
int enqueue(int data)
{
    if(front==NULL)
    {
        node* new=(node*)malloc(sizeof(node));
        new->data=data;
        new->next=NULL;

        front=rear=new;
    }
    else
    {
        node* new=(node*)malloc(sizeof(node));
        new->data=data;
        new->next=NULL;
        rear->next=new;
        rear=new;

    }

}
void dequeue()
{
    if(front==NULL)
    {
        printf("kuyruk bos.\n");
    }
    else
    {
        node* index=front;
        front=front->next;
        free(index);

    }
}
void Display()
{
    node* index=front;
    while(index!=NULL)
    {
        printf("%d",index->data);
        index=index->next;
        printf("\n");
    }

}
