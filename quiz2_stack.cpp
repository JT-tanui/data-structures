// Quiz 2: Basic operations on a stack
// Push, Pop, Peek and Display
// A stack is Last In First Out (LIFO): the last item added is the first one removed

#include <iostream>
using namespace std;

int stack[100];   // the stack (can hold up to 100 numbers)
int top = -1;     // position of the top item, -1 means the stack is empty

// Check if the stack has nothing in it
bool isEmpty() {
    return top == -1;
}

// Check if the stack has no more space
bool isFull() {
    return top == 99;
}

// Add a value on top of the stack
void push(int value) {
    if (isFull()) {
        cout << "Stack overflow. Cannot push " << value << endl;
        return;
    }

    top = top + 1;
    stack[top] = value;
    cout << value << " pushed onto the stack." << endl;
}

// Remove the value on top of the stack
void pop() {
    if (isEmpty()) {
        cout << "Stack underflow. Nothing to pop." << endl;
        return;
    }

    cout << stack[top] << " popped from the stack." << endl;
    top = top - 1;
}

// Look at the value on top without removing it
void peek() {
    if (isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }

    cout << "Top element is " << stack[top] << endl;
}

// Show everything in the stack from top to bottom
void display() {
    if (isEmpty()) {
        cout << "The stack is empty." << endl;
        return;
    }

    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << endl;
        cout << "----- STACK OPERATIONS -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            peek();
        }
        else if (choice == 4) {
            display();
        }
        else if (choice == 0) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
