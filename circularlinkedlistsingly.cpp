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

    ~Node() {
        int value = this->data;
        if (this->next != nullptr) {
            delete this->next;
            this->next = nullptr;
        }
        cout << "Memory is free for node with data: " << value << endl;
    }
};

void insert(Node*& tail, int element, int d) {
    // Empty list
    if (tail == nullptr) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode; 
    }
    // Non-empty list
    else {
        Node* curr = tail;
        while (curr->data != element ){
            curr = curr->next;
        } 

        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail) {
    if (tail==nullptr){
        cout << " empty list :("<<endl;

    }
    Node* temp = tail;
    do {
        cout <<tail->data << " ";
        tail = tail->next;
    } while (temp != tail);
    cout << tail->data << endl; // Print the tail node's data to complete the circle
}
void deleteNode(Node* &tail,int value){
    if (tail==nullptr){
        cout<< "list is empty " <<endl;
        return;
    }
    else{
        Node* prev=tail;
        Node* curr =prev->next;
    while(curr->data!=value){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr ->next;
    //only one element present in linked list
    if(curr==prev)
    {                           
        tail=nullptr;
    }
    //for greater than or equal to 2 element
    else if(tail==curr)
    {                           //to handle tail
        tail=prev;         
    }                      
        curr->next=nullptr;
        delete curr;
    }
}
int main() {
    Node* tail = nullptr;

    // Inserting into the circular linked list
    insert(tail, 5, 3); // Since the list is empty, 3 will be inserted
    print(tail);

    // Additional insertions
    insert(tail, 3, 5);
    print(tail);

    insert(tail, 5, 7);
    print(tail);

    insert(tail, 3, 10);
    print(tail);

    deleteNode(tail,5);
    print(tail);

    deleteNode(tail,3);
    print(tail);

    deleteNode(tail,10);
    print(tail);

    deleteNode(tail,7);
    print(tail);

    //Clean up memory (delete the circular linked list)
    //delete tail;

    return 0;
}
