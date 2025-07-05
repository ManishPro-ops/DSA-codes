#include<iostream>
using namespace std;

class stack{
    public:
    int size;
    int *arr;               
    int top;
    stack(int size){
        this->size=size;
        arr= new int[size];
        top=-1;             
    }

    void push(int element){
        if(size-top >1){
            top++;
            arr[top]=element;
        }
        else{
            cout<< "stack overflow"<< endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
           cout<< "stack underflow" << endl;
        }
    }

    int peek(){
        if(top >= 0 && top< size)
        return arr[top];
        else 
        cout<< "empty stack" << endl;
        return -1;
    }

    bool isempty(){
        if(top ==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
      stack s(8);
      s.push(10);
      s.push(20);
      s.push(30);
      s.push(40);
      s.push(50);
      s.push(60);
      s.pop();
      s.pop();
      s.pop();
      s.pop();

      cout<< s.peek() << endl;

      s.pop();
      s.pop();

      cout<< s.peek() << endl;


      cout << s.isempty() << endl;




}