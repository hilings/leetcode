#   002
#   Add Two Numbers
#####################################################
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def printList(l):
    while l:
        print l.val,
        l = l.next
    print


class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        head = ListNode(0)
        prev = None
        carry = 0
        while l1 or l2:
            if prev is None:
                cur = head
            else:
                cur = ListNode(0)

            sum = carry
            if l1:
                sum += l1.val
            if l2:
                sum += l2.val
            cur.val = sum % 10
            carry = sum / 10

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            if prev:
                prev.next = cur
            prev = cur

        if carry > 0:
            prev.next = ListNode(1)
        return head

#####################################################

a1 = ListNode(2)
a2 = ListNode(4)
a3 = ListNode(3)
a4 = ListNode(3)

b1 = ListNode(5)
b2 = ListNode(6)
b3 = ListNode(4)

a1.next = a2
a2.next = a3
a3.next = a4
b1.next = b2
b2.next = b3


printList(a1)
printList(b1)

sol = Solution()
printList(sol.addTwoNumbers(a1, b1))

