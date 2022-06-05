package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	if k == 0 {
		return []int{target.Val}
	}

	q := []*TreeNode{root}
	mp := map[*TreeNode]*TreeNode{root: nil} // parent pointers
	for i := 0; i < len(q); i++ {            // bfs
		cur := q[i]
		if cur.Left != nil {
			mp[cur.Left] = cur
			q = append(q, cur.Left)
		}
		if cur.Right != nil {
			mp[cur.Right] = cur
			q = append(q, cur.Right)
		}
	}

	dis := map[*TreeNode]int{target: 0}
	q = []*TreeNode{target}
	r := []int{}
	for i := 0; i < len(q); i++ {
		cur := q[i]
		neighbors := []*TreeNode{
			cur.Left,
			cur.Right,
			mp[cur],
		}
		for _, nb := range neighbors {
			if nb == nil {
				continue
			}
			if _, ok := dis[nb]; ok {
				continue
			}
			q = append(q, nb)
			dis[nb] = dis[cur] + 1
			if dis[nb] == k {
				r = append(r, nb.Val)
			}
		}
	}
	return r
}

const null = -1

func buildT(nodes []int) *TreeNode {
	if len(nodes) == 0 {
		return nil
	}

	root := &TreeNode{Val: nodes[0]}
	q := []*TreeNode{root}
	for i, p := 1, 0; i < len(nodes); p++ {
		if nodes[i] != null {
			left := &TreeNode{Val: nodes[i]}
			q[p].Left = left
			q = append(q, left)
		}
		i++

		if i < len(nodes) && nodes[i] != null {
			right := &TreeNode{Val: nodes[i]}
			q[p].Right = right
			q = append(q, right)
		}
		i++
	}
	return root
}

func printT(root *TreeNode) {
	// pre-order traverse
	q := []*TreeNode{root}
	for i := 0; i < len(q); i++ {
		cur := q[i]
		if cur != nil {
			q = append(q, cur.Left, cur.Right)
		}
	}

	// trim all nulls in the end
	n := len(q)
	for i := n - 1; i >= 0 && q[i] == nil; i-- {
		n--
	}
	q = q[:n]

	// print
	fmt.Printf("[ ")
	for _, node := range q {
		if node != nil {
			fmt.Printf("%d ", node.Val)
		} else {
			fmt.Printf("null ")
		}
	}
	fmt.Println("]")
}

// func main() {
// 	fmt.Printf("LeetCode 863. All Nodes Distance K in Binary Tree ...\n\n")

// 	type args struct {
// 		root   *TreeNode
// 		target *TreeNode
// 		k      int
// 	}

// 	root1 := buildT([]int{
// 		3, 5, 1, 6, 2, 0, 8, null, null, 7, 4,
// 	})

// 	root2 := buildT([]int{1})

// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				root:   root1,
// 				target: root1.Left,
// 				k:      2,
// 			},
// 			want: []int{7, 4, 1},
// 		},
// 		{
// 			args: args{
// 				root:   root2,
// 				target: root2,
// 				k:      3,
// 			},
// 			want: []int{},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := distanceK(tt.args.root, tt.args.target, tt.args.k)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
