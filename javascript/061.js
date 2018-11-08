//  061
//  Rotate List
//  2015-12-16
/////////////////////////////////////////////////////
/**
 * Definition for singly-linked list.
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
    if (!head)
        return null;

    var tail = head, newtail = head, length = 1;
    while (tail.next) {
        length++;
        tail = tail.next;
    }
    tail.next = head
    
    k = length-1-k%length;
    for (var i = 0; i < k; i++) {
        newtail = newtail.next;
    }
    newhead = newtail.next;
    newtail.next = null;

    return newhead;
};

/////////////////////////////////////////////////////

var a1 = new ListNode(1);
var a2 = new ListNode(2);
var a3 = new ListNode(3);
var a4 = new ListNode(4);
var a5 = new ListNode(5);
a1.next = a2;
a2.next = a3;
a3.next = a4;
a4.next = a5;

var k = 2;
var r = rotateRight(a1, k);
while (r) {
    console.log(r.val);
    r = r.next;
}

