#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;
struct Node* create_linkedlist(int data);
void write_linkedlist(node* n);
void sona_node_ekleme(node** linkedlist, int data);
void node_silme(node** linkedlist, int data);
int main()
{
    node* root=create_linkedlist(4);
    sona_node_ekleme(&root,5);
    sona_node_ekleme(&root,6);
    sona_node_ekleme(&root,7);
    sona_node_ekleme(&root,8);
    node_silme(&root,6);

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
void sona_node_ekleme(node** linkedlist, int data)
{
    node* iter=*linkedlist;
    while(iter->next!=NULL)
    {
        iter=iter->next;
    }
    iter->next=create_linkedlist(data);

}
void node_silme(node** linkedlist, int data)
{
    node* temp=*linkedlist;
    node* iter=*linkedlist;
    if(*(linkedlist)==NULL)
    {
        printf("Linked list bos\n");
    }
    else if((*linkedlist)->data==data)
    {
        temp=(*linkedlist)->next;
        free(*linkedlist);
        *linkedlist=temp;
    }
    else
    {
        while(iter!=NULL && iter->data!=data)
        {
            temp=iter;
            iter=iter->next;
        }
        if(iter==NULL)//silmek istenilen datanýn linkedliste olup olmadýðýný konntrol ediyoruz.
        {
            printf("\n\naradiginiz veri mevcut degil\n\n");
        }
        else
        {
            temp->next=iter->next;
            free(iter);
        }
    }
}
