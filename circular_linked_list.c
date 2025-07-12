#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head=NULL, *temp, *newnode;
    int choice=1;

    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head==NULL){
            head = temp = newnode;
            temp->next = head;
        }
        else{
            temp->next = newnode;
            temp = newnode;
            temp->next = head;
        }

        printf("Do you want to continue inserting? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    }

    if(head==NULL){
        printf("List is empty.\n");
    }
    else{
        temp = head;
        printf("\nCircular linked list elements: ");
        while(temp->next!=head){
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("%d->NULL", temp->data);
    }

    return 0;
}
