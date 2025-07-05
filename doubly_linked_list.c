#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode, *temp;
    int choice;

    while(1){
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head==NULL){
            head = newnode;
        }
        else{
            temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }

        printf("Do you want to continue inserting? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);

        if(choice==0){
            break;
        }
    }

    printf("\nDoubly linked list elements: ");
    temp = head;
    while(temp!=NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

