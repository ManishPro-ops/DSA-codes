#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    // upper half
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(n-j<=i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        for(int j=0;j<n;j++){
            if(j<=i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    // lower half
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<n;j++){
            if(n-j<=i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        for(int j=0;j<n;j++){
            if(j<=i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
   return 0;
}