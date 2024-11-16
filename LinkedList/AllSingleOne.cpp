#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Contact {
    string name;
    string number;
    Contact* next;
};
Contact* head = NULL;
void addContactToBeginning(string name, string number) {
    Contact* newContact = new Contact();
    newContact->name = name;
    newContact->number = number;
    newContact->next = head;
    head = newContact;
}
void addContactToEnd(string name,string number) {
    Contact* newContact = new Contact();
    newContact->name = name;
    newContact->number = number;
    newContact->next = NULL;

    if (head == NULL) {
        head = newContact;
    } else {
        Contact* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
}
void addContactAtPosition(string name,string number, int position) {
    if (position == 0) {
        addContactToBeginning(name, number);
        return;
    }
    Contact* newContact = new Contact();
    newContact->name = name;
    newContact->number = number;
    Contact* current = head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Position out of bounds. Adding to the end instead.\n";
        addContactToEnd(name, number);
        return;
    }
    newContact->next = current->next;
    current->next = newContact;
}
void displayContacts() {
    Contact* current = head;
    if (current == NULL) {
        cout << "No contacts available.\n";
        return;
    }
    while (current != NULL) {
        cout << "Name: " << current->name << ", Number: " << current->number << endl;
        current = current->next;
    }
}
void 
deleteFromBeginning() {
    system("cls");
    cout<<"Before Deletion :: \n";
    displayContacts();
    cout<<"\n\n";
    if (head == NULL) {
        cout << "No contacts to delete.\n";
        return;
    }
    Contact* temp = head;
    head = head->next;
    delete temp;
    cin.get();
    }
void deleteFromEnd() {
    system("cls");
    cout<<"Before Deletion :: \n";
    displayContacts();
    if (head == NULL) {
        cout << "No contacts to delete.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Deleted the only contact.\n";
        return;
    }
    Contact* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    cout << "Deleted contact from the end.\n";
}
void deleteAtPosition(int position) {
    system("cls");
    cout<<"Before Deletion :: \n";
    displayContacts();
    if (head == NULL) {
        cout << "No contacts to delete.\n";
        return;
    }
    if (position == 0) {
        deleteFromBeginning();
        return;
    }
    Contact* current = head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
       cout<<"Out bound.";
       return;
    }
    Contact* temp = current->next;
    current->next = temp->next;
    delete temp;
    cout << "Deleted contact at position " << position << ".\n";
}
void addContactMenu() {
    int choice;
    string name, contact;
    int position;
    while (true) {

        cin.get();
        system("cls");
        cout << "1. Add contact from the beginning\n";
        cout << "2. Add contact to the end\n";
        cout << "3. Add contact at any position\n";
        cout << "4. Back to main menu\n";
        cout << "5. Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter number: ";
                getline(cin, contact);
                system("cls");
                cout<<"Before Added contact :\n\n";
                displayContacts();
                cout<<"After Contact is addded :\n\n";
                addContactToBeginning(name, contact);
                displayContacts();
                break;
            case 2:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter number: ";
                getline(cin, contact);
                system("cls");
                cout<<"Before Added contact :\n\n";
                displayContacts();
                cout<<"After Contact is addded :\n\n";
                addContactToEnd(name, contact);
                displayContacts();
                break;
            case 3:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter number: ";
                getline(cin, contact);
                cout << "Enter the position to add: ";
                cin >> position;
                system("cls");
                cout<<"Before Added contact :\n\n";
                displayContacts();
                cout<<"After Contact is addded :\n\n";
                addContactAtPosition(name, contact, position);
                displayContacts();
                cin.get();
                break;
            case 4:
                return; 
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
void deleteContactMenu() {
    int choice, position;
    while (true) {
        cout << "1. Delete from the beginning\n";
        cout << "2. Delete from the end\n";
        cout << "3. Delete at any position\n";
        cout << "4. Back to main menu\n";
        cout << "5. Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                deleteFromBeginning();
                break;
            case 2:
                deleteFromEnd();
                break;
            case 3:
                cout << "Enter the position to delete: ";
                cin >> position;
                deleteAtPosition(position);
                break;
            case 4:
                return; // Go back to the main menu
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout<<"\tAfter Operation \n\n";
        displayContacts();
    }
}
void firstMenu() {
    int choice;
    while (true) {
        system("cls");
        cout << "1. Add contact\n";
        cout << "2. Delete contact\n";
        cout << "3. Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addContactMenu();
                break;
            case 2:
                deleteContactMenu();
                break;
            case 3:
                exit(0);
            default:
                cout << "Incorrect input. Please try again.\n";
                break;
        }
    }
}
int main()
 {
system("cls");
    addContactToBeginning("Tsegaye Bekele", "0912345678");
    addContactToBeginning("Marta Alemayehu", "0923456789");
    addContactToBeginning("Kebede Guta", "0934567890");
    addContactToBeginning("Hana Tesfaye", "0945678901");
    addContactToBeginning("Abebe Banto", "0956789012");
    addContactToBeginning("Fatuma Mohammed", "0967890123");
firstMenu();
return 0;
}