#include <iostream>
using namespace std;

int fact(int n)                             // factorial function using recursion 
{
    if(n==0)
    {
        return 1;
    }
    return n*fact(n-1);
}
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n+ sum(n-1);
}
int pow(int n){
    if (n==0){
        return 1;
    }
    return 2* pow(n-1);
}
int fibona(int n){
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    int ans = fibona(n-1)+fibona(n-2);
    return ans;
}
int main ()
{
    int n;
    cout << "enter the no :"<< endl;
    cin >> n;
    int factorial =fact(n);
    cout <<"factorial is  :   " <<factorial << endl;
    int sum_ =sum(n);
    cout <<"sum of numbers  :  "<< sum_<< endl;
    int pow_ =pow(n);
    cout << "power is :   "<<pow_<< endl;
    int fibonacci_= fibona(n);
    cout <<"fibonacci number at position "<< n<<" :" <<  fibonacci_;

}