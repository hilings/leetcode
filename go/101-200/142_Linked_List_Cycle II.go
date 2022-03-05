package main

// ListNode ...
// type ListNode struct {
// 	Val  int
// 	Next *ListNode
// }

func detectCycle(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}

	fast, slow := head, head
	for fast != nil {
		fast, slow = fast.Next, slow.Next
		if fast == nil || fast.Next == nil {
			return nil
		}
		fast = fast.Next
		if fast == slow {
			break
		}
	}

	slow = head
	for slow != fast {
		fast, slow = fast.Next, slow.Next
	}
	return slow
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
// 	fmt.Printf("LeetCode 142. Linked List Cycle II ...\n\n")

// 	type args struct {
// 		head *ListNode
// 	}
// 	h1 := buildList([]int{3, 2, 0, -4})
// 	h1.Next.Next.Next.Next = h1.Next

// 	tests := []struct {
// 		args args
// 		want *ListNode
// 	}{
// 		{
// 			args: args{
// 				head: h1,
// 			},
// 			want: nil,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := detectCycle(tt.args.head)
// 		fmt.Println(r)
// 	}
// }
