//
//  641_Design_Circular_Deque.cpp
//  leetcode
//
//  Created by Hang Zhang on 10/24/18.
//  Copyright © 2018 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
    vector<int> q;
    int size, begin, end;   // begin inclusive, end non-inclusive
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k+1;
        q = vector<int> (size, 0);
        begin = 0;
        end = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        begin = (begin-1+size) % size;
        q[begin] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        q[end] = value;
        end = (end+1) % size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        begin = (begin+1) % size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        end = (end-1+size) % size;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : q[begin];
    }

    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : q[(end-1+size) % size];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return begin == end;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (end+1) % size == begin;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 641. Design Circular Deque, C++ ...\n\n";

    int k = 3;
    MyCircularDeque circularDeque(k); // set the size to be 3

    bool rb = circularDeque.insertLast(1);            // return true
    cout << (rb ? "true" : "false") << '\n';

    rb = circularDeque.insertLast(2);            // return true
    cout << (rb ? "true" : "false") << '\n';

    rb = circularDeque.insertFront(3);            // return true
    cout << (rb ? "true" : "false") << '\n';

    rb = circularDeque.insertFront(4);            // return false, the queue is full
    cout << (rb ? "true" : "false") << '\n';

    int ri = circularDeque.getRear();              // return 2
    cout << ri << '\n';

    rb = circularDeque.isFull();                // return true
    cout << (rb ? "true" : "false") << '\n';

    rb = circularDeque.deleteLast();            // return true
    cout << (rb ? "true" : "false") << '\n';

    rb = circularDeque.insertFront(4);            // return true
    cout << (rb ? "true" : "false") << '\n';

    ri = circularDeque.getFront();            // return 4
    cout << ri << '\n';

    return 0;
}
