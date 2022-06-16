package main

/**
 * Definition for a binary tree node.
 */
// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func minCameraCover(root *TreeNode) int {
	r := 0
	if dfs968(root, &r) == 0 { // root is a leaf
		r++
	}
	return r
}

func dfs968(root *TreeNode, r *int) int {
	if root == nil {
		return 2 // no need camera
	}
	left, right := dfs968(root.Left, r), dfs968(root.Right, r)
	if left == 2 && right == 2 {
		return 0 // this is a leaf
	}

	if left == 0 || right == 0 { // parent of a leaf
		(*r)++ // put a camera here, cover leaf, parent and parent's parent, best strategy
		return 1
	}

	// left == 1 || right == 1, parent of a leaf parent
	return 2 // already covered, no need camera
}

// const null = -1

// func buildT(nodes []int) *TreeNode {
// 	if len(nodes) == 0 {
// 		return nil
// 	}

// 	root := &TreeNode{Val: nodes[0]}
// 	q := []*TreeNode{root}
// 	for i, p := 1, 0; i < len(nodes); p++ {
// 		if nodes[i] != null {
// 			left := &TreeNode{Val: nodes[i]}
// 			q[p].Left = left
// 			q = append(q, left)
// 		}
// 		i++

// 		if i < len(nodes) && nodes[i] != null {
// 			right := &TreeNode{Val: nodes[i]}
// 			q[p].Right = right
// 			q = append(q, right)
// 		}
// 		i++
// 	}
// 	return root
// }

// func printT(root *TreeNode) {
// 	// pre-order traverse
// 	q := []*TreeNode{root}
// 	for i := 0; i < len(q); i++ {
// 		cur := q[i]
// 		if cur != nil {
// 			q = append(q, cur.Left, cur.Right)
// 		}
// 	}

// 	// trim all nulls in the end
// 	n := len(q)
// 	for i := n - 1; i >= 0 && q[i] == nil; i-- {
// 		n--
// 	}
// 	q = q[:n]

// 	// print
// 	fmt.Printf("[ ")
// 	for _, node := range q {
// 		if node != nil {
// 			fmt.Printf("%d ", node.Val)
// 		} else {
// 			fmt.Printf("null ")
// 		}
// 	}
// 	fmt.Println("]")
// }

// func main() {
// 	fmt.Printf("LeetCode 968. Binary Tree Cameras ...\n\n")

// 	type args struct {
// 		root *TreeNode
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				root: buildT([]int{0, 0, null, 0, 0}),
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				root: buildT([]int{0, 0, null, 0, null, 0, null, null, 0}),
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				root: buildT([]int{0}),
// 			},
// 			want: 1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := minCameraCover(tt.args.root)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
