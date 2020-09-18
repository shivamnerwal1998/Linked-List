#include<iostream>
using namespace std ;

// self refrential structure of linked list
struct node
{
    int info ;
    struct node *next ;
    node(int x)
    {
        info = x ;
    }
};

// function to insert the elements at end
void insertAtEnd(node **head,int data)
{
    node *ptr ;
    ptr = new node(data) ;
    ptr->next = NULL ;
    if(*head == NULL)
        *head = ptr ;
    else
    {
        node *temp;
        for(temp= *head ; temp->next!=NULL ; temp=temp->next);
            temp->next = ptr ;

    }
}


int findSecondLast(node *head)
{
    if(head->next == NULL && (head ->next)->next==NULL)
    {
        cout<<"N.A"<<endl ;
        exit(1);
    }
       while((head->next)->next != NULL)
        head = head->next ;

        return head->info ;
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


// Main program
int main()
{
    node *head ;
    head = NULL;
    insertAtEnd(&head,4) ;
    insertAtEnd(&head,5) ;
    insertAtEnd(&head,6) ;
    insertAtEnd(&head,7) ;
    printList(head);
    cout<<" \n the second last node is :" << findSecondLast(head);


    return 0;
}
