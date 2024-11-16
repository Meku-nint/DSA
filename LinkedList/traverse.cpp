#include <iostream>
#include <string>

using namespace std;
struct SinglyNode {
    int data;
    SinglyNode* next;
};

struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
};
struct CircularNode {
    int data;
    CircularNode* next;
};
void insertSingly(SinglyNode*& head, int data) {
    SinglyNode* newNode = new SinglyNode();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        SinglyNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void displaySingly(SinglyNode* head) {
    SinglyNode* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
bool searchSingly(SinglyNode* head, int target) {
    SinglyNode* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void insertDoubly(DoublyNode*& head, int data) {
    DoublyNode* newNode = new DoublyNode();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        DoublyNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}
void displayDoubly(DoublyNode* head) {
    DoublyNode* current = head;
    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}bool searchDoubly(DoublyNode* head, int target) {
    DoublyNode* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void insertCircular(CircularNode*& head, int data) {
    CircularNode* newNode = new CircularNode();
    newNode->data = data;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head; 
    } else {
        CircularNode* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
}
void displayCircular(CircularNode* head) {
    if (head == nullptr) return;

    CircularNode* current = head;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);
    cout << "(head)" << endl;}

bool searchCircular(CircularNode* head, int target) {
    if (head == nullptr) return false;

    CircularNode* current = head;
    do {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    } while (current != head);
    return false;
}
void clearSingly(SinglyNode*& head) {
    SinglyNode* current = head;
    while (current != nullptr) {
        SinglyNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
void clearDoubly(DoublyNode*& head) {
    DoublyNode* current = head;
    while (current != nullptr) {
        DoublyNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
void clearCircular(CircularNode*& head) {
    if (head == nullptr) return;

    CircularNode* current = head->next;
    while (current != head) {
        CircularNode* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
    head = nullptr;
}

void menu() {
    system("cls");
    cout << "Linked List Operations Menu" << endl;
    cout << "1. Singly Linked List" << endl;
    cout << "2. Doubly Linked List" << endl;
    cout << "3. Circular Linked List" << endl;
    cout << "4. Exit" << endl;
}

void linkedListMenu(int choice) {
    int data;
    SinglyNode* singlyHead = nullptr;
    DoublyNode* doublyHead = nullptr;
    CircularNode* circularHead = nullptr;
    while (true) {
        cout << "1. Insert element" << endl;
        cout << "2. Display list" << endl;
        cout << "3. Search element" << endl;
        cout << "4. Clear list" << endl;
        cout << "5. Back to main menu" << endl;
        cout << "-------------------" << endl;
        int option;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                if (choice == 1) {
                    insertSingly(singlyHead, data);
                } else if (choice == 2) {
                    insertDoubly(doublyHead, data);
                } else if (choice == 3) {
                    insertCircular(circularHead, data);
                }
                break;
            case 2:
                if (choice == 1) {
                    cout << "Singly Linked List: ";
                    displaySingly(singlyHead);
                } else if (choice == 2) {
                    cout << "Doubly Linked List: ";
                    displayDoubly(doublyHead);
                } else if (choice == 3) {
                    cout << "Circular Linked List: ";
                    displayCircular(circularHead);
                }
                break;
            case 3:
                cout << "Enter data to search: ";
                cin >> data;
                if (choice == 1) {
                    cout << (searchSingly(singlyHead, data) ? "Found" : "Not Found") << endl;
                } else if (choice == 2) {
                    cout << (searchDoubly(doublyHead, data) ? "Found" : "Not Found") << endl;
                } else if (choice == 3) {
                    cout << (searchCircular(circularHead, data) ? "Found" : "Not Found") << endl;
                }
                break;
            case 4:
                if (choice == 1) {
                    clearSingly(singlyHead);
                    cout << "Singly Linked List cleared." << endl;
                } else if (choice == 2) {
                    clearDoubly(doublyHead);
                    cout << "Doubly Linked List cleared." << endl;
                } else if (choice == 3) {
                    clearCircular(circularHead);
                    cout << "Circular Linked List cleared." << endl;
                }
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

int main() {
    while (true) {
        menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                linkedListMenu(1); 
                break;
            case 2:
                linkedListMenu(2); 
                break;
            case 3:
                linkedListMenu(3);
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
