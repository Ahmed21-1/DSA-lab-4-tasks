//student registeration systen
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int rollNumber;
    Node* next;
};

int main() {
    Node* head = 0; // start

    // --- 1. Students Add Karna ---
    int rolls[] = {101, 105, 108, 112};
    for (int i = 0; i < 4; i++) {
        Node* newNode = new Node();
        newNode->rollNumber = rolls[i];
        newNode->next = 0;

        if (head == 0) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != 0) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // --- 2. Display All Students ---
    cout << "Registered Students:\n";
    Node* temp = head;
    while (temp != 0) {
        cout << temp->rollNumber;
        if (temp->next != 0) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    // --- 3. Search Student ---
    int searchRoll = 108;
    cout << "\nEnter Roll Number to Search: " << searchRoll << endl;

    temp = head;
    bool found = false;
    while (temp != 0) {
        if (temp->rollNumber == searchRoll) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << "Student Found" << endl;
    } else {
        cout << "Student Not Found" << endl;
    }

    return 0;
}
