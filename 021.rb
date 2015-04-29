# 021
# Merge Two Sorted Lists
# 2015-04-28
#####################################################
# Definition for singly-linked list.
class ListNode
  attr_accessor :val, :next
  def initialize(val)
    @val = val
    @next = nil
  end
end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def merge_two_lists(l1, l2)
  return l2 if l1.nil?
  return l1 if l2.nil?
  if l1.val < l2.val
    h = l1
    l1 = l1.next
  else
    h = l2
    l2 = l2.next
  end
  p = h
  while l1 and l2
    if l1.val < l2.val
      p.next = l1
      l1 = l1.next
    else
      p.next = l2
      l2 = l2.next
    end
    p = p.next
  end
  if l1
    p.next = l1
  else
    p.next = l2
  end
  h
end

def printList(l)
  return if l.nil?
  while l.next
    print "#{l.val} -> "
    l = l.next
  end
  puts l.val
end

#####################################################

a1 = ListNode.new(1)
a2 = ListNode.new(3)
a3 = ListNode.new(5)
b1 = ListNode.new(2)
b2 = ListNode.new(4)
b3 = ListNode.new(6)
a1.next = a2
a2.next = a3
b1.next = b2
b2.next = b3

printList(a1)
printList(b1)

printList(merge_two_lists(a1, b1))

