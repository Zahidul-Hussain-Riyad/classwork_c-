#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main( )
{
    struct node *head = NULL, *temp, *prev, *newnode;
    int choice;

    while(1){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
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
        }

        printf("Do you want to continue inserting? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);

        if(choice==0){
            break;
        }
    }

    printf("\nLinked list before deletion: ");
    temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    if (head == NULL){
        printf("List is already empty. No node to delete.\n");
    }
    else if(head->next==NULL){
        free(head);
        head = NULL;
        printf("Only node deleted, list is now empty.\n");
    }
    else{
        temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        printf("Node deleted from end successfully.\n");
    }

    printf("\nLinked list after deletion: ");
    temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
