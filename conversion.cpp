#include<iostream>
#include<math.h>
using namespace std;
int main(){
    /*
    int n;
    cout<< "enter the binary representation for number " << endl;
    cin >> n;
    int answer =0,bit;                                    //binary to decimal
    for (int i=0; n!=0;i++){
        bit= n % 10;
        answer = bit * pow(2,i) + answer ;
        n= n/10; 
    }
    cout <<" decimal representation for number" << endl <<answer ;
    */
   /*int n,answer=0,bit;
   cout << "enter the decimal representation" <<endl ;
   cin >> n;
   for(int i=0;n!=0;i++){
    bit= n&1;
    answer=bit*pow(10,i)+answer;                            //first way
    n=n>>1;

   }
   cout << "the binary representation for number" << endl<< answer;
   */

                                                         // decimal to binary
   int n,answer=0,bit;
   cout << "enter the decimal representation" <<endl ;
   cin >> n;
   for(int i=0;n!=0;i++){
    bit=n%2;
    answer=bit*pow(10,i)+answer;                            //second way
    n=n/2;

   }
   cout << "the binary representation for number"<< endl << answer;
    
} 