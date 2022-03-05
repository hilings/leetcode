package main

import (
	"fmt"
)

// ListNode ...
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	prevLeft := head
	for i := 0; i < left-2; i++ {
		prevLeft = prevLeft.Next
	}
	pLeft := prevLeft.Next
	if left == 1 {
		pLeft = head
		prevLeft = nil
	}
	fmt.Printf("pLeft = %v\n", pLeft)

	pRight := pLeft
	for i := left; i < right; i++ {
		pRight = pRight.Next
	}
	fmt.Printf("pRight = %v\n", pRight)
	pRest := pRight.Next
	fmt.Printf("pRest = %v\n", pRest)

	prev := pRest
	for cur := pLeft; cur != pRest; {
		next := cur.Next
		cur.Next = prev
		prev = cur
		cur = next
	}
	if left == 1 {
		return prev
	}
	prevLeft.Next = prev
	return head
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

// func main() {
// 	fmt.Printf("LeetCode 92. Reverse Linked List II ...\n\n")

// 	type args struct {
// 		head  *ListNode
// 		left  int
// 		right int
// 	}
// 	tests := []struct {
// 		args args
// 		want *ListNode
// 	}{
// 		{
// 			args: args{
// 				head:  buildList([]int{1, 2, 3, 4, 5}),
// 				left:  2,
// 				right: 4,
// 			},
// 			want: nil,
// 		},
// 		{
// 			args: args{
// 				head:  buildList([]int{5}),
// 				left:  1,
// 				right: 1,
// 			},
// 			want: nil,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := reverseBetween(tt.args.head, tt.args.left, tt.args.right)
// 		printList(r)
// 	}
// }
