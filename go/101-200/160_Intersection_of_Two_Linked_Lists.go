package main

import "fmt"

// ListNode ...
type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	pa, pb := headA, headB
	for pa != pb {
		if pa != nil {
			pa = pa.Next
		} else {
			pa = headB
		}
		if pb != nil {
			pb = pb.Next
		} else {
			pb = headA
		}
	}
	return pa // if no intersection, both pointers meet at nil in the end
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

// func main() {
// 	fmt.Printf("LeetCode 160. Intersection of Two Linked Lists ...\n\n")

// 	type args struct {
// 		headA *ListNode
// 		headB *ListNode
// 	}

// 	ha := buildList([]int{11, 12})
// 	hb := buildList([]int{21, 22, 23})
// 	hc := buildList([]int{31, 32, 33})
// 	ha.Next.Next = hc
// 	hb.Next.Next.Next = hc

// 	h1 := buildList([]int{2, 6, 4})
// 	h2 := buildList([]int{1, 5})

// 	tests := []struct {
// 		args args
// 		want *ListNode
// 	}{
// 		{
// 			args: args{
// 				headA: ha,
// 				headB: hb,
// 			},
// 			want: nil,
// 		},
// 		{
// 			args: args{
// 				headA: h1,
// 				headB: h2,
// 			},
// 			want: nil,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := getIntersectionNode(tt.args.headA, tt.args.headB)
// 		fmt.Println(r)
// 	}
// }
