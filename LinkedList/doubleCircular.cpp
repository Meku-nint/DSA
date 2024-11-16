#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Person {
    string Pname;
    string Address;
    Person* next;
    Person* prev; 
};
Person* head = nullptr;
Person* tail = nullptr; 
int position;
string name, address;
void insertBeginning(string name, string address) {
    Person* beg = new Person();
    beg->Pname = name;
    beg->Address = address;

    if (head == nullptr) {
        head = beg;
        tail = beg;
        beg->next = head; 
        beg->prev = head;
    } else {
        beg->next = head; 
        beg->prev = tail; 
        tail->next = beg; 
        head->prev = beg; 
        head = beg; 
    }
}

void display() {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }
    Person* current = head;
    do {
        cout << "Name: " << current->Pname << "\tAddress: " << current->Address << endl;
        current = current->next;
    } while (current != head);
}

void insertEnd(string name, string address) {
    Person* end = new Person();
    end->Pname = name;
    end->Address = address;

    if (head == nullptr) {
        head = end;
        tail = end;
        end->next = head;
        end->prev = head;
    } else {
        end->prev = tail; 
        end->next = head; 
        tail->next = end; 
        head->prev = end; 
        tail = end;
    }}
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }
    if (head->next == head) { 
        delete head;
        head = nullptr;
        tail = nullptr; 
        return;
    }
    Person* temp = head; 
    head = head->next; 
    tail->next = head;
    head->prev = tail; 
    delete temp; 
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Person* temp = tail; 
    tail = tail->prev; 
    tail->next = head; 
    head->prev = tail; 
    delete temp; 
}

void deleteAnyPosition(int position) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    if (position == 0) {
        deleteFromBeginning();
        return;
    }
    Person* current = head;
    for (int i = 0; i < position && current->next != head; i++) {
        current = current->next;
    }
    if (current == head) {
        cout << "Out of bounds." << endl;
        return;
    }
    if (current->next == head) {
        deleteFromEnd();
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current; 
}

void insertAnyPosition(string name, string address, int position) {
    Person* newOne = new Person();
    newOne->Pname = name;
    newOne->Address = address;

    if (position == 0) {
        insertBeginning(name, address);
        return;
    }
    Person* current = head;
    for (int i = 0; i < position - 1 && current->next != head; i++) {
        current = current->next;
    }
    newOne->next = current->next;
    newOne->prev = current;
    current->next->prev = newOne;
    current->next = newOne;
    if (newOne->next == head) {
        tail = newOne;
    }
}
void deletionMenu() {
    system("cls");
    int choice;
    cout << "1. for deletion at beginning \n";
    cout << "2. for deletion at end \n";
    cout << "3. for deletion at any position \n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    system("cls");
    cout << "Before Operation:\n";
    display();
    switch (choice) {
        case 1:
            deleteFromBeginning();
            break;
        case 2:
            deleteFromEnd();
            break;
        case 3:
            cout << "Enter the position: ";
            cin >> position;
            cin.ignore();
            deleteAnyPosition(position);
            break;
        default:
            cout << "Wrong input \n";
            break;
    }
    cout << "\nAfter Operation : \n";
    display();
    cin.get();
    deletionMenu();
}

void insertMenu() {
    system("cls");
    int choice;
    cout << "1. for insertion at beginning\n";
    cout << "2. for insertion at end\n";
    cout << "3. for insertion at any position\n";
    cout << "4. for back to main menu\n";
    cout << "5. for exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    if (choice == 4) {
        return;
    }
    if (choice == 5) {
        exit(0);
    }
    cout << "Name: ";
    getline(cin, name);
    cout << "Address: ";
    getline(cin, address);
    system("cls");
    cout << "Before Operation:\n";
    display();
    switch (choice) {
        case 1:
            insertBeginning(name, address);
            break;
        case 2:
            insertEnd(name, address);
            break;
        case 3:
            cout << "Enter the position: ";
            cin >> position;
            cin.ignore();
            insertAnyPosition(name, address, position);
            break;
        default:
            cout << "Wrong input \n";
            insertMenu();
            break;
    }
    cout << "\nAfter Operation : \n";
    display();
    cin.get();
    insertMenu();
}

void firstMenu() {
    int choice;
    cout << "1. for insertion operation \n";
    cout << "2. for deletion operation \n";
    cout << "3. for exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    system("cls");
    switch (choice) {
        case 1:
            insertMenu();
            break;
        case 2:
            deletionMenu();
            break;
        case 3:
            exit(0);
        default:
            cout << "Wrong input :\n";
            firstMenu();
            break;
    }
}

int main() {
    system("cls");
    insertEnd("Bilal", "Addis Ababa");
    insertEnd("Suleman", "Addis Ababa");
    insertEnd("Yane", "Addis Ababa");
    firstMenu();
    return 0;
}
