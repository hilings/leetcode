package tree

import "fmt"

// TreeNode ...
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

func main() {
	fmt.Printf("LeetCode tree template ...\n\n")

	nodes := []int{1, 2, 3, 4, null, 6, 7}
	root := buildT(nodes)

	printT(root)
}
