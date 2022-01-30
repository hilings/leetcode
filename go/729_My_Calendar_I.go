package main

type MyCalendar struct {
	Books [][]int
}

// func Constructor() MyCalendar {
// 	mc := MyCalendar{
// 		Books: [][]int{},
// 	}
// 	return mc
// }

func (this *MyCalendar) Book(start int, end int) bool {
	for _, book := range this.Books {
		if end <= book[0] || start >= book[1] {
			continue
		}
		return false
	}
	this.Books = append(this.Books, []int{start, end})
	return true
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(start,end);
 */

// func main() {
// 	fmt.Printf("LeetCode 729. My Calendar I ...\n\n")

// 	mc := Constructor()

// 	books := [][]int{
// 		{10, 20},
// 		{15, 25},
// 		{20, 30},
// 	}

// 	for _, book := range books {
// 		r := mc.Book(book[0], book[1])
// 		fmt.Println(r)
// 	}
// }
