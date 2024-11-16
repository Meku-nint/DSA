#include <iostream>
#include <string>

using namespace std;
struct Node {
    string data;
    Node* next;
    Node* prev;

    Node(string value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(string value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void displayBackward() {
        Node* current = tail;
        cout << "The strings backward are: ";
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;
    string input;
    cout << "Enter strings (type 'exit' to finish):" << endl;
    while (true) {
        getline(cin, input);
        if (input == "exit") break;
        list.insert(input);
    }
    list.displayBackward();
    return 0;
}
