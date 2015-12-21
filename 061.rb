# 061
# Rotate List
# 2015-12-16
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
def rotate_right(head, k)
  return nil if not head
  
  tail, newtail, length = head, head, 1
  while tail.next
    length += 1
    tail = tail.next
  end
  tail.next = head

  k = length-1-k%length
  k.times { newtail = newtail.next }
  newhead = newtail.next
  newtail.next = nil
  
  newhead
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

r = rotate_right(a1, k)
while r
  print r.val,' -> '
  r = r.next
end

