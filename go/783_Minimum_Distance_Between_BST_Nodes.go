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
	fmt.Printf("\n[ ")
	for _, node := range q {
		if node != nil {
			fmt.Printf("%d ", node.Val)
		} else {
			fmt.Printf("null ")
		}
	}
	fmt.Println("]")
}

func minDiffInBST(root *TreeNode) int {
	cur := root
	stack := []*TreeNode{}
	min, prev := 100000, -1
	// in-order traverse
	for cur != nil || len(stack) > 0 {
		for cur != nil {
			stack = append(stack, cur)
			cur = cur.Left
		}
		top := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if prev != -1 {
			diff := top.Val - prev
			if diff < min {
				min = diff
			}
		}
		cur = top.Right
		prev = top.Val
	}

	return min
}

func minDiffInBST2(root *TreeNode) int {
	min, prev := 100000, -1
	inT(root, &min, &prev)
	return min
}

func inT(root *TreeNode, min *int, prev *int) {
	if root.Left != nil {
		inT(root.Left, min, prev)
	}
	if *prev != -1 && root.Val-*prev < *min {
		*min = root.Val - *prev
	}
	*prev = root.Val
	if root.Right != nil {
		inT(root.Right, min, prev)
	}
}

func main() {
	fmt.Printf("LeetCode 783. Minimum Distance Between BST Nodes ...\n\n")

	type args struct {
		root *TreeNode
	}
	tests := []struct {
		args args
		want int
	}{
		{
			args: args{
				root: buildT([]int{4, 2, 6, 1, 3}),
			},
			want: 1,
		},
		{
			args: args{
				root: buildT([]int{1, 0, 48, null, null, 12, 49}),
			},
			want: 1,
		},
		{
			args: args{
				root: buildT([]int{27, null, 34, null, 58, 50, null, 44}),
			},
			want: 6,
		},
	}
	for _, tt := range tests {
		printT(tt.args.root)
		r := minDiffInBST(tt.args.root)
		fmt.Printf("got = %v, want = %v\n", r, tt.want)

		r = minDiffInBST2(tt.args.root)
		fmt.Printf("got = %v, want = %v\n", r, tt.want)
	}
}
