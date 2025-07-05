#include <iostream>
using namespace std;
// string namaste_duniya(){
//     int n;
//     cin >> n;
//     for (int i=0; i<n; i++){
//     cout << "namaste duniya" << endl;                       // understanding functions
//     }
//     return 0;
// }
// string function(){
    
//     string a;
    
//     a = namaste_duniya();
//     return a;
// }
// int main(){
    
//     cout<< "enter no time's you want to print ";
//     cout << function();
//     return 0;
// }
//  int power( int x,int y, int z=1){                                           // power function
//     for(int i=1;i<=y;i++){
//         z= z*x ;
//     }
//     return z;
// }
//  int main(){
//     int a,b;
//     cout << " enter a and b "<<endl;
//     cin >> a;
//     cin >> b;
//     int result = power(a,b);
//     cout << "result is "<< result;
//     return 0;
//  }

// int factorial ( int x){
//     int fact=1;
//     for ( int i=1; i<=x; i++){
//         fact = fact* i;
//     }
//     return fact;
// }
// int permutation( int n , int r){                                     // permutation of any number
//     int a=factorial(n);
//     int b=factorial(n-r);
//     int per = a/b;
//     return per;
// }
 
// int main(){
//     int a,b;
//     cout <<  "enter a ";
//     cin >> a;
//     cout <<  "enter b ";
//     cin >> b;
//     int result= permutation(a,b);
//     cout <<result ;
// }
// int term (int a){
//      int n= (3*a)+7;
//     return n;
// }
// int main(){                                                                   // term of an AP
//     int n;
//     cout << "enter no of term for AP "<<"3*n + 7"<< endl;
//     cin >> n;
//     int a= term(n);
//     cout<< a;
//     return a;
// }
// int setbits(int a){
//     int count=0;
//     int i=0;
//     while(a!=0)
//     {
//         int n= a%2;
//         if (n!=0)                                                                //setbits program
//         {
//             count+=1;
//         }
//         a=a>>1;
//     } 
//     return count;
//     i++;
// }
// int main (){
//     int a;
//     cout <<"enter digit "<< endl;
//     cin >> a;
//     int b= setbits(a);
//     cout << "no of setbits in A is"<<"  "<<b;

// }
// bool check( int num){
//     if (num%2==0){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int main(){                                                               // odd or even
//     int a;
//     cout<< "enter the number "<< endl;
//     cin >> a;
//     int x= check(a);
//     if (x == 1 ){
//         cout<< " entered no is even"<< endl;
//     }
//     else{
//         cout << " entered no is odd"<< endl;
//     }
// }
// bool prime(int n)
// {
//     for(int i=2;i<n;i++){
//         if(n%i==0){
//             return false;
//         }
            
//         }
//     return true;
// }
// int main(){                                                                         // prime or not
//     int a;
//     cout<< "enter the no"<< endl;
//     cin >> a;
//     int b= prime(a);
//     if (b==1){           // as 1=true in bool an we can write conditions as if(prime(a))--->for true value
//         cout<< " its a prime number  :)"; 
//     }
//     else{
//         cout << " its not a prime number :(";
//     }
 //   }
// void fibonacci(int x ){
//     int a=0;
//     int b=1;
//     cout << 0 << " "<< 1 << " ";
//     for (int i=1;i<=(x-2);i++){
//          int next_term = a+b;
//          cout<< next_term << " ";
//          a=b;
//          b=next_term;                                            // fibonacci series
//      }
//  }
//  int main (){
//     int a;
//     cout << "enter the no "<< endl;
//     cin >> a;
//     fibonacci(a);

//  }
// void count(int n){
//     for (int i=1;i<=n;i++){
//         cout <<i<< endl;
//     }                                                    //counting
// }
// int main(){
//     int a;
//     cout<<"enter the number"<< " ";
//     cin >> a;
//     count(a);
// }