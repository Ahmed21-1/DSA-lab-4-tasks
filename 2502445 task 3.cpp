//online Shopping cART
#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string productID;
    Node* next;
};

int main() {
    Node* head = 0;

    // --- 1. add Products into Cart 
    string products[] = {"P101", "P205", "P310", "P415"};
    for (int i = 0; i < 4; i++) {
        Node* newNode = new Node();
        newNode->productID = products[i];
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

    // --- 2. Display Initial Cart ---
    cout << "Shopping Cart:\n";
    Node* temp = head;
    while (temp != 0) {
        cout << temp->productID;
        if (temp->next != 0) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    // --- 3. Specific Product Removal ---
    string removeID = "P310";
    cout << "\nRemove Product: " << removeID << endl;

    if (head != 0) {
        if (head->productID == removeID) {
            Node* tempToDelete = head;
            head = head->next;
            delete tempToDelete;
        } else {
            // delete 
            temp = head;
            while (temp->next != 0 && temp->next->productID != removeID) {
                temp = temp->next;
            }

            if (temp->next != 0) { // Product found
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
        }
    }

    // --- 4. Display Updated Cart ---
    cout << "\nUpdated Cart:\n";
    temp = head;
    while (temp != 0) {
        cout << temp->productID;
        if (temp->next != 0) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
