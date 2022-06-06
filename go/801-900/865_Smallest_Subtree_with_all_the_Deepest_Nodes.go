package main

import "fmt"

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
	m := map[int]map[*TreeNode]bool{} // depth -> set of node
	p := map[*TreeNode]*TreeNode{}    // node -> parent
	depth := scan(root, 0, m, p)

	for q := m[depth]; len(q) > 0; {
		next := map[*TreeNode]bool{}
		for cur := range q {
			if len(q) == 1 {
				return cur
			}
			next[p[cur]] = true
		}
		q = next
	}
	return nil
}

func scan(root *TreeNode, d int, m map[int]map[*TreeNode]bool, p map[*TreeNode]*TreeNode) int {
	depth := d
	if _, ok := m[d]; !ok {
		m[d] = map[*TreeNode]bool{}
	}
	m[d][root] = true
	if root.Left != nil {
		p[root.Left] = root
		dd := scan(root.Left, d+1, m, p)
		if dd > depth {
			depth = dd
		}
	}
	if root.Right != nil {
		p[root.Right] = root
		dd := scan(root.Right, d+1, m, p)
		if dd > depth {
			depth = dd
		}
	}
	return depth
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
// 	fmt.Printf("LeetCode 865. Smallest Subtree with all the Deepest Nodes ...\n\n")

// 	root1 := buildT([]int{3, 5, 1, 6, 2, 0, 8, null, null, 7, 4})
// 	root2 := buildT([]int{1})
// 	root3 := buildT([]int{0, 1, 3, null, 2})

// 	type args struct {
// 		root *TreeNode
// 	}
// 	tests := []struct {
// 		args args
// 		want *TreeNode
// 	}{
// 		{
// 			args: args{
// 				root: root1,
// 			},
// 			want: root1.Left.Right,
// 		},
// 		{
// 			args: args{
// 				root: root2,
// 			},
// 			want: root2,
// 		},
// 		{
// 			args: args{
// 				root: root3,
// 			},
// 			want: root3.Left.Right,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := subtreeWithAllDeepest(tt.args.root)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
