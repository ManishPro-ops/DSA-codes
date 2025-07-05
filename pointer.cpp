#include<iostream>
using namespace std;
 
int main()
{
    int a = 5;
    int* b= &a;
    int ** c = &b;
    cout <<"address is stored in b as b is pointer to " << b << endl;
    cout << "value at address b "<< *b << endl;
    cout <<"address is stored in c as c is pointer to " << c << endl;
    cout << "value at address c "<< *c << endl;
    cout << "value at address address stored by c "<< **c << endl;



}