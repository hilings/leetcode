package main

import "fmt"

// ListNode ...
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	for cur := head; cur != nil; {
		next := cur.Next
		cur.Next = prev
		prev = cur
		cur = next
	}
	return prev
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
// 	fmt.Printf("LeetCode 206. Reverse Linked List ...\n\n")

// 	type args struct {
// 		head *ListNode
// 	}
// 	tests := []struct {
// 		args args
// 		want *ListNode
// 	}{
// 		{
// 			args: args{
// 				head: buildList([]int{1, 2, 3, 4, 5}),
// 			},
// 			want: nil,
// 		},
// 		{
// 			args: args{
// 				head: buildList([]int{1, 2}),
// 			},
// 			want: nil,
// 		},
// 		{
// 			args: args{
// 				head: buildList([]int{}),
// 			},
// 			want: nil,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := reverseList(tt.args.head)
// 		printList(r)
// 	}
// }
