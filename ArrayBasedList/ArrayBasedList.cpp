# include <iostream>
# include<cstdlib>
using namespace std;
void DTail();
void Dany_position();
void IHead();
void ITail();
void Iany_position();
void DHead();
int n=6;
int max_size=25;
double list[]={23,2,45,6,74,29};
int choice;
int size;
int target;  // this will be the element to be inserted,to be delted or to be trversed.
void insertion();
void deletion();
void Display_menu(){
        cout<<"\n1, for Isertion \n";
        cout << "2. For Deletion\n";
        cout << "3. For Exit\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            exit(0);
            break;
        default:
        cout<<"wrong input insert again";
        Display_menu();
            break; }
        }
int main(){
    system("cls");
    system("color 0A");
    cout<<"\t\tWelcome To Array Based List\n\n";
    cout<<"Press Enter to next : ";
    cin.get();
    Display_menu();
    return 0;
}
void IHead(){
            system("cls");
            cout<<"Enter the target you want to insert :";
            cin>>target;
            n=n+1;
              cout<<"The list Befor insertion was :";
            for(int i=0;i<n;i++){
                cout<<list[i]<<"  ";
            }
            for(int i=n;i>0;i--){
              list [i]=list[i-1];
            }
            list[0]=target;
            cout<<"\nthe new list : ";
            for(int i=0;i<n;i++){
                cout<<list[i]<<"  ";
            }
            }
void Iany_position()
{               int position;
                cout<<"Enter the position you want to insert your target : ";
                cin>>position;
                cout<<"Enter the target you want to insert : ";
                cin>>target;
                n=n+1;
             system("cls");
              cout<<"The list Befor insertion was :";
            for(int i=0;i<6;i++){
                cout<<list[i]<<"  ";
            }
                for(int i=n;i>=position;i--){
                 list[i]=list[i-1];
                }
                list[position-1]=target;
                 cout<<"\nthe new list : ";
                 for(int i=0;i<n;i++){
                 cout<<list[i]<<"  ";
            }
            }
void ITail() {
            system("cls");
             cout<<"Enter the target you want to insert :";
             cin>>target;
              cout<<"The list Befor insertion was :";
            for(int i=0;i<6;i++){
                cout<<list[i]<<"  ";
            }
            list[n]=target;
            n=n+1;
            cout<<"\nthe new list : ";
            for(int i=0;i<n;i++){
                cout<<list[i]<<"  ";
            }
          }
void Dany_position(){
            int position;
             system("cls");
            cout<<"The list Befor Deletion was :";
            for(int i=0;i<6;i++){
                cout<<list[i]<<"  ";
            }
                cout<<"\nEnter the position you want to delete : ";
                cin>>position;
               n=n-1;            
                for(int i=position-1;i<n;i++){
                 list[i]=list[i+1];
                }
                 cout<<"\nthe new list : ";
                 for(int i=0;i<n;i++){
                 cout<<list[i]<<"  ";
            }
            }
 void DHead(){
            system("cls");
             cout<<"The list Befor Deletion was :";
            for(int i=0;i<6;i++){
            cout<<list[i]<<"  ";
            }
            n=n-1;
            for(int i=0;i<n;i++){
            list[i]=list[i+1];
            }
            cout<<"\n\nthe new list : ";
            for(int i=0;i<n;i++){
                cout<<list[i]<<"  ";
                }           
        }
 void DTail() {
            system("cls");
             cout<<"Enter the target you want to insert :";
             cin>>target;
              cout<<"The list Befor insertion was :";
            for(int i=0;i<6;i++){
                cout<<list[i]<<"  ";
            }
            n=n-1;
            cout<<"\nthe new list : ";
            for(int i=0;i<n;i++){
                cout<<list[i]<<"  ";
            }
          }
void deletion(){
    system("cls");
    cout<<"1, to delete the head\n";
    cout<<"2,to delete the tail\n";
    cout<<"3,to delete your want position\n";
    cout<<"4, back to menu\n";
    cout<<"5,to exit\n\n";
     cin>>choice;
            switch (choice)
        {
        case 1:
            DHead();
            break;
        case 2:
            DTail();
            Display_menu();
            break;
        case 3:
            Dany_position();
            break;
        case 4:
         Display_menu(); ;
        case 5:
            exit(0);
            break;
        default:
        cout<<"wrong input insert again";
        Display_menu();
            break; }
         Display_menu();
        }
void insertion(){
    system("cls");
    cout<<"1,to insert on the head\n";
    cout<<"2,to insert on the tail\n";
    cout<<"3,to insert your position\n";
    cout<<"4, back to menu\n";
    cout<<"5,to exit\n\n";
    cout<<"\tchoice : ";
        cin>>choice;
            switch (choice)
        {
        case 1:
            IHead();
            break;
        case 2:
            ITail();
            break;
        case 3:
            Iany_position();
            break;
        case 4:
            Display_menu();
        case 5:
            exit(0);
            break;
        default:
        cout<<"wrong input insert again";
        Display_menu();
            break;
         }
         Display_menu();
        }