//
//  061.c
//  leetcode
//
//  Created by Hang Zhang on 12/16/15.
//  Copyright © 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head)
        return NULL;

    struct ListNode *tail = head;
    int length = 1;
    while (tail->next) {
        length++;
        tail = tail->next;
    }
    tail->next = head;

    struct ListNode *newtail = head;
    k = length-1-k%length;
    for (int i = 0; i < k; i++) {
        newtail = newtail->next;
    }
    struct ListNode *newhead = newtail->next;
    newtail->next = NULL;

    return newhead;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 061 Rotate List, C ...\n\n");

    struct ListNode a5 = {5};
    struct ListNode a4 = {4, &a5};
    struct ListNode a3 = {3, &a4};
    struct ListNode a2 = {2, &a3};
    struct ListNode a1 = {1, &a2};

    int k = 2;
    struct ListNode *head = rotateRight(&a1, k);

    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }


    return 0;
}