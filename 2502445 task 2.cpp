//hospital patient line
#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string patientID;
    Node* next;
};

int main() {
    Node* head = 0;

    // --- 1. add patients ---
    string patients[] = {"P101", "P102", "P103", "P104"};
    for (int i = 0; i < 4; i++) {
        Node* newNode = new Node();
        newNode->patientID = patients[i];
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

    // --- 2. Display Initial Queue ---
    cout << "Waiting Patients:\n";
    Node* temp = head;
    while (temp != 0) {
        cout << temp->patientID;
        if (temp->next != 0) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    // --- 3. Serve/Remove First Patient
    if (head != 0) {
        Node* tempToDelete = head;
        cout << "\nPatient " << tempToDelete->patientID << " is being served." << endl;
        head = head->next; // shift heAD 2 next patient
        delete tempToDelete; // del 1st node
    }

    // --- 4. Display Updated Queue ---
    cout << "\nUpdated Queue:\n";
    temp = head;
    while (temp != 0) {
        cout << temp->patientID;
        if (temp->next != 0) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
