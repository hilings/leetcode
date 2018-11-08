#   021
#   Merge Two Sorted Lists
#   2015-04-28
#####################################################
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def mergeTwoLists(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            h = l1
            l1 = l1.next
        else:
            h = l2
            l2 = l2.next
        p = h
        while l1 and l2:
            if l1.val < l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next
        if l1:
            p.next = l1
        else:
            p.next = l2
        return h

def printList(l):
    if not l:
        return
    while l.next:
        print(l.val, end="->")
        l = l.next
    print(l.val)

#####################################################

a1 = ListNode(1) 
a2 = ListNode(3) 
a3 = ListNode(5) 
b1 = ListNode(2) 
b2 = ListNode(4) 
b3 = ListNode(6) 
a1.next = a2
a2.next = a3
b1.next = b2
b2.next = b3
printList(a1)
printList(b1)

sol = Solution()
z = sol.mergeTwoLists(a1, b1)
printList(z)

