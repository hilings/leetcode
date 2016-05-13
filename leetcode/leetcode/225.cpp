//
//  225.cpp
//  leetcode
//
//  Created by Hang Zhang on 5/10/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

class Stack {
    deque<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        int n = (int)q.size();
        q.push_back(x);
        for (int i = 0; i < n; i++) {
            q.push_back(q.front());
            q.pop_front();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop_front();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 225. Implement Stack using Queues, C++ ...\n\n";
    Stack stk;

    stk.push(1);
    stk.push(2);
    cout << stk.top();
    stk.pop();
    cout << stk.top();
    cout << (stk.empty() ? "true" : "false") << '\n';
    stk.pop();
    cout << (stk.empty() ? "true" : "false") << '\n';

    return 0;
}