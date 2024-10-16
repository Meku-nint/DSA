#include <iostream>
#include <cstdlib>
using namespace std;
class Sorting {
public:
    int length_of_array;
    double* array; // Declaration of dynamic array.
    void Array_accepter(int length) {
        length_of_array = length;
        array = new double[length_of_array];
        cout << "Enter " << length_of_array << " elements:\n";
        for (int i = 0; i < length_of_array; i++) {
            cin >> array[i];
        }
    }
    void bubble_sort() {
        for (int i = 0; i < length_of_array - 1; i++) {
            for (int j = 0; j < length_of_array - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                }
            }
        }
        display_array();
    }
    void selection_sort() {
        for (int i = 0; i < length_of_array - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < length_of_array; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            swap(array[i], array[minIndex]);
        }
        display_array();
    }
//3,1,25,6,7
    void insertion_sort() {
        for (int i = 1; i < length_of_array; i++) {
            double key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
        display_array();
    }
    void display_array() {
        cout << "Sorted array: ";
        for (int i = 0; i < length_of_array; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    void sorting_menu() {
        cout << "\n1. For Bubble Sorting\n";
        cout << "2. For Selection Sorting\n";
        cout << "3. For Insertion Sorting\n";
        cout << "4. For Back to Main Menu\n";
        cout << "5. For Exit\n\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                bubble_sort();
                break;
            case 2:
                selection_sort();
                break;
            case 3:
                insertion_sort();
                break;
            case 4:
                system("cls");
                return;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice, try again.\n";
                sorting_menu();
                break;
        }
    }
};
class Searching {
public:
    double array_for_searching[10] = {23, 0, 34, -4, 0.8, 4, 21, 24};
    void linear_searching() {
        cout << "Enter your target: ";
        double target;
        cin >> target;
        for (int i = 0; i < 8; i++) {
            if (target == array_for_searching[i]) {
                system("cls");
                cout << "Found at index " << i << endl;
                return;
            }
        }
        system("cls");
        cout <<target << " Not found\n";
        cin.get();
    }
    void binary_searching() {
        // Sort the array before binary searching
        bubble_sort(array_for_searching, 8);
        cout << "Enter your target: ";
        double target;
        cin >> target;
        int low = 0, high = 7, middle;
        while (low <= high) {
            middle = low + (high - low) / 2;
            if (target == array_for_searching[middle]) {
                system("cls");
                cout << "Found at index " << middle << endl;
                return;
            } else if (target > array_for_searching[middle]) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        } 
        system("cls");
        cout << "Not found!\n";
        cin.get();
    }
    void bubble_sort(double arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    void Searching_menu() {
        int x;
        do {
            cout << "\t1. For Linear Searching.\n";
            cout << "\t2. For Binary Searching.\n";
            cout << "\t3. For Exit from the Program.\n";
            cout << "\t4. For Back to the Main Menu.\n";
            cout << "Enter your choice: ";
            cin >> x;
            switch (x) {
            case 1:
            linear_searching();
            break;
            case 2:
            binary_searching();
            break;
            case 4:
            return;
            case 3:
            exit(0);
            default:
            system("cls");
            cout << "Try again\n";
            break;
            }
            } while (x != 3);
            }
};
int first_menu() {
    int choice;
    cout << "\n\n\t1. For Searching\n";
    cout << "\n\t2. For Sorting\n";
    cout << "\n\t3. For Exit\n\n";
    cout << "Enter your choice: ";
    cin >> choice;
    system("cls");
    return choice;
}
void Dessission() {
    Searching searching;
    Sorting sorting;
    int value;
    do {
        value = first_menu();
        switch (value) {
            case 1:
                searching.Searching_menu();
                break;
            case 2:
                int length;
                cout << "Enter number of elements: ";
                cin >> length;
                sorting.Array_accepter(length); // Accept user input for dynamic array
                sorting.sorting_menu();
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                system("cls");
                cout << "Error input, try again!\n";
                break;
        }
    } while (value != 3);
}
int main() {
    system("cls");
    system("color 0B");
    cout << "\n\n\n\t\t------------Welcome-------------\n";
    cout << "\n\n\t\tEnter any key for next: ";
    cin.get();
    system("cls");
    system("color 0A");
    Dessission();
    system("cls");
    cout << "\n\n\t\tEXITING...\n\n";
    return 0;
}