// this program is about fibonuc series.
# include<iostream>
using namespace std;
// this is about for looping.
int main()
{
    int value_one=0;
    int value_two=1,final;
    int length;
    cout<<"Enter the length of the fibonic series";
    cin>>length;
    cout<<value_one<<" ";
    cout<<value_two<<" ";
    for(int i=0;i<=length;i++)
    {
        final=value_one+value_two;
        cout<<final<<" ";
        value_one=value_two;
        value_two=final;
    }
    return 0;
}