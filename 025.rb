# 025
# Reverse Nodes in k-Group
# 2015-05-02
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
# @param {Integer} k
# @return {ListNode}
def reverse_k_group(head, k)
  printList(head)
  return head if k == 1

  first = ListNode.new(0)
  first.next = head

  p0 = first
  p1 = head
  while true
    q = p1
    (1...k).each do
      break if not q
      q = q.next
    end
    break if not q

    h = p1
    p2 = p1.next
    while p2 != q
      t = p2.next
      p2.next = p1
      p1 = p2
      p2 = t
    end
    h.next = q.next
    q.next = p1
    p0.next = q

    p0 = h
    p1 = h.next
    h = p1
    q = p1
  end

  printList(first.next)
  first.next
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
a5 = ListNode.new(5)
a1.next = a2
a2.next = a3
a3.next = a4
a4.next = a5

k = 2

reverse_k_group(a1, k)

