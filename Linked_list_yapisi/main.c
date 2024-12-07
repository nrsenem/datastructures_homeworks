#include <stdio.h>
#include <stdlib.h>

typedef struct Node  //struct'ýn baþýna typedef tanýmlayarak her defasýnda "struct Node" yapýsý yazmak yerine sadece "node" yazabiliriz.
{
    int data;
    struct Node* next;
}node;
struct Node* create_linkedlist(int data); //Linked list oluþturan fonksiyon
void write_linkedlist(node* n); //Linked list yazdýran fonksiyon

int main()
{
    node* root=create_linkedlist(5);
    write_linkedlist(root);
    return 0;
}
struct Node* create_linkedlist(int data)
{
    node* n=(node*)malloc(sizeof(node));
    n->data=data;
    n->next=NULL;
}
void write_linkedlist(struct Node* n)
{
    node* iter=n;
    while(iter!=NULL)
    {
        printf("%d\n",iter->data);
        iter=iter->next;
    }
}
