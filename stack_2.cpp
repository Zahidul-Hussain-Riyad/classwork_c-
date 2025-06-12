#include <iostream>
using namespace std;

const int N = 5;
int stack[N];
int top = -1;

void push(){
    if (top == N-1){
        cout << "Stack Overflow\n";
        return;
    }

    int x;
    cout<<"Enter data to insert: ";
    cin>>x;

    top++;
    stack[top] = x;
    cout<<"Inserted "<< x <<"at position"<< top << endl;
}

void pop(){
    if(top==-1){
        cout<<"Stack Underflow\n";
        return;
    }

    int value = stack[top];
    top--;
    cout<<"Deleted value: "<< value << endl;
}

void display(){
    if(top==-1){
        cout<<"Stack is empty\n";
        return;
    }

    cout<<"Stack elements: ";
    for (int i=top; i>=0; i--) {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    push();  
    push();  
    push(); 
    push();
    push();  
    push();  
    pop();
    pop();
    display();

    return 0;
}

