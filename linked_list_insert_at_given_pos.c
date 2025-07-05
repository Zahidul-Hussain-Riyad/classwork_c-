#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *newnode, *temp;
    int choice, pos, i;

    while (1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        printf("Do you want to continue inserting at end? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
    }

     printf("\nLinked list elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert: ");
    scanf("%d", &newnode->data);

    printf("Enter position after which you want to insert: ");
    scanf("%d", &pos);

    temp = head;
    i = 1;

    while (i < pos && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position! Node not inserted.\n");
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Node inserted successfully after position %d.\n", pos);
    }

    printf("\nLinked list elements: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

