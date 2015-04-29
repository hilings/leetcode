#   019
#   Remove Nth Node From End of List
#   2015-04-28
#####################################################
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} n
    # @return {ListNode}
    def removeNthFromEnd(self, head, n):
        q = head
        for i in range(0, n):
            q = q.next
        if q is None:
            return head.next
        p = head
        while q.next:
            p = p.next
            q = q.next
        p.next = p.next.next
        return head

def printList(head):
    while head.next:
        print head.val, '->', 
        head = head.next
    print head.val
    return 0

#####################################################

a1 = ListNode(1)
a2 = ListNode(2)
a3 = ListNode(3)
a4 = ListNode(4)
a5 = ListNode(5)
a1.next = a2
a2.next = a3
a3.next = a4
a4.next = a5

n = 5

printList(a1)
sol = Solution()

printList(sol.removeNthFromEnd(a1, n))

