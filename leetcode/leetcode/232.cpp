//
//  232.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/12/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> stk;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> buffer;
        while (!stk.empty()) {
            buffer.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while (!buffer.empty()) {
            stk.push(buffer.top());
            buffer.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stk.pop();
    }

    // Get the front element.
    int peek(void) {
        return stk.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 232. Implement Queue using Stacks, C++ ...\n\n";

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << '\n';
    q.pop();
    cout << q.peek() << '\n';
    cout << (q.empty() ? "true" : "false") << '\n';
    q.pop();
    cout << q.peek() << '\n';
    cout << (q.empty() ? "true" : "false") << '\n';
    q.pop();
    cout << (q.empty() ? "true" : "false") << '\n';
    
    return 0;
}