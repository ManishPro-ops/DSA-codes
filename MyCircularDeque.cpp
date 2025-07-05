#include <iostream>


class MyCircularDeque {
public:
    int size;
    int* arr;
    int front;
    int rear;
    MyCircularDeque(int k) {
        this->size = k;
        arr = new int[k];
        this->rear = -1;
        this->front = -1;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0 && rear != size - 1) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (front == 0 && rear == size - 1 || (rear + 1) % size == front) {
            return true;
        }
        return false;
    }
};




int main() {
    // Create a circular deque of size 5
    MyCircularDeque* dq = new MyCircularDeque(5);

    // Insert elements at the rear
    std::cout << "Insert 10 at rear: " << dq->insertLast(10) << std::endl;  // True
    std::cout << "Insert 20 at rear: " << dq->insertLast(20) << std::endl;  // True
    std::cout << "Insert 30 at rear: " << dq->insertLast(30) << std::endl;  // True
    std::cout << "Insert 40 at rear: " << dq->insertLast(40) << std::endl;  // True

    // Insert element at the front
    std::cout << "Insert 5 at front: " << dq->insertFront(5) << std::endl;  // True

    // Check if the deque is full
    std::cout << "Is deque full? " << dq->isFull() << std::endl;  // True

    // Attempt to insert when deque is full
    std::cout << "Insert 50 at front (Deque is Full): " << dq->insertFront(50) << std::endl;  // False

    // Get front and rear elements
    std::cout << "Front element: " << dq->getFront() << std::endl;  // 5
    std::cout << "Rear element: " << dq->getRear() << std::endl;    // 40

    // Delete elements from the front
    std::cout << "Delete from front: " << dq->deleteFront() << std::endl;  // True
    std::cout << "Delete from front: " << dq->deleteFront() << std::endl;  // True

    // Get front and rear elements after deletion
    std::cout << "Front element after deletion: " << dq->getFront() << std::endl;  // 20
    std::cout << "Rear element: " << dq->getRear() << std::endl;                   // 40

    // Insert at the rear and front
    std::cout << "Insert 50 at rear: " << dq->insertLast(50) << std::endl;  // True
    std::cout << "Insert 60 at front: " << dq->insertFront(60) << std::endl;  // True

    // Get front and rear elements again
    std::cout << "Front element: " << dq->getFront() << std::endl;  // 60
    std::cout << "Rear element: " << dq->getRear() << std::endl;    // 50

    // Check if deque is full
    std::cout << "Is deque full? " << dq->isFull() << std::endl;  // True

    // Clean up memory
    delete dq;

    return 0;
}
