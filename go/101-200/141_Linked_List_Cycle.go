package main

// ListNode Definition for singly-linked list.
// type ListNode struct {
// 	Val  int
// 	Next *ListNode
// }

func hasCycle(head *ListNode) bool {
	fast, slow := head, head
	for fast != nil && slow != nil {
		fast, slow = fast.Next, slow.Next
		if fast == nil {
			return false
		}
		fast = fast.Next
		if fast == slow {
			return true
		}
	}
	return false
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

// func main() {
// 	fmt.Printf("LeetCode 141. Linked List Cycle ...\n\n")

// 	type args struct {
// 		head *ListNode
// 	}

// 	h1 := buildList([]int{3, 2, 0, -4})
// 	h1.Next.Next.Next.Next = h1.Next

// 	h2 := buildList([]int{1, 2})
// 	h2.Next = h2

// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				head: h1,
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				head: h2,
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				head: &ListNode{
// 					Val: 1,
// 				},
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := hasCycle(tt.args.head)
// 		fmt.Println(r)
// 	}
// }
