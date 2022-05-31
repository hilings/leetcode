//         10
//        /  \
//       5    8
//      / \
//     2   20

package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func swap(root *TreeNode) {
	if root == nil {
		return
	}

	// DFS in order traverse
	arr := []*TreeNode{}
	stk := []*TreeNode{}
	cur := root
	for cur != nil || len(stk) > 0 {
		if cur != nil {
			stk = append(stk, cur)
			cur = cur.Left
			continue
		}
		top := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		arr = append(arr, top)
		cur = top.Right
	}

	// scan ascending array
	var a, b *TreeNode
	for i := 0; i < len(arr); i++ {
		if a == nil && i+1 < len(arr) && arr[i].Val > arr[i+1].Val {
			a = arr[i]
		}
		if a != nil && b == nil && i-1 >= 0 && arr[i].Val < arr[i-1].Val {
			b = arr[i]
		}
	}

	// swap
	a.Val, b.Val = b.Val, a.Val
}

// func main() {

// }
