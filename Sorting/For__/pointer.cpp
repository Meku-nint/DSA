#include<iostream>
using namespace std;

int main() {
    int value = 5;                  // Declare an integer variable and assign it the value 5.
    int *pointer = &value;         // Declare a pointer and store the address of 'value'.
    cout << value;                  // Displays the value of 'value', which is 5.
    cin.get();
    cout << 
    pointer;               // Displays the address of 'value' in memory.
    cin.get();
    *pointer=8;
    cout<<value;
    return 0;
}