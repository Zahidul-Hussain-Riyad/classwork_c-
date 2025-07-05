#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *prev, *newnode;
    int choice, pos, i;

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
            while (temp->next != NULL){
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
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL){
        printf("List is empty. No node to delete.\n");
    }
    else if (pos == 1){
        temp = head;
        head = head->next;
        free(temp);
        printf("Node at position 1 deleted successfully.\n");
    }
    else
    {
        temp = head;
        i = 1;

        while (i < pos - 1 && temp != NULL){
            temp = temp->next;
            i++;
        }

        if (temp == NULL || temp->next == NULL){
            printf("Invalid position! No node deleted.\n");
        }
        else{
            prev = temp->next;
            temp->next = prev->next;
            free(prev);
            printf("Node at position %d deleted successfully.\n", pos);
        }
    }

    printf("\nLinked list after deletion: ");
    temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

