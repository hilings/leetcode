//
//  155.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/3/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> stk;
    stack<int> minstk;
public:
    void push(int x) {
        stk.push(x);
        if (minstk.empty() || x <= minstk.top())
            minstk.push(x);
    }
    void pop() {
        if (stk.empty())
            return;
        if (stk.top() == minstk.top())
            minstk.pop();
        stk.pop();
    }
    int top() {
        return stk.top();
    }
    int getMin() {
        return minstk.top();
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 155. Min Stack, C++ ...\n\n";
    MinStack sol;
    
    return 0;
}