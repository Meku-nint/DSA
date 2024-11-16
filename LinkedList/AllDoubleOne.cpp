#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
struct Student {
    string name;
    string id;
    Student *next;
    Student *prev;
};
Student *head = nullptr;
Student *tail = nullptr;
int choice,position;
void addStudent(string name, string id);
void addStudentToBeginning(string name, string id);
void deleteFromBeginning();
void deleteFromEnd();
void InsertionMenu();
void InsertAtPosition(string name,string id,int position);
void FirstMenu();
void DeltionMenu();
void addStudent(string name, string id) {
    Student *newStudent = new Student();
    newStudent->name = name;
    newStudent->id = id;
    newStudent->next = nullptr;
    newStudent->prev = nullptr;
    if (head == nullptr) {
        head = newStudent;
        tail = newStudent;
    } else {
        newStudent->prev = tail;
        tail->next = newStudent;
        tail = newStudent;
    }
}
void display() {
    Student *current = head;
    while (current != nullptr) {
        cout << "Name: " << current->name << "   ID: " << current->id << endl;
        current = current->next;
    }
}
void addStudentToBeginning(string name, string id) {
    Student *newStudent = new Student();
    newStudent->name = name;
    newStudent->id = id;
    newStudent->next = head;
    newStudent->prev = nullptr;
    if (head != nullptr) {
        head->prev = newStudent;
    } else {
        tail = newStudent; 
    }
    head = newStudent; 
}
void InsertAtPosition(string name,string id,int position){
    if (position==0){
    addStudentToBeginning(name,id);
    return;
    }
    Student *atposition=new Student();
    atposition->name=name;
    atposition->id=id;
    Student*current=head;
    for(int i=0;i<position-1&&current!=nullptr;i++){
        current=current->next;
    }
    if(current==nullptr){
        cout<<"Out of the bound \n";
        return ;
    }
    atposition->next=current->next;
    current->next=atposition;
    atposition->prev=current;
}
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Student *temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr; 
    }
    delete temp;
}
void deleteFromEnd() {
    if (tail == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Student *temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr; 
    }
    delete temp;
}
void DeleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "The list is empty\n";
        return;
    }

    if (position == 0) {
        deleteFromBeginning();
        return;
    }
    Student* current = head;
    for (int i = 0; i < position && current != nullptr; i++) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Out of bounds\n";
        return;}
    if (current == tail) {
        deleteFromEnd();
        return;
    }
    current->prev->next = current->next; 
    if (current->next != nullptr) {
        current->next->prev = current->prev; 
    }
    delete current;
}
void InsertionMenu() {
    string name, id;
    cin.get();
    system("cls");
    while (true) {
        cout << "1. Add student from the beginning\n";
        cout << "2. Add student to the end\n";
        cout << "3. Add student at posittion\n";
        cout << "4. Back to main menu\n";
        cout << "5. Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;
        cin.ignore();
        system("cls");
        cout<<"Before Operation :\n";
        display();
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter ID: ";
                getline(cin, id);
                addStudentToBeginning(name, id);
                break;
            case 2:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter ID: ";
                getline(cin, id);
                addStudent(name, id);
                break;
            case 3:
                cout<<"Enter the position :";
                cin>>position;
                cin.ignore();
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter ID: ";
                getline(cin, id);
                InsertAtPosition(name,id,position);
                cin.ignore();
                break;
            case 4:
                return;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout<<"\nAfter Operation :\n";
        display();
        cin.get();
    }
}
void FirstMenu() {
    while (true) {
        system("cls");
        cout << "1. Insertion Operation\n";
        cout << "2. Deletion Operation\n";
        cout << "3. Exit From The Program\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                InsertionMenu();
                break;
            case 2:
                DeltionMenu();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
void DeltionMenu() {
    cin.get();
    system("cls");
    while (true) {
        cout << "1. Delete from the beginning\n";
        cout << "2. Delete from the end\n";
        cout << "3. Delete from At Position\n";
        cout << "4. Back to main menu\n"; 
        cout << "5. Exit\n";
        cout << "   Please enter your choice: ";
        cin >> choice;
        cin.ignore();
        system("cls");
        cout<<"\tBefore Operation:\n";
        display();
        switch (choice) {
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
            DeleteAtPosition(position);
            break;
            case 4:
                return;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        cout<<"\n\tAfter Operation:\n";
        display();
        cin.get();
    }
}
int main() {
    system("cls");
    system("color 0A");
    addStudent("Amina Tesfaye", "2023-ET-001");
    addStudent("Samuel Kebede", "2023-ET-002");
    addStudent("Fatima Abebe", "2023-ET-003");
    addStudent("Mekonnen Yilma", "2023-ET-004");
    addStudent("Selamawit Biruk", "2023-ET-005");

    FirstMenu(); 
    return 0;
}