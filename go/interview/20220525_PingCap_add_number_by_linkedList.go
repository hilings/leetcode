package main

import "fmt"

// TreeNode ...
// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

// func height(root *TreeNode) int {
// 	if root == nil {
// 		return 0
// 	}
// 	return 1 + max(height(root.Left), height(root.Right))
// }

// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }

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

func addByList(l1, l2 *ListNode) *ListNode {
	stk1, stk2 := []int{}, []int{}
	for p := l1; p != nil; p = p.Next {
		stk1 = append(stk1, p.Val)
	}
	for p := l2; p != nil; p = p.Next {
		stk2 = append(stk2, p.Val)
	}

	carry := 0
	var head *ListNode
	for i, j := len(stk1)-1, len(stk2)-1; i >= 0 || j >= 0; {
		a, b := 0, 0
		if i >= 0 {
			a = stk1[i]
		}
		if j >= 0 {
			b = stk2[j]
		}
		c := a + b + carry
		node := &ListNode{
			Val:  c % 10,
			Next: head,
		}
		head = node
		carry = c / 10
		i--
		j--
	}

	return head
}

// func main() {
// 	fmt.Printf("Interview, PingCap R1, add number by LinkedList ...\n\n")

// 	// 两数相加
// 	// 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// 	// 输出: (7 -> 8 -> 0 -> 7)

// 	type args struct {
// 		l1 *ListNode
// 		l2 *ListNode
// 	}
// 	tests := []struct {
// 		args args
// 		want *ListNode
// 	}{
// 		{
// 			args: args{
// 				l1: buildList([]int{7, 2, 4, 3}),
// 				l2: buildList([]int{5, 6, 4}),
// 			},
// 			want: nil,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := addByList(tt.args.l1, tt.args.l2)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 		printList(r)
// 	}
// }
