#include<iostream>
using manespace std ;

struct node
{
    int info ;
    node *next ;

};
void insertFront(node **head ; int data)
{
    node ptr ;
    ptr =(node *)malloc(sizeof(node));
    ptr->info = data ;
    ptr->next = (*head);
    (*head) = ptr ;
}
int main()
{
    node *head ;
    head = NULL ;
    insertFront(&head,1);
    insertFront(&head,2);
    insertFront(&head,3);
    insertFront(&head,4);
    traverse(head);

    return 0 ;
}
