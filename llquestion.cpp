#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=nullptr){
            delete next;
            this->next=nullptr;
        }
        cout << "memory is free for node with data "<< value << endl;

    }
};
Node* reverse1(Node* head)
{
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* chotahead =reverse1(head->next);
    
    head->next->next = head;
    head->next=nullptr;
    return chotahead;

}

Node* reverseHead(Node* head, int k) 
{
    if (head == nullptr || k == 1) {
        return head; // no need to reverse if list is empty or k is 1
    }

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != nullptr) {
        head->next = next; // connect the reversed part to the rest of the list
    }

    return prev; // new head of the reversed list
}

int getlength(Node* &head){
    Node* temp = head;
    int count=0;
    while(temp!=nullptr)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void reverse(Node* & head,Node* curr,Node* prev)
{
    if(curr==nullptr){
        head= prev;
        return;
    }

    Node* forward=curr->next;
    reverse(head,forward,curr);
    curr-> next = prev;   // to break the connection in forward direction
}

Node* reversell(Node* &head)
{
    // if(head ==nullptr || head -> next ==nullptr){
    //     return head ;                                     //empty or single element in linked list
    // }
    // Node* curr=head;
    // Node* prev=nullptr;
    // Node* forward=nullptr;
    // while(curr!=nullptr){
    //     forward=curr->next;
    //     curr->next=prev;       // to break the connection in forward direction
    //     prev=curr;
    //     curr = forward;
    // }
    // return prev;

    /*Node* curr = head;
    Node* prev = nullptr;
    reverse(head,curr,prev);                     //reverse
    return head;*/

    
    return reverse1(head);                      //reverse1
}



void insertAthead(Node* &head, int d) {
    Node* temp = new Node(d);                    
    temp->next = head;
    head = temp;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAttail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtposition(Node* &tail, Node* &head, int position, int d) {
    if (position == 1) {
        insertAthead(head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != nullptr) {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        insertAttail(tail, d);
    } 
    else {
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
        if (nodeToInsert->next == nullptr) {
            tail = nodeToInsert;
        }
    }
}

void deleteNode(int position,Node* &head,Node* &tail){
    if (position ==1 ){
        Node* temp=head;
        head=head->next;
        temp->next=nullptr;
        delete temp;
    }
    else{
        Node* curr =head;
        Node* prev=nullptr;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        if (curr->next == nullptr) {
            tail = prev;  // Update tail if the last node is deleted
        }
        curr->next = nullptr;
        delete curr;
    }
}

Node* printmiddle(Node* head){
    // int len= getlength(head);
    // int ans = len/2;
    // int count=0;
    // Node* temp = head;
    // while(count<ans)                          //approach 1
    // {
    //     temp=temp->next;
    //     count++;
    // }
    // return temp;


    if(head==nullptr || head-> next == nullptr){
        return head;
    }
    if(head->next->next == nullptr){
        head->next;
    }
    Node* slow = head;
    Node* fast=head->next;
    while(fast!= nullptr){
        fast=fast->next;
        if(fast !=nullptr){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAttail(tail, 12);
    print(head);
    insertAttail(tail, 15);
    print(head);
    insertAttail(tail, 10);
    print(head);
    insertAttail(tail, 8);
    print(head);
    insertAttail(tail, 5);
    print(head);
    insertAtposition(tail, head, 2, 14);
    print(head);
    insertAtposition(tail, head, 3, 17);
    print(head);

    insertAtposition(tail, head, 4, 18);
     print(head);
    
    // Node* newhead=reversell(head);
    // print(newhead);

    reverseHead(head,2);
    print(head);

    //cout << printmiddle(head)->data;

    // cout << "head: " << head->data << endl;
    // cout << "tail: " << tail->data << endl;
    // // deleteNode(4,head,tail);
    // cout << "tail: " << tail->data << endl;
    
    return 0;
}
