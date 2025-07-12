#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front=-1, rear=-1;

void enqueue(int x)
 {
    if((rear+1)%SIZE==front){
        printf("Overflow.\n");
    }
    else if(front==-1 && rear==-1){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear = (rear+1)%SIZE;
        queue[rear] = x;
    }
}

void dequeue( )
{
    if(front==-1 && rear==-1){
        printf("Underflow.\n");
    }
    else if(front==rear){
        printf("Deleted: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Deleted: %d\n", queue[front]);
        front = (front+1)%SIZE;
    }
}

void display( )
 {
    int i = front;
    if(front==-1 && rear==-1){
        printf("Queue is empty.\n");
    }
    else{
        printf("Queue elements: ");
        while(i!=rear){
            printf("%d ", queue[i]);
            i = (i+1)%SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main( )
 {
    int choice, value;
    while(1){
        printf("\n----- Circular Queue Menu -----\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue( );
            break;
        case 3:
            display( );
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

