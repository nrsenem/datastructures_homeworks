#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;

struct Node* create_linkedlist(int data);
void write_linkedlist(node* n);
int basa_node_ekleme(node** linkedlist,int data);
void sona_node_ekleme(node** linkedlist, int data);
int main()
{
    node* root=create_linkedlist(5);
    basa_node_ekleme(&root,4);
    sona_node_ekleme(&root,6);
    sona_node_ekleme(&root,7);
    sona_node_ekleme(&root,8);
    write_linkedlist(root);
    return 0;
}

struct Node* create_linkedlist(int data)
{
    node* n=(node*)malloc(sizeof(node));
    n->data=data;
    n->next=NULL;
    return n;
}

void write_linkedlist(node* n)
{
    node* iter=n;
    while(iter!=NULL)
    {
        printf("%d\n",iter->data);
        iter=iter->next;
    }
}
int basa_node_ekleme(node** linkedlist,int data)
{
    node* new=create_linkedlist(data);
    new->next=*linkedlist;
    *linkedlist=new;
}

void sona_node_ekleme(node** linkedlist, int data)
{
    node* iter=*linkedlist;
    while(iter->next!=NULL)
    {
        iter=iter->next;
    }
    iter->next=create_linkedlist(data);
}
