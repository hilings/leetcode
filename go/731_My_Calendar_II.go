package main

type MyCalendarTwo struct {
	Books       [][]int
	DoubleBooks [][]int
}

// func Constructor() MyCalendarTwo {
// 	mc := MyCalendarTwo{
// 		Books:       [][]int{},
// 		DoubleBooks: [][]int{},
// 	}
// 	return mc
// }

func (this *MyCalendarTwo) Book(start int, end int) bool {
	for _, db := range this.DoubleBooks {
		if end <= db[0] || start >= db[1] {
			continue
		}
		return false
	}

	for _, b := range this.Books {
		if end <= b[0] || start >= b[1] {
			continue
		}
		ol := overlap(b[0], b[1], start, end)
		this.DoubleBooks = append(this.DoubleBooks, ol)
	}

	this.Books = append(this.Books, []int{start, end})
	return true
}

// func overlap(start1 int, end1 int, start2 int, end2 int) []int {
// 	start, end := start1, end1
// 	if start1 < start2 {
// 		start = start2
// 	}
// 	if end1 > end2 {
// 		end = end2
// 	}

// 	return []int{start, end}
// }

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(start,end);
 */

// func main() {
// 	fmt.Printf("LeetCode 731. My Calendar II ...\n\n")

// 	mc := Constructor()

// 	books := [][]int{
// 		{10, 20},
// 		{50, 60},
// 		{10, 40},
// 		{5, 15},
// 		{5, 10},
// 		{25, 55},
// 	}
// 	for _, b := range books {
// 		fmt.Printf("+[%d, %d] ...\n", b[0], b[1])
// 		r := mc.Book(b[0], b[1])
// 		fmt.Printf("%v, books = %v, doubleBooks = %v\n\n", r, mc.Books, mc.DoubleBooks)
// 	}

// }
