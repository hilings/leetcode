# 024
# Swap Nodes in Pairs
# 2015-04-30
#####################################################
# Definition for singly-linked list.
class ListNode
  attr_accessor :val, :next
  def initialize(val)
    @val = val
    @next = nil
  end
end

# @param {ListNode} head
# @return {ListNode}
def swap_pairs(head)
  printList(head)
  h = ListNode.new(0)
  p = h
  while head and head.next
    q = head.next
    p.next = q
    head.next = q.next
    q.next = head
    p = head
    head = head.next
  end
  p.next = head
  printList(h.next)
  h.next
end

def printList(l)
  while l
    print l.val, ' -> '
    l = l.next
  end
  puts "(null)"
end

#####################################################

a1 = ListNode.new(1)
a2 = ListNode.new(2)
a3 = ListNode.new(3)
a4 = ListNode.new(4)
a1.next = a2
a2.next = a3
a3.next = a4

swap_pairs(a1)

