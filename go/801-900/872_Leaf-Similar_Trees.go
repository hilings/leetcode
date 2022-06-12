package main

/**
 * Definition for a binary tree node.
 */
// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	seq1, seq2 := leafSeq(root1), leafSeq(root2)
	if len(seq1) != len(seq2) {
		return false
	}
	for i := 0; i < len(seq1); i++ {
		if seq1[i] != seq2[i] {
			return false
		}
	}
	return true
}

func leafSeq(root1 *TreeNode) []int {
	r := []int{}
	stk := []*TreeNode{}
	for cur := root1; cur != nil || len(stk) > 0; {
		if cur != nil {
			stk = append(stk, cur)
			cur = cur.Left
			continue
		}
		top := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		if top.Left == nil && top.Right == nil {
			r = append(r, top.Val)
		}
		cur = top.Right
	}
	return r
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
// 	fmt.Printf("LeetCode 872. Leaf-Similar Trees ...\n\n")

// 	type args struct {
// 		root1 *TreeNode
// 		root2 *TreeNode
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				root1: buildT([]int{3, 5, 1, 6, 2, 9, 8, null, null, 7, 4}),
// 				root2: buildT([]int{3, 5, 1, 6, 7, 4, 2, null, null, null, null, null, null, 9, 8}),
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				root1: buildT([]int{1, 2, 3}),
// 				root2: buildT([]int{1, 3, 2}),
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := leafSimilar(tt.args.root1, tt.args.root2)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
