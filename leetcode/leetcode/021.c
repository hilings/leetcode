//
//  021.c
//  leetcode
//
//  Created by Hang Zhang on 4/28/15.
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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    struct ListNode *head;
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
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
    if (l1)
        p->next = l1;
    else
        p->next = l2;
    return head;
}

void printList(struct ListNode *head) {
    if (!head)
        return;
    while (head->next) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("%d\n", head->val);
    
}

int main(int arg, char *argv[]) {
    // insert code here...
    printf("LeetCode 021 Merge Two Sorted Lists, C ... ...\n");
    
    struct ListNode *a1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *b1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *b2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *b3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    a1->val = 1;
    a2->val = 3;
    a3->val = 5;
    b1->val = 2;
    b2->val = 4;
    b3->val = 6;
    a1->next = a2;
    a2->next = a3;
    b1->next = b2;
    b2->next = b3;

    printList(a1);
    printList(b1);
    
    printList(mergeTwoLists(a1, b1));
    
    return 0;
}