# 002
# Add Two Numbers
#####################################################
# Definition for singly-linked list.
class ListNode
  attr_accessor :val, :next
  def initialize(val)
    @val = val
    @next = nil
  end
end


def printList(l)
  while l do
    print "#{l.val} "
    l = l.next
  end
  puts
end


# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def add_two_numbers(l1, l2)
  head = ListNode.new(0)
  prev = nil
  carry = 0
  while l1 or l2
    cur = if prev.nil? then head else ListNode.new(0) end

    sum = carry
    sum += l1.val if not l1.nil?
    sum += l2.val if not l2.nil?
    cur.val = sum % 10
    carry = sum / 10

    l1 = l1.next if not l1.nil?
    l2 = l2.next if not l2.nil?
    prev.next = cur if not prev.nil?
    prev = cur
  end

  prev.next = ListNode.new(1) if carry > 0

  head
end

#####################################################

a1 = ListNode.new(1)
a2 = ListNode.new(4)
a3 = ListNode.new(3)
a4 = ListNode.new(3)

b1 = ListNode.new(5)
b2 = ListNode.new(6)
b3 = ListNode.new(4)


#a1.next = a2
#a2.next = a3
#a3.next = a4
b1.next = b2
b2.next = b3

printList(a1)
printList(b1)

printList(add_two_numbers(a1, b1))

