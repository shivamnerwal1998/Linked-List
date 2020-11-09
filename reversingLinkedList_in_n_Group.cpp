#include<iostream>
using namespace std ;

struct node
{
    int info ;
    struct node *next ;

};

void insertFront(node **head , int data)
{
    node *ptr;
    ptr =(node *)malloc(sizeof(node));
    ptr->info = data ;
    ptr->next = (*head);
    (*head) = ptr ;
}
traverse(node *head)
{
    for( ; head != NULL ;head = head-> next )
        cout << head->info << "->" ;
}
node* reverseList(node *headREF, int k)
{
    node *current  = headREF;
    node *prev = NULL ;
    node *next = NULL ;
    int count = 0 ;
    while(current != NULL && count<k )
    {
        count++ ;
        next = current->next ;
        current -> next = prev ;
        prev = current ;
        current = next ;
    }
    if(next != NULL)
        headREF->next = reverseList(next , k);
        return prev ;
}

int main()
{
    node *head ;
    head = NULL ;
    insertFront(&head,1);
    insertFront(&head,2);
    insertFront(&head,3);
    insertFront(&head,4);
    cout << "\n List is  : \n" ;
    traverse(head);
    cout << "\n Reversing the in group  \n" ;
    cout << "Enter number of groups \n" ;
    int k ;
    cin >> k ;
    head = reverseList(head,k) ;
    traverse(head);
    return 0 ;
}
