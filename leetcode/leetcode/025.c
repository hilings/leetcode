//
//  025.c
//  leetcode
//
//  Created by Hang Zhang on 5/2/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode *l) {
    while (l) {
        printf("%d -> ", l->val);
        l = l->next;
    }
    printf("(null)\n");
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    printList(head);
    if (k == 1)
        return head;

    struct ListNode *first = (struct ListNode*)malloc(sizeof(struct ListNode));
    first->next = head;

    struct ListNode *p0 = first;
    struct ListNode *p1 = head;

    while (1) {
        struct ListNode *q = p1;
        for (int i = 1; i < k && q ; i++)
            q = q->next;

        if (!q)     // less than k item
            break;

        struct ListNode *h = p1;
        struct ListNode *p2 = p1->next;
        while (p2 != q) {
            struct ListNode *t = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = t;
        }
        h->next = q->next;
        q->next = p1;
        p0->next = q;

        p0 = h;
        p1 = h->next;
        h = p1;
        q = p1;
    }

    printList(first->next);
    return first->next;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 025 Reverse Nodes in k-Group, C ...\n\n");

    struct ListNode *a1 = 0;//(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    //a1->val = 1;
    a2->val = 2;
    a3->val = 3;
    a4->val = 4;
    a5->val = 5;
    //a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    int k = 2;

    reverseKGroup(a1, k);

    return 0;
}
