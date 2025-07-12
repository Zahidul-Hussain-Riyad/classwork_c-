#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main( )
{
    struct node *head = NULL, *newnode, *temp;
    int choice=1;

    while(choice){
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
            while (temp->next != NULL){
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

    int pos, i = 1;
    printf("\nEnter data to insert: ");
    newnode = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    printf("Enter position to insert (starting from 1): ");
    scanf("%d", &pos);

    if(pos==1){
        newnode->next = head;
        if(head != NULL){
            head->prev = newnode;
        }
        head = newnode;
    }
    else{
        temp = head;
        while(i<pos-1 && temp!=NULL){
            temp = temp->next;
            i++;
        }

        if(temp==NULL){
            printf("Position out of range. Insertion failed.\n");
        }
        else{
            newnode->next = temp->next;
            newnode->prev = temp;

            if (temp->next != NULL){
                temp->next->prev = newnode;
            }
            temp->next = newnode;
        }
    }

    printf("\nDoubly linked list elements after insertion: ");
    temp = head;
    while(temp!=NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

