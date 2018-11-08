#   024
#   Swap Nodes in Pairs
#   2015-04-30
#####################################################
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def swapPairs(self, head):
        printList(head)
        h = ListNode(0)
        p = h
        while head and head.next:
            q = head.next
            p.next = q
            head.next = q.next
            q.next = head
            p = head
            head = head.next
        p.next = head
        printList(h.next)
        return h.next

def printList(l):
    while l:
        print(l.val, end="->")
        l = l.next
    print("(null)")

#####################################################

a1 = ListNode(1)
a2 = ListNode(2)
a3 = ListNode(3)
a4 = ListNode(4)
a1.next = a2
a2.next = a3
a3.next = a4

sol = Solution()
sol.swapPairs(a1)

