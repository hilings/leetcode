package main

type MyCalendar struct {
	Books [][]int
}

func Constructor() MyCalendar {
	mc := MyCalendar{
		Books: [][]int{},
	}
	return mc
}

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
// 	fmt.Println("LeetCode 729. My Calendar I ...")

// 	mc := Constructor()
// 	r := mc.Book(10, 20)
// 	fmt.Println(r)

// 	r = mc.Book(15, 25)
// 	fmt.Println(r)

// 	r = mc.Book(20, 30)
// 	fmt.Println(r)
// }
