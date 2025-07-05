#include<iostream>
using namespace std;

int pow(int a, int b){
    if (b==0){
        return 1;
    }
    int ans=pow(a,b/2);
    if (b==1){
        return a;
    }
    if( b%2==0){
        return ans*ans;
    }
    else {
        return a*ans*ans;
    }
}

int main (){
    int a,b;
    cin >> a>> b;
    int c=pow(a,b);
    cout << endl << c <<endl;
}