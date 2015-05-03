# 023
# Merge k Sorted Lists
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

def merge_two_lists(l1, l2)
  h = ListNode.new(0)
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
  p.next = l1 ? l1 : l2
  #printList(h.next)
  h.next
end

# @param {ListNode[]} lists
# @return {ListNode}
def merge_k_lists(lists)
  printVector(lists)
  while lists.size > 1
    size = lists.size
    for i in 0...size/2
      lists[i] = merge_two_lists(lists[i], lists[size-1-i])
      lists.pop()
    end
  end
  printList(lists.first)
  lists.first
end

def printList(l)
  while l
    print l.val, " -> "
    l = l.next
  end
  puts "(null)"
end

def printVector(v)
  for i in 0...v.size
    printList(v[i])
  end
end
#####################################################

a1 = ListNode.new(1)
a2 = ListNode.new(4)
a3 = ListNode.new(7)
b1 = ListNode.new(2)
b2 = ListNode.new(5)
b3 = ListNode.new(8)
c1 = ListNode.new(3)
c2 = ListNode.new(6)
c3 = ListNode.new(9)
a1.next = a2
a2.next = a3
b1.next = b2
b2.next = b3
c1.next = c2
c2.next = c3

v = [a1, b1, c1]
#merge_two_lists(a1, b1)
merge_k_lists(v)

