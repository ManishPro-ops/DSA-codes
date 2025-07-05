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

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAttail(tail, 12);
    print(head);
    insertAttail(tail, 15);
    print(head);
    insertAtposition(tail, head, 4, 14);
    print(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    deleteNode(4,head,tail);
    cout << "tail: " << tail->data << endl;
    return 0;
}
