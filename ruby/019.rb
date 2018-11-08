# 019
# Remove Nth Node From End of List
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

# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end(head, n)
  q = head
  for i in 0...n
    q = q.next
  end
  if not q
    return head.next
  end
  p = head
  while q.next
    p = p.next
    q = q.next
  end
  p.next = p.next.next
  head
end

def printList(head)
  while head.next do
    print head.val, ' -> '
    head = head.next
  end
  puts head.val
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

n = 5

printList(a1)
printList(remove_nth_from_end(a1, n))

