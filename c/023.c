//
//  023.c
//  leetcode
//
//  Created by Hang Zhang on 4/30/15.
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

void printList(struct ListNode *h) {
    while (h) {
        printf("%d -> ", h->val);
        h = h->next;
    }
    printf(" (null)\n");
}

void printVector(struct ListNode **v, int n) {
    for (int i = 0; i < n; i++) {
        printList(v[i]);
    }
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return head->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *h = NULL;
    if (listsSize == 0)
        return h;
    
    while (listsSize > 1) {
        int size = listsSize;
        for (int i = 0; i < size-1-i; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[size-1-i]);
            listsSize--;
        }
    }
    printList(lists[0]);
    return lists[0];
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 023 Merge k Sorted Lists, C ...\n");
    
    struct ListNode *a1 = 0;//(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *b1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *b2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *b3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *c1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *c2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *c3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    //a1->val = 1;
    a2->val = 4;
    a3->val = 7;
    b1->val = 2;
    b2->val = 5;
    b3->val = 8;
    c1->val = 3;
    c2->val = 6;
    c3->val = 9;
    //a1->next = a2;
    a2->next = a3;
    b1->next = b2;
    b2->next = b3;
    c1->next = c2;
    c2->next = c3;
    
    //printList(a1);
    //printList(mergeTwoLists(a1, b1));
    
    int n = 3;
    struct ListNode **lists = (struct ListNode**)malloc(sizeof(struct ListNode*) * n);
    lists[0] = a1;
    lists[1] = b1;
    lists[2] = c1;
    printVector(lists, n);
    mergeKLists(lists, n);
    
    
    return 0;
}