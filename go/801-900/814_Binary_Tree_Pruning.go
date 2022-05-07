package main

// TreeNode ...
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pruneTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	root.Left = pruneTree(root.Left)
	root.Right = pruneTree(root.Right)
	if root.Left != nil || root.Right != nil {
		return root
	}

	if root.Val == 1 {
		return root
	}

	return nil
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
// 	fmt.Printf("LeetCode 814. Binary Tree Pruning ...\n\n")

// 	type args struct {
// 		root *TreeNode
// 	}
// 	tests := []struct {
// 		args args
// 		want *TreeNode
// 	}{
// 		{
// 			args: args{
// 				root: buildT([]int{1, null, 0, 0, 1}),
// 			},
// 			want: buildT([]int{1, null, 0, null, 1}),
// 		},
// 		{
// 			args: args{
// 				root: buildT([]int{1, 0, 1, 0, 0, 0, 1}),
// 			},
// 			want: buildT([]int{1, null, 1, null, 1}),
// 		},
// 		{
// 			args: args{
// 				root: buildT([]int{1, 1, 0, 1, 1, 0, 1, 0}),
// 			},
// 			want: buildT([]int{1, 1, 0, 1, 1, null, 1}),
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := pruneTree(tt.args.root)
// 		printT(r)
// 		printT(tt.want)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
