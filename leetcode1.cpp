#include<iostream>
#include<math.h>
using namespace std;
int main(){                     
  /*
  int n,digit;
   int answer=0;
   cout << "enter the number "<<endl;                  //reversing number
   cin >> n; 
   while(n!=0){
   digit= n%10;
   answer = (answer * 10) + digit;
   n=n/10;
   if((answer > INT_MAX / 10) || (answer < INT_MIN / 10)){
    return 0;
   }
   }
   cout << answer;
   
  /*
  int n,answer,mask=0;
  cout << "enter the number "<<endl;                  // complement of any number
  cin >> n;
  int m=n;
  while(m!=0){
     mask=(mask << 1) | 1;           
     m= m >> 1;
  }
  
  answer= (~n)&mask;
  cout << answer;
 */
  /*
  int n;
  cout << "enter the number "<<endl;                  // if number can be written in power of n
  cin >> n;
  int product=1;
  for(int i=0;i<=30;i++){
    if(n==product)
    {
    cout<<"yes";
    break;
    }
    if(product < INT_MAX/2){
        product=product*2;
    }
    else{
       cout<<"no"; 
    }
    */
    /*
    int n,answer=0,m;
    cout << "enter value of n" << endl;
    cin >> n;
    n=abs(n);                                               //decimal to binary conversion for negative number
    for(int i=0;n!=0;i++){
    int bit=n%2;
    answer=bit*pow(10,i)+answer;                         
    n=n/2;

   }
   cout << "the binary representation for number"<< endl << -((~answer)+1);
  */
}
  

   
   
