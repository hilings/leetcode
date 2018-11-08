#   023
#   Merge k Sorted Lists
#   2015-04-30
#####################################################
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        h = ListNode(0)
        p = h
        while l1 and l2:
            if l1.val < l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next
        p.next = l1 if l1 else l2
        #printList(h.next)
        return h.next

    # @param {ListNode[]} lists
    # @return {ListNode}
    def mergeKLists(self, lists):
        if not lists:
            return None
        while len(lists) > 1:
            size = len(lists)
            for i in range(0, size//2):
                lists[i] = self.mergeTwoLists(lists[i], lists[size-1-i])
                lists.pop()
        return lists[0]

def printList(l):
    while l:
        print(l.val, end="->")
        l = l.next
    print("(null)")

def printVector(v):
    for l in v:
        printList(l)

#####################################################

a1 = ListNode(1)
a2 = ListNode(4)
a3 = ListNode(7)
b1 = ListNode(2)
b2 = ListNode(5)
b3 = ListNode(8)
c1 = ListNode(3)
c2 = ListNode(6)
c3 = ListNode(9)
a1.next = a2
a2.next = a3
b1.next = b2
b2.next = b3
c1.next = c2
c2.next = c3

v = [a1,b1,c1]
printVector(v)
sol = Solution()
#sol.mergeTwoLists(a1, b1)
z = sol.mergeKLists(v)
printList(z)

