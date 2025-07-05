#include <iostream>

//creation of circular queue
class MyCircularQueue {
public:
    int size;
    int* arr;
    int front;
    int rear;

    // Constructor
    MyCircularQueue(int k) {
        this->size = k;
        arr = new int[k];  // Allocate array with the correct size
        this->front = -1;
        this->rear = -1;
    }

    // Destructor to free memory
    ~MyCircularQueue() {
        delete[] arr;
    }

    bool enQueue(int value) {
        // Insertion
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;  // Wrap around
        } else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            rear = front = -1;  // Queue becomes empty after removal
        } else if (front == size - 1) {
            front = 0;  // Wrap around
        } else {
            front++;
        }
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


int main() {
    // Create a circular queue of size 5
    MyCircularQueue* q = new MyCircularQueue(5);

    // Enqueue elements
    std::cout << "Enqueue 10: " << q->enQueue(10) << std::endl;  // True
    std::cout << "Enqueue 20: " << q->enQueue(20) << std::endl;  // True
    std::cout << "Enqueue 30: " << q->enQueue(30) << std::endl;  // True
    std::cout << "Enqueue 40: " << q->enQueue(40) << std::endl;  // True
    std::cout << "Enqueue 50: " << q->enQueue(50) << std::endl;  // True
    std::cout << "Enqueue 60 (Queue is Full): " << q->enQueue(60) << std::endl;  // False (Queue is Full)

    // Get front and rear elements
    std::cout << "Front element: " << q->Front() << std::endl;  // 10
    std::cout << "Rear element: " << q->Rear() << std::endl;    // 50

    // Dequeue some elements
    std::cout << "Dequeue: " << q->deQueue() << std::endl;  // True
    std::cout << "Dequeue: " << q->deQueue() << std::endl;  // True

    // Get front and rear elements after dequeuing
    std::cout << "Front element after dequeuing: " << q->Front() << std::endl;  // 30
    std::cout << "Rear element: " << q->Rear() << std::endl;    // 50

    // Enqueue more elements after dequeuing
    std::cout << "Enqueue 60: " << q->enQueue(60) << std::endl;  // True
    std::cout << "Enqueue 70: " << q->enQueue(70) << std::endl;  // True

    // Check if the queue is full
    std::cout << "Is queue full? " << q->isFull() << std::endl;  // True

    // Get front and rear elements again
    std::cout << "Front element: " << q->Front() << std::endl;  // 30
    std::cout << "Rear element: " << q->Rear() << std::endl;    // 70

    // Clean up memory
    delete q;

    return 0;
}
