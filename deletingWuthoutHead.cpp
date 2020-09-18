#include<iostream>
using namespace std ;

struct node
{
    int info ;
    struct node *next ;
    node(int x)
    {
        info = x ;
    }
};
void insertBefore(node **head,int info)
{
    node *temp ;
    temp = new node(info) ;
    temp->next = (*head) ;
    (*head) = temp ;

}
void printList(node *head)
{
    while(1)
    {
        if(head == NULL)
            return ;
        printf("%d -> ",head->info) ;
        head = head->next ;
    }

}


// we are taking the address of the node which we want to delete
void deleteGiven(node **nodeadr)
{
    node *temp ;
    if((*nodeadr) == NULL && (*nodeadr)->next == NULL)
    {
        printf("\n not possible \n");
        return ;
    }
    /*********/
    (*nodeadr)->info = ((*nodeadr)->next)->info ;
    temp = (*nodeadr)->next ;
    (*nodeadr)->next = ((*nodeadr)->next)->next ;
    /*********/
    free(temp);
}


int main()
{
    node *head ;
    head = NULL;
    insertBefore(&head,4) ;
    insertBefore(&head,3) ;
    insertBefore(&head,2) ;
    insertBefore(&head,1) ;
    printList(head);
    cout<<" \n delete 2 without sending head  \n";
    deleteGiven(&(head->next));
    printList(head);
    return 0;
}
