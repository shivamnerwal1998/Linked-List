#include<iostream>
using namespace std ;

class Node
{
    public:
    int info ;
    Node *next ;
    public:
    // constructor
    Node(int data)
    {
        info = data ;
        next = NULL ; //in this case we are inserting at end
    }

};

 // function to traverse a list
void traverse(Node *head)
{
    while(head != NULL)
    {
        cout<<head->info<<"->" ;
        head = head -> next ;
    }

}

// function to insert a node at end
void insertAtEnd(Node **head , int info )
{
    Node *ptr ;
    ptr = new Node(info) ;
    if(*head == NULL)
        (*head) = ptr ;
    else
    {
        Node *temp ;
        for(temp = *head ; temp->next != NULL; temp= temp->next);
        temp->next = ptr ;

    }
}

/****FUNCTION TO REVERSE A LINKED LIST****/

void reverseList(Node **head)
{
    Node *prev = NULL  ;
    Node *current = (*head) ;
    Node *next ;
    while(current != NULL )
    {
        next = current->next ;
        current->next = prev ;
        prev = current ;
        current = next ;

    }(*head) = prev ;
}

// main program
int main()
{
    Node *head ;
    head = NULL;
    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    traverse(head);
    cout<<endl<<"reversing the list :"<<endl ;
    reverseList(&head) ;
    traverse(head);
    return 0;
}
