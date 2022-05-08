package main

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func numComponents(head *ListNode, nums []int) int {
	m := map[int]bool{}
	for _, a := range nums {
		m[a] = true
	}

	r := 0
	for ; head != nil; head = head.Next {
		if !m[head.Val] {
			continue
		}
		if head.Next != nil && m[head.Next.Val] {
			continue
		}
		r++
	}

	return r
}

func numComponents0(head *ListNode, nums []int) int {
	m := map[int]map[int]bool{
		head.Val: {},
	}
	for ; head != nil; head = head.Next {
		next := head.Next
		if next != nil {
			m[head.Val][next.Val] = true
			m[next.Val] = map[int]bool{
				head.Val: true,
			}
		}
	}
	// fmt.Println(m)

	mNums := map[int]bool{}
	for _, a := range nums {
		mNums[a] = true
	}

	visited := make(map[int]bool)

	r := 0
	for _, a := range nums { // traverse nums
		if visited[a] == true {
			continue
		}

		r++
		q := []int{a}
		visited[a] = true
		for j := 0; j < len(q); j++ { //dfs
			for k := range m[q[j]] {
				if mNums[k] && !visited[k] {
					q = append(q, k)
					visited[k] = true
				}
			}
		}
		// fmt.Printf("\tq = %v\n", q)
	}

	return r
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
// 	fmt.Printf("LeetCode 817. Linked List Components ...\n\n")

// 	type args struct {
// 		head *ListNode
// 		nums []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				head: buildList([]int{0, 1, 2, 3}),
// 				nums: []int{0, 1, 3},
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				head: buildList([]int{0, 1, 2, 3, 4}),
// 				nums: []int{0, 3, 1, 4},
// 			},
// 			want: 2,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := numComponents(tt.args.head, tt.args.nums)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
