package main

func scanByLayer(root *TreeNode) []int {
	q := []*TreeNode{
		root,
	}
	res := []int{}

	for len(q) > 0 {
		next := []*TreeNode{}
		for i, node := range q {
			if i == len(q)-1 { // rightmost of this layer
				res = append(res, node.Val)
			}

			if node.Left != nil {
				next = append(next, node.Left)
			}
			if node.Right != nil {
				next = append(next, node.Right)
			}
		}
		q = next // next layer
	}

	return res
}

// func main() {
// 	fmt.Printf("rightmost node per layer, ByteDance R1 ...\n\n")
// }
