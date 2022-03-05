package linkedlist

import "fmt"

// ListNode ...
type ListNode struct {
	Val  int
	Next *ListNode
}

func buildList(l []int) *ListNode {
	origin := &ListNode{}
	cur := origin
	for _, val := range l {
		node := &ListNode{
			Val: val,
		}
		cur.Next = node
		cur = cur.Next
	}

	cur = origin.Next
	for cur != nil {
		fmt.Printf("%d -> ", cur.Val)
		cur = cur.Next
	}
	fmt.Printf("null\n")

	return origin.Next
}

func printList(head *ListNode) {
	for cur := head; cur != nil; cur = cur.Next {
		fmt.Printf("%d -> ", cur.Val)
	}
	fmt.Printf("null\n")
}
