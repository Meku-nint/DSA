// this program about array in cpp.
# include<iostream>
using namespace std;
void sorter(int num[],int size);
int main(){
    int num[5]={3,5,2,6,7};
    sorter(num,5);
     for(int i=0;i<5;i++){
            cout<<num[i];
            cout<<' ';
        }
    return 0;
}void sorter(int num[],int n){
        for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
           if(num[i]>num[j]) 
           swap(num[i],num[j]);
        }
    }