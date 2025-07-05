#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this -> data=d;
        this -> next=nullptr;
        this -> prev=nullptr;
    }
    ~Node(){
        int value=this->data;
        if (next != nullptr){
            delete next;
            next = nullptr;
        }
        cout<< "memory is free for data with value :"<< value<< endl;

    }
};

void print (Node* head ,  Node* tail){
    Node* temp=head;
    while(temp!=nullptr){                      //traversing
        cout<< temp -> data << " ";
        temp=temp -> next;
    }cout << endl << "head and tail are  : "<< head->data <<"  "<< tail->data<< endl;
}

int getlength(Node* head){
    int len=0;
    Node* temp =head;
    while(temp!=nullptr){
        len ++;
        temp=temp -> next ;
    }return len;
}

void insertAthead(Node* &head,int d){
    Node* temp = new Node(d);
    temp-> next= head;
    head-> prev= temp;
    head=temp;
}
void insertAttail(Node* & tail, int d){
    Node* temp= new Node(d);
    temp-> prev = tail;
    tail-> next = temp;
    tail=temp;
}

void insertAtpos(Node* & head,Node* &tail,int p, int d){
    if ( p ==1 ){
        insertAthead(head,d);
        return;
    }
    Node* temp= head;
    int cnt=1;
    while(cnt<p-1){
        temp=temp->next;
        cnt++;
    }
    if (temp->next==nullptr){
        insertAttail(tail,d);
        return;
    }

    Node* nodetoinsert =new Node(d);
    nodetoinsert -> next = temp -> next;
    temp-> next ->prev =nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev = temp;


}

void deleteNode(int p,Node* &head, Node* &tail){
    if (p==1){
       Node* temp=head;
       temp->next->prev=nullptr;
       head=temp->next;
       temp->next=nullptr;
       delete temp;
    }

    else{
        Node* curr= head;
        Node* prev= nullptr;

        int cnt=1;
        while(cnt<p){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

            curr->prev=nullptr;
            prev->next=curr->next;
            if (curr->next == nullptr) {
            tail = prev;          // Update tail if the last node is deleted
            }
            curr->next=nullptr;
            delete curr; 
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head,tail);
    insertAthead(head,15);
    print(head,tail);
    insertAttail(tail,15);
    print(head,tail);
    insertAtpos(head,tail,3,10);
    print(head,tail);
    insertAtpos(head,tail,5,102);
    print(head,tail);
    deleteNode(4,head,tail);
    print(head,tail);
    deleteNode(4,head,tail);
    print(head,tail);

}