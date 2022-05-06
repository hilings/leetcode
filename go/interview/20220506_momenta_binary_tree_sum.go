package main

// TreeNode ...
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func solution(root *TreeNode, sum int) [][]int {
	r := [][]int{}
	if root == nil {
		return r
	}

	helper(root, sum, []int{root.Val}, root.Val, &r)

	return r
}

func helper(root *TreeNode, sum int, path []int, pathSum int, r *[][]int) {
	if root.Left == nil && root.Right == nil {
		if pathSum == sum {
			*r = append(*r, path)
		}
		return
	}
	if root.Left != nil {
		newpath := append([]int{}, path...)
		newpath = append(newpath, root.Left.Val)
		helper(root.Left, sum, newpath, pathSum+root.Left.Val, r)
	}
	if root.Right != nil {
		newpath := append([]int{}, path...)
		newpath = append(newpath, root.Right.Val)
		helper(root.Right, sum, newpath, pathSum+root.Right.Val, r)
	}
}

// func main() {
// 	fmt.Printf("Binary Tree Sum, with Momenta, R1 ...\n\n")

// 	leftLeft := TreeNode{
// 		Val: 1,
// 	}
// 	left := TreeNode{
// 		Val:  2,
// 		Left: &leftLeft,
// 	}
// 	right := TreeNode{
// 		Val: 3,
// 	}
// 	root := TreeNode{
// 		Val:   1,
// 		Left:  &left,
// 		Right: &right,
// 	}

// 	r := solution(&root, 4)
// 	fmt.Println(r)

// }
