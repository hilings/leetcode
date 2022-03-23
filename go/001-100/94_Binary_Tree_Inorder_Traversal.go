package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	left := inorderTraversal(root.Left)
	right := inorderTraversal(root.Right)
	l := append(left, root.Val)
	return append(l, right...)
}

func inorderTraversalI(root *TreeNode) []int {
	l := []int{}
	stack := []*TreeNode{}
	cur := root
	for cur != nil || len(stack) > 0 {
		for cur != nil {
			stack = append(stack, cur)
			cur = cur.Left
		}
		cur = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		l = append(l, cur.Val)
		cur = cur.Right
	}

	return l
}

// func main() {
// 	fmt.Printf("LeetCode 94. Binary Tree Inorder Traversal ...\n\n")

// 	n3 := &TreeNode{
// 		Val: 3,
// 	}
// 	n2 := &TreeNode{
// 		Val:  2,
// 		Left: n3,
// 	}
// 	n1 := &TreeNode{
// 		Val:   1,
// 		Right: n2,
// 	}
// 	type args struct {
// 		root *TreeNode
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				root: n1,
// 			},
// 			want: []int{1, 3, 2},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := inorderTraversal(tt.args.root)
// 		fmt.Println(r)

// 		r = inorderTraversalI(tt.args.root)
// 		fmt.Println(r)
// 	}
// }
