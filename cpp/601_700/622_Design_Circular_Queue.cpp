//
//  622_Design_Circular_Queue.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/21/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
    vector<int> q;
    int size, front, back;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k+1;
        q = vector<int> (size, 0);
        front = 0;
        back = 0;
        printf("k = %d, queue size = %d\n", k, size);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        q[back] = value;
        back = (back+1) % size;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front+1) % size;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return q[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return q[(back-1+size) % size];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == back;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (back+1) % size == front;
    }

    void print() {
        for (int i = front; i != back; i=(i+1)%size) {
            cout << q[i] << ' ';
        }
        printf(", front = %d, back = %d\n\n", front, back);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 622. Design Circular Queue, C++ ...\n\n";

    int k = 3;
    MyCircularQueue circularQueue(k);    // set the size to be 3

    bool r = circularQueue.enQueue(1);  // return true
    printf("enQueue = %s\n", r ? "true" : "false");
    circularQueue.print();

    r = circularQueue.enQueue(2);  // return true
    printf("enQueue = %s\n", r ? "true" : "false");
    circularQueue.print();

    r = circularQueue.enQueue(3);  // return true
    printf("enQueue = %s\n", r ? "true" : "false");
    circularQueue.print();

    r = circularQueue.enQueue(4);  // return false, the queue is full
    printf("enQueue = %s\n", r ? "true" : "false");
    circularQueue.print();

    int r2 = circularQueue.Rear();  // return 3
    printf("rear = %d\n", r2);
    circularQueue.print();

    r = circularQueue.isFull();  // return true
    printf("isFull = %s\n", r ? "true" : "false");
    circularQueue.print();

    r = circularQueue.deQueue();  // return true
    printf("deQueue = %s\n", r ? "true" : "false");
    circularQueue.print();

    r = circularQueue.enQueue(4);  // return true
    printf("enQueue = %s\n", r ? "true" : "false");
    circularQueue.print();

    r2 = circularQueue.Rear();  // return 4
    printf("rear = %d\n", r2);
    circularQueue.print();

    return 0;
}
