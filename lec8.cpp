#include<iostream>
using namespace std;
int main(){
    int a,b;
    char ch ;
    cout << "enter a "<< endl;
    cin >> a;
    cout << "enter b "<< endl;
    cin >> b;
    cout << endl;
    cout << "enter the operation "<< endl;
    cin >> ch;
    switch(ch){
        case '*' :
        cout << a*b;
        break;
        case '+' :
        cout << a+b;
        break;
        case '-' :
        cout << a-b;
        break;
        case '%' :
        cout << a%b;
        break;
        case '/' :
        cout << float(a)/b;
        default :
        cout << "invalid operation ";
     
    // int a;
    // cout << "enter amount";
    // cin >> a;
    // while(a){
    //     switch(a){
    //         case 100 :
    //     cout << " no of 100's note"<< a/100;
    //     a= a/100;
    //     break;
    //     case 50 :
    //     cout << " no of 50's note"<< a/50;
    //     a=a/50 ;
    //     break;
    //     case 20  :
    //     cout << " no of 20's note"<< a/20;
    //     a= a/20;
    //     break;
    //     case 10 :
    //     cout << " no of 10's note"<< a/10;
    //     a= a/10;
    // }
    // exit();
        
    }
}

