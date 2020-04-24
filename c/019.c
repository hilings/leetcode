//
//  019.c
//  leetcode
//
//  Created by Hang Zhang on 4/28/15.
//  Copyright (c) 2015 Hilings Studio. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *q = head;
    for (int i = 0; i < n; i++)
        q = q->next;
    if (!q)
        return head->next;
    struct ListNode *p = head;
    while(q->next) {
        p = p->next;
        q = q->next;
    }
    p->next = p->next->next;
    return head;
}

void printList(struct ListNode* head) {
    while(head->next) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("%d\n", head->val);
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 019 Remove Nth Node From End of List, C ... ...\n");
    
    struct ListNode *a1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    a1->val = 1;
    a2->val = 2;
    a3->val = 3;
    a4->val = 4;
    a5->val = 5;
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    
    int n = 5;
    
    printList(a1);
    printList(removeNthFromEnd(a1, n));
    
    return 0;
}