#   061
#   Rotate List
#   2015-12-16
#####################################################
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return None
        tail, newtail, length = head, head, 1
        while tail.next:
            length += 1
            tail = tail.next
        tail.next = head

        k = length-1-k%length
        for i in range(k):
            newtail = newtail.next
        newhead = newtail.next
        newtail.next = None
        
        return newhead

#####################################################
sol = Solution()

a1 = ListNode(1)
a2 = ListNode(2)
a3 = ListNode(3)
a4 = ListNode(4)
a5 = ListNode(5)
a1.next = a2
a2.next = a3
a3.next = a4
a4.next = a5

k = 2

r = sol.rotateRight(a1, k)
while r:
    print(r.val, end='->')
    r = r.next

print()

