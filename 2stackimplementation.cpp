#include<iostream>
using namespace std;

class stack{
    public:
    int size;
    int *arr;               
    int top1;
    int top2;
    stack(int size){
        this->size=size;
        arr= new int[size];
        top1=-1;             //if we take another top = size we can store two stack one will be stored reversely from last
        top2=size;
    }

    void push1(int element){
        if(top2-top1 >1){
            top1++;
            arr[top1]=element;
        }
        else{
            cout<< "stack overflow"<< endl;
        }
    }

    void push2(int element){
        if(top2-top1 >1){
            top2--;
            arr[top2]=element;
        }
        else{
            cout<< "stack overflow"<< endl;
        }
    }

    int pop1(){
        if(top1 >= 0 ){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else{
           cout<< "stack underflow" << endl;
           return -1;
        }
    }

    int pop2(){
        if(top2 >= 0 ){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else{
           cout<< "stack underflow" << endl;
           return -1;
        }
    }

    
};

int main(){
      stack s(8);
      s.push1(10);
      s.push2(20);
      s.push1(30);
      s.push2(40);
      s.push1(50);
      s.push2(60);
      cout<<s.pop1()<<endl;
      cout<<s.pop2()<<endl;      
      cout<<s.pop1()<<endl;

      


      




}