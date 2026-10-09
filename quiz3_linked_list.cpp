// Quiz 3: Basic operations on a singly linked list
// Insert, Delete, Update, Search and Traverse

#include <iostream>
using namespace std;

// Each node holds a number and a pointer to the next node
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;   // first node of the list, NULL means the list is empty

// Show all the nodes in the list
void traverse() {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* current = head;
    cout << "List: ";
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Insert a new node at the start of the list
void insertAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << value << " inserted at the beginning." << endl;
}

// Insert a new node at the end of the list
void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        // walk to the last node
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << value << " inserted at the end." << endl;
}

// Insert a new node at a given position (position starts from 0)
void insertAtPosition(int position, int value) {
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 0) {
        insertAtBeginning(value);
        return;
    }

    // walk to the node just before the position
    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Invalid position." << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
    cout << value << " inserted at position " << position << endl;
}

// Delete the first node
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    cout << temp->data << " deleted from the beginning." << endl;
    delete temp;
}

// Delete the last node
void deleteFromEnd() {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    // only one node in the list
    if (head->next == NULL) {
        cout << head->data << " deleted from the end." << endl;
        delete head;
        head = NULL;
        return;
    }

    // walk to the second last node
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    cout << current->next->data << " deleted from the end." << endl;
    delete current->next;
    current->next = NULL;
}

// Delete the first node that holds the given value
void deleteByValue(int value) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    // the value is in the first node
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << value << " deleted from the list." << endl;
        return;
    }

    // look for the node just before the one to delete
    Node* current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        cout << value << " was not found in the list." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    cout << value << " deleted from the list." << endl;
}

// Search for a value in the list
void searchElement(int value) {
    Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->data == value) {
            cout << value << " found at position " << position << endl;
            return;
        }
        current = current->next;
        position = position + 1;
    }
    cout << value << " was not found in the list." << endl;
}

// Change an old value to a new value
void updateElement(int oldValue, int newValue) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue;
            cout << oldValue << " updated to " << newValue << endl;
            return;
        }
        current = current->next;
    }
    cout << oldValue << " was not found in the list." << endl;
}

int main() {
    int choice, position, value, newValue;

    do {
        cout << endl;
        cout << "----- LINKED LIST OPERATIONS -----" << endl;
        cout << "1. Traverse" << endl;
        cout << "2. Insert at beginning" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Insert at position" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete by value" << endl;
        cout << "8. Search" << endl;
        cout << "9. Update" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            traverse();
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
        }
        else if (choice == 3) {
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
        }
        else if (choice == 4) {
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter value: ";
            cin >> value;
            insertAtPosition(position, value);
        }
        else if (choice == 5) {
            deleteFromBeginning();
        }
        else if (choice == 6) {
            deleteFromEnd();
        }
        else if (choice == 7) {
            cout << "Enter value to delete: ";
            cin >> value;
            deleteByValue(value);
        }
        else if (choice == 8) {
            cout << "Enter value to search: ";
            cin >> value;
            searchElement(value);
        }
        else if (choice == 9) {
            cout << "Enter value to change: ";
            cin >> value;
            cout << "Enter new value: ";
            cin >> newValue;
            updateElement(value, newValue);
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
