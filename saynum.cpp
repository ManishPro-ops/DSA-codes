#include <iostream>
using namespace std;

void saynum(int n,string arr[] )
{
    if(n==0)
    {
        return  ;
    }
    int num = n%10;
    n=n/10;
    saynum(n,arr);
    cout<< arr[num];
}
int main (){
    string arr[10]={" zero "," one "," two ",
                    " three "," four "," five",
                    " six "," seven "," eight "," nine "};
    int n;
    cout << "enter the no :"<< endl;
    cin>>n;
    cout << endl<<endl;
    saynum(n,arr);
}