#include <iostream>
using namespace std;
int main(){
    int size;
    cout << " enter size of element"<< endl;
    cin >> size;
    // for(int i=0;i<size;i++){
    //     for (int j=0;j<size;j++){
    //         if (j!=i)
    //         {
    //             cout<< "-";
    //         }
    //         else
    //         {
    //             cout<< "*";
    //         }
    //         }
    for(int i=0;i<=size;i++){
        for (int j=0;j<(size-i)+1;j++){
                cout<< " ";
          
            }
        for (int k=size;k>(size-i);k--){
             cout<< "*";
        }
        cout<<endl;
    } 
}