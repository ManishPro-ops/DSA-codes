#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    cin >> n;
    i=1;
   /* 
   while(i<=n){
        j=1;
        while(j<=n){
            cout << i;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    
   while(i<=n){
        j=1;
        while(j<=i){
            cout << i;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    
   while(i<=n){
        j=1;
        while(j<=i){
            cout << n-i+1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    */
   while(i<=n){
        j=1;
        while(j<=n-i+1){
            cout << j;
            j=j+1;
        }
        int start= i-1;
        while(j < i-n+1){
            cout<<"*";
        }
        cout<<endl;
        i=i+1;
    }
}