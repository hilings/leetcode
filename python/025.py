#   025
#   Reverse Nodes in k-Group
#   2015-05-02
#####################################################
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} k
    # @return {ListNode}
    def reverseKGroup(self, head, k):
        printList(head)
        if k == 1:
            return head

        first = ListNode(0)
        first.next = head

        p0 = first
        p1 = head
        while True:
            q = p1
            for i in range(1, k):
                if not q:
                    break
                q = q.next

            if not q:
                break

            h = p1
            p2 = p1.next
            while p2 != q:
                t = p2.next
                p2.next = p1
                p1 = p2
                p2 = t
            h.next = q.next
            q.next = p1
            p0.next = q
            
            p0 = h
            p1 = h.next
            h = p1
            q = p1

        printList(first.next)
        return first.next

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
a5 = ListNode(5)
a1.next = a2
a2.next = a3
a3.next = a4
a4.next = a5

k = 3

sol = Solution()
sol.reverseKGroup(a1, k)

