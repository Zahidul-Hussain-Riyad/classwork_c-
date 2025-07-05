#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode;
    int choice;

    while (1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = head;

        head = newnode;

        printf("Do you want to continue? (1 for yes / 0 for no): ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
    }

    printf("\nLinked list elements: ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

