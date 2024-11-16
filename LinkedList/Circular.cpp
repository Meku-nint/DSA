#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Person {
    string Pname;
    string Address;
    Person* next;
};
Person* head = nullptr;
int position;
string name,address;
void insertBeginning(string name, string address) {
    Person* beg = new Person();
    beg->Pname = name;
    beg->Address = address;
    if (head == nullptr) { 
        head = beg;
        beg->next = head; // Point to itself
    } else {
        Person* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = beg;
        beg->next = head; 
        head = beg;
    }
}
void firstMenu();
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
void insertEnd(string name,string address){
    Person* end = new Person();
    end->Pname = name;
    end->Address = address;
    if (head == nullptr) {
        head = end;
        end->next = head; 
    } else {
        Person* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = end;
        end->next = head; 
    }
}
void deleteFromBeginning() {
    if (head == nullptr) {
            display();
        cout << "The list is empty" << endl;
        return;
    }
    Person* current = head;
    while (current->next != head) {
        current = current->next;
    }
    head=head->next;
    current->next=head;
        delete current;

}
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }
    Person* current = head;
    while (current->next->next != head) {
        current = current->next;
    }
    current->next = head;
    delete current->next;
    current->next = nullptr;
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
    Person* previous = nullptr;

    for (int i = 0; i < position && current->next != head; i++) {
        previous = current;
        current = current->next;
    }
    if (current == head && position > 0) {
        cout << "Out of bounds." << endl;
        return;
    }
    if (current->next == head) {
        previous->next = head;
        delete current;
        return;
    }
    previous->next = current->next;
    delete current;
}
void delationMenu(){
    system("cls");
    int choice;
    cout<<"1. for deletion at beginning \n";
    cout<<"2. for deletion at end \n";
    cout<<"3. for deletion at any position \n";
    cout<<"Enter your choice: ";
    cin>>choice;
    cin.ignore();
    system("cls");
    cout<<"Befor Operation :\n";
    display();
    switch(choice){
        case 1:
            deleteFromBeginning();
            break;
        case 2:
            deleteFromEnd();
            break;
        case 3:
        cout<<"Enter the position : ";
        cin>>position;
        cin.ignore();
        deleteAnyPosition(position);
            break;
        default :
         cout<<"Wrong input \n";
         break;
    }
    cout<<"\nAfter Operation : \n";
    display();

cin.get();
delationMenu();
}

void insertAnyPosition(string name,string address,int position){
    Person* newOne = new Person();
    newOne->Pname = name;
    newOne->Address = address;
    if (position==0) {
        insertBeginning(name,address);
        return;
    } else {
        Person* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newOne->next = current->next;
        current->next = newOne;
    }
}
void insertMenu(){
    system("cls");
    int choice;
    cout<<"1. for insertion at beginning\n";
    cout<<"2. for insertion at end\n";
    cout<<"3. for insertion at any position\n";
    cout<<"4. for back to main menu\n";
    cout<<"5. for exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;
   cin.ignore();
   if(choice==4){
    firstMenu();
   }
   if(choice==5){
        exit(0);
    }
    cout<<"Name : ";
    getline(cin,name);
    cout<<"Address : ";
    getline(cin,address);
    system("cls");
     cout<<"Before Operation:\n";
    display();
    switch(choice){
        case 1:
            insertBeginning(name,address);
            break;
        case 2:
            insertEnd(name,address);
            break;
        case 3:
            cout<<"Enter the position : ";
            cin>>position;
            cin.ignore();
            insertAnyPosition(name,address,position);
            break;
        default :
        cout<<"Wrong input \n";
        insertMenu();
        break;
    }
    cout<<"\nAfter Operation : \n";
    display();
    cin.get();
    insertMenu();
}
void firstMenu(){
    int choice;
    cout<<"1. for insertion operation \n";
    cout<<"2, for delation operation \n";
    cout<<"5, for exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    cin.ignore(); 
    system("cls"); 
    switch(choice){
        case 1:
            insertMenu();
            break;
        case 2:
            delationMenu();
            break;
            case 5:
            exit(0) ;
        default:
        cout<<"Wrong input :\n" ;
        firstMenu();
        break;
    }}
int main() {
    system("color B1");

    system("cls");
    insertEnd("Bilal", "Addis Ababa");
    insertEnd("Suleman", "Addis Ababa");
    insertEnd("Yane", "Addis Ababa");
    firstMenu();
    return 0;
}