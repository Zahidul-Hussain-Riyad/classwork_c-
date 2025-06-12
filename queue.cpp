#include <iostream>
#define CAPACITY 4
using namespace std;

int queue[CAPACITY];
int front = 0;
int rear = -1;
int count = 0;

void enqueue(int x)
{
    if (count<CAPACITY)
    {
        rear = (rear+1)%CAPACITY;
        queue[rear] = x;
        count++;
        cout << "Successfully added item: " << x << endl;
    }
    else
    {
        cout << "The queue is full" << endl;
    }
}

int dequeue( )
 {
    if (count==0)
    {
        cout << "Underflow condition" << endl;
        return -1;
    }
    else
    {
        int val = queue[front];
        front = (front+1)%CAPACITY;
        count--;
        return val;
    }
}

int peek( )
 {
    if (count==0)
    {
        cout << "The queue is empty" << endl;
        return -1;
    } else
    {
        return queue[front];
    }
}

void display( )
 {
    if (count==0)
    {
        cout << "The queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i=0; i<count; i++)
     {
        int index = (front+i)%CAPACITY;
        cout << queue[index] << " ";
    }
    cout << endl;
}

int main( )
 {
    cout << "Implementing my queue:" << endl;
    display( );
    enqueue(10);
    enqueue(16);
    enqueue(20);
    enqueue(30);
    display( );
    cout << "Dequeued item is: " << dequeue( ) << endl;
    display( );
    enqueue(60);
    display( );
    cout << "Front item is: " << peek() << endl;

    return 0;
}

