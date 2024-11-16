#include<iostream>
#include<cstdlib>
using namespace std;
// bubble sort
int main(){
    system("cls");
    system("color 0B");
    cout<<"Enter your size of the array :";
    int n;
    cin>>n;
    double array[n];
    for (int i=0;i<n;i++){
            cout<<"Enter the array index of  :"<< i<<"  ";
        cin>>array[i];
    }
    for(int i=n;i>0;i--)
    for(int j=0;j<n-1;j++){
        if(array[j]>array[j+1])
        swap(array[j],array[j+1]);
    }
    cout<<"This is sorted array :";
    for(int i=0;i<n;i++)
    cout<<array[i]<<"  ";
    return 0;

    // The time complixity of the bubble sorting is n^2.
}