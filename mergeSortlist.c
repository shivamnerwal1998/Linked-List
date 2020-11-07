#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info ;
    struct node* next ;

};

typedef struct node node ;


void insertAtFront(node **head , int data)
{
    node* ptr ;
    ptr = (node*)malloc(sizeof(node)) ;
    ptr->info = data ;
    ptr->next = (*head) ;
    (*head) = ptr ;
}

void traverse(node *head)
{
    while(head != NULL)
    {
        printf("%d -> ",head->info);
        head = head->next ;
    }
}
void frontBackSplit(node *head ,node **front,node **back)
{
    node *slow;
    node *fast ;
    slow = head ;
    fast = head->next ;
    while(fast != NULL)
    {
        fast = fast->next ;
        if(fast != NULL){
            slow = slow->next ;
            fast = fast->next ;
        }
    }
    (*front)  = head ;
    (*back)  = slow->next ;
    slow->next = NULL ;  // important step
}
node* merge(node *front,node *back)
{
    node *ptr ;
    if(front == NULL )
        return back ;
    else if(back == NULL)
        return front ;
    if(front->info <= back->info)
    {
        ptr = front ;
        ptr->next = merge(front->next , back) ;

    }
    else
    {
        ptr = back ;
        ptr->next = merge(front , back->next) ;

    }
    return ptr ;
}

void mergeSort(node **headR)
{
    node *head = *headR ;
    node *front ;
    node *back ;
    if(head == NULL || head->next == NULL)
        return  ;

    frontBackSplit(head,&front,&back);
    mergeSort(&front) ;
    mergeSort(&back) ;
    (*headR) = merge(front , back) ;

}




int main()
{
    node *head ;
    head = NULL ;
    insertAtFront(&head , 1);
    insertAtFront(&head , 2) ;
    insertAtFront(&head , 3) ;
    insertAtFront(&head , 4) ;
    printf("\n traversing the list :\n") ;
    traverse(head) ;
    printf("\n sorting the list  :\n") ;
    mergeSort(&head); // calling the merge sort function
    printf("\n list after sorting :\n") ;
    traverse(head) ;
}
