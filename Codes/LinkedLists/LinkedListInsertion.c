#include<stdio.h>
#include<stdlib.h> //for malloc function

struct node{
    int data;
    struct node * next;
};

void linkedListTraversal(struct node * ptr){
    while(ptr!=NULL){
        printf("Element-> %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node * insertAtFirst(struct node * head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct node * insertAtIndex(struct node * head, int data, int index){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node * insertAtEnd(struct node * head, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next=NULL;
    return head;
}

struct node * insertAfterNode(struct node * head, struct node * prevNode, int data){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
     struct node * head;
     struct node * second;
     struct node * third;

     //allocate memory for nodes in the linkedlist in heap

     head = (struct node *) malloc ( sizeof(struct node));
     second = (struct node *) malloc ( sizeof(struct node));
     third = (struct node *) malloc ( sizeof(struct node));

     head->data=1;
     head->next=second;

     second->data=2;
     second->next=third;

     third->data=3;
     third->next=NULL;

     linkedListTraversal(head);

     head = insertAtFirst(head,12);
     printf("\nAfter insertion at beginning:\n");
     linkedListTraversal(head);

     head = insertAtIndex(head,24,1);
     printf("\nAfter insertion in between two elements at particular index:\n");
     linkedListTraversal(head);

     head = insertAtEnd(head,56);
     printf("\nAfter insertion at end:\n");
     linkedListTraversal(head);

     head = insertAfterNode(head, second, 45);
     printf("\nOn insertion after node:\n");
     linkedListTraversal(head);

     return 0;
}