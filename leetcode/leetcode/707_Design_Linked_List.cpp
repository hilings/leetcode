//
//  707_Design_Linked_List.cpp
//  leetcode
//
//  Created by Hang Zhang on 6/2/19.
//  Copyright © 2019 Hilings Studio. All rights reserved.
//

#include <iostream>
//#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
    int size;
    ListNode* head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = new ListNode(0);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* prev = locate(index);
        if (size == 0 || !prev || index == size) {
            return -1;
        }
        print();
        return prev->next->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0) {
            index = 0;
        }
        ListNode* prev = locate(index);
        if (!prev) {
            return;
        }
        ListNode* cur = new ListNode(val);
        cur->next = prev->next;
        prev->next = cur;
        size++;
        print();
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* prev = locate(index);
        if (!prev || index == size) {
            return;
        }
        prev->next = prev->next->next;
        size--;
        print();
    }

    // locate the prev pointer of index-th node
    ListNode* locate(int index) {
        if (index < 0 || index > size) {
            return NULL;
        }
        ListNode* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        return prev;
    }

    void print() {
        for (ListNode* p = head->next; p; p = p->next) {
            cout << p->val << " -> ";
        }
        cout << "NULL\n";
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 707. Design Linked List, C++ ...\n\n";

    MyLinkedList linkedList = MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
    cout << linkedList.get(1) << '\n';            // returns 2
    linkedList.deleteAtIndex(1);  // now the linked list is 1->3
    cout << linkedList.get(1) << '\n';            // returns 3

    return 0;
}
