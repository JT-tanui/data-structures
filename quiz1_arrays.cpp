// Quiz 1: Basic operations on an array
// Traverse, Insert, Delete, Search, Update and Reverse

#include <iostream>
using namespace std;

int arr[100];   // the array (can hold up to 100 numbers)
int n = 0;      // how many numbers are in the array right now

// Show all the elements in the array
void traverse() {
    if (n == 0) {
        cout << "The array is empty." << endl;
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insert a value at a given position (position starts from 0)
void insertElement(int position, int value) {
    if (n == 100) {
        cout << "The array is full." << endl;
        return;
    }
    if (position < 0 || position > n) {
        cout << "Invalid position." << endl;
        return;
    }

    // move the elements one step to the right to make space
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    n = n + 1;
    cout << value << " inserted at position " << position << endl;
}

// Delete the element at a given position
void deleteElement(int position) {
    if (n == 0) {
        cout << "The array is empty." << endl;
        return;
    }
    if (position < 0 || position >= n) {
        cout << "Invalid position." << endl;
        return;
    }

    int removed = arr[position];

    // move the elements one step to the left to cover the gap
    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n = n - 1;
    cout << removed << " deleted from position " << position << endl;
}

// Search for a value (linear search)
void searchElement(int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cout << value << " found at position " << i << endl;
            return;
        }
    }
    cout << value << " was not found in the array." << endl;
}

// Change the value at a given position
void updateElement(int position, int value) {
    if (position < 0 || position >= n) {
        cout << "Invalid position." << endl;
        return;
    }

    arr[position] = value;
    cout << "Position " << position << " updated to " << value << endl;
}

// Reverse the array by swapping the first and last elements, and so on
void reverseArray() {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start = start + 1;
        end = end - 1;
    }
    cout << "The array has been reversed." << endl;
}

int main() {
    int choice, position, value;

    // first fill the array
    cout << "How many elements do you want to start with? ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "The size must be between 0 and 100." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    do {
        cout << endl;
        cout << "----- ARRAY OPERATIONS -----" << endl;
        cout << "1. Traverse" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Search" << endl;
        cout << "5. Update" << endl;
        cout << "6. Reverse" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            traverse();
        }
        else if (choice == 2) {
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter value: ";
            cin >> value;
            insertElement(position, value);
        }
        else if (choice == 3) {
            cout << "Enter position: ";
            cin >> position;
            deleteElement(position);
        }
        else if (choice == 4) {
            cout << "Enter value to search: ";
            cin >> value;
            searchElement(value);
        }
        else if (choice == 5) {
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter new value: ";
            cin >> value;
            updateElement(position, value);
        }
        else if (choice == 6) {
            reverseArray();
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
