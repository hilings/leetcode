//
//  341.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    stack<vector<NestedInteger>::iterator> begins, ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (!begins.empty()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else if (begins.top()->isInteger()) {
                return true;
            } else {
                vector<NestedInteger>::iterator p = begins.top();
                begins.top()++;
                begins.push(p->getList().begin());
                ends.push(p->getList().end());
            }
        }
        return false;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 341. Flatten Nested List Iterator, C++ ...\n\n";
    
    NestedInteger nestedList;
    
    /**
     * Your NestedIterator object will be instantiated and called as such:
     */
    NestedIterator i(nestedList);
    while (i.hasNext()) cout << i.next();
    
    
    return 0;
}