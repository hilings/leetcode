//
//  382.cpp
//  leetcode
//
//  Created by Hang Zhang on 3/14/17.
//  Copyright © 2017 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* myhead;
public:
    /** @param head The linked list's head.
     Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        myhead = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        //cout << "getting random\n";
        ListNode* p = myhead, *r = myhead;
        int count = 1;
        while (p) {
            if (rand() % count++ == 0) {
                r = p;
            }
            p = p->next;
        }
        return r->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 382. Linked List Random Node, C++ ...\n\n";

    // Init a singly linked list [1,2,3].
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution solution(head);// = new Solution(head);

    // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
    int i = solution.getRandom();
    cout << i << '\n';
    
    for (int i = 0; i < 99; i++) {
        cout << solution.getRandom() << '\n';
    }
    
    return 0;
}
