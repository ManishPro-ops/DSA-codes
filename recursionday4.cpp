#include <iostream>
using namespace std;

void reversestr(string &a,int i,int j)
{
    //cout << "call recieved for  :"<<a<< endl;
    if (i> j)
    {
        return ;     
    }
    swap(a[i],a[j]);
    i++;
    j--;
    return reversestr(a,i,j);
}
string reverse(string a){
    reversestr(a,0,a.length()-1);
    cout << "your final answer is"<<endl; 
    return a;
}
bool checkPalindrome(string& a,int i,int j){
    if (i> j)
    {
        return 1;     
    }
    if(a[i]!=a[j]){
        return 0;
    }
    else{
        return checkPalindrome(a,i+1,j-1);
    }
    
}
int main(){
    string a="manishsinam";
    string b=reverse(a);
    cout << b;
    bool is=checkPalindrome(a,0,a.length()-1);
    if(is){
        cout << " is a palindrome";
    }
    else{
        cout << " is not a palindrome";
    }
}