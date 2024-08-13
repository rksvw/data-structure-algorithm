/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void Traverse(struct Node * head) {
    do{
        printf("Element %d", head->data);
        printf("\n");
        head = head->next;
    }while(head->next != NULL);
    printf("Element %d", head->data);
}

struct Node * NodeAtFirst(struct Node * head,int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node * NodeAtBetween(struct Node * head, int index, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * qtr = head;
    ptr->data = data;

    int i = 0;
    while(i != index-1)
    {
        qtr = qtr->next;
        i++;
    }
    
    ptr->next = qtr->next;
    qtr->next = ptr;
    
    return head;
}

struct Node * AtLast(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * qtr = head;
    
    while(qtr->next != NULL)
    {
        qtr = qtr->next;
    }
    
    ptr->data = data;
    ptr->next = NULL;
    qtr->next = ptr;
    return head;
}

int main()
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * first = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 5;
    head->next = first;
    first->data = 8;
    first->next = second;
    second->data = 1;
    second->next = third;
    third->data = 4;
    third->next = fourth;
    fourth->data = 14;
    fourth->next = NULL;
    
    printf("Traverse before Add\n");
    Traverse(head);
    printf("\nTraverse after Add\n");
    // head = NodeAtFirst(head, 23);
    // head = NodeAtBetween(head, 3, 42);
    head = AtLast(head, 40);
    Traverse(head);
    return 0;
}