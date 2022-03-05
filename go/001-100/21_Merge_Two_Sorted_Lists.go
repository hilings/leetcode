package main

// ListNode ...
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	head := &ListNode{}
	prev := head
	for list1 != nil && list2 != nil {
		if list1.Val < list2.Val {
			prev.Next = list1
			prev = prev.Next
			list1 = list1.Next
			continue
		}
		prev.Next = list2
		prev = prev.Next
		list2 = list2.Next
	}

	if list1 != nil {
		prev.Next = list1
	} else {
		prev.Next = list2
	}

	return head.Next
}

// func buildList(l []int) *ListNode {
// 	origin := &ListNode{}
// 	cur := origin
// 	for _, val := range l {
// 		node := &ListNode{
// 			Val: val,
// 		}
// 		cur.Next = node
// 		cur = cur.Next
// 	}

// 	cur = origin.Next
// 	for cur != nil {
// 		fmt.Printf("%d -> ", cur.Val)
// 		cur = cur.Next
// 	}
// 	fmt.Printf("null\n")

// 	return origin.Next
// }

// func printList(head *ListNode) {
// 	for cur := head; cur != nil; cur = cur.Next {
// 		fmt.Printf("%d -> ", cur.Val)
// 	}
// 	fmt.Printf("null\n")
// }

// func main() {
// 	fmt.Printf("LeetCode 21. Merge Two Sorted Lists ...\n\n")

// 	type args struct {
// 		list1 *ListNode
// 		list2 *ListNode
// 	}
// 	tests := []struct {
// 		args args
// 		want *ListNode
// 	}{
// 		{
// 			args: args{
// 				list1: buildList([]int{1, 3, 5}),
// 				list2: buildList([]int{2, 4, 6, 7}),
// 			},
// 			want: nil,
// 		},
// 		{
// 			args: args{
// 				list1: buildList([]int{}),
// 				list2: buildList([]int{0}),
// 			},
// 			want: nil,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := mergeTwoLists(tt.args.list1, tt.args.list2)
// 		printList(r)
// 	}
// }
