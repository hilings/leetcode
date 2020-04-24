//
//  024.c
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

void printList(struct ListNode *l) {
    while (l) {
        printf("%d -> ", l->val);
        l = l->next;
    }
    printf("(null)\n");
}

struct ListNode* swapPairs(struct ListNode* head) {
    printList(head);
    
    struct ListNode *h = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = h;
    while (head && head->next) {
        struct ListNode *q = head->next;
        
        p->next = q;
        head->next = q->next;
        q->next = head;
        
        p = head;
        head = head->next;
    }
    p->next = head;
    printList(h->next);
    return h->next;
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 024 Swap Nodes in Pairs, C ...\n\n");
    
    struct ListNode *a1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    a1->val = 1;
    a2->val = 2;
    a3->val = 3;
    a4->val = 4;
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    
    swapPairs(a1);
    
    return 0;
}