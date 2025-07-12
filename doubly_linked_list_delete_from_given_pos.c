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

    int pos, i = 1;
    printf("\nEnter position to delete (starting from 1): ");
    scanf("%d", &pos);

    if(head==NULL){
        printf("List is empty. Deletion not possible.\n");
    }
    else if(pos==1){
        temp = head;
        head = head->next;
        if(head!=NULL){
            head->prev = NULL;
        }
        free(temp);
    }
    else{
        temp = head;
        while(i<pos && temp!=NULL){
            temp = temp->next;
            i++;
        }

        if(temp==NULL){
            printf("Position out of range. Deletion not possible.\n");
        }
        else{
            if(temp->prev!=NULL){
                temp->prev->next = temp->next;
            }
            if(temp->next!=NULL){
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
    }

    printf("\nDoubly linked list after deletion: ");
    temp = head;
    while(temp!=NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

