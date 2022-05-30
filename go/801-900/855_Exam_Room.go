package main

import (
	"fmt"
)

// ExamRoom ...
type ExamRoom struct {
	n      int
	seated []int
}

// Constructor ...
func Constructor(n int) ExamRoom {
	examRoom := ExamRoom{
		n:      n,
		seated: []int{},
	}
	return examRoom
}

// Seat ...
func (er *ExamRoom) Seat() (pos int) {
	defer func() {
		fmt.Printf("Seat() = %d\n\n", pos)
	}()

	fmt.Printf("\tbefore %v\n", er.seated)
	if len(er.seated) == 0 {
		er.seated = append(er.seated, 0)
		return 0
	}

	dis := 0                  // label of seat to be taken
	index := 0                // index in er.seated where to insert
	if er.seated[0]-0 > dis { // left end
		dis = er.seated[0] - 0
		pos = 0
		index = 0
	}
	for i := 0; i < len(er.seated)-1; i++ {
		mid := (er.seated[i] + er.seated[i+1]) / 2
		if mid-er.seated[i] > dis {
			dis = mid - er.seated[i]
			pos = mid
			index = i + 1
		}
	}
	if er.n-1-er.seated[len(er.seated)-1] > dis { // right end
		dis = er.n - 1 - er.seated[len(er.seated)-1]
		pos = er.n - 1
		index = len(er.seated)
	}

	next := append([]int{}, er.seated[0:index]...)
	next = append(next, pos)
	next = append(next, er.seated[index:]...)
	er.seated = next

	fmt.Printf("\tafter  %v\n", er.seated)
	return pos
}

// Leave ...
func (er *ExamRoom) Leave(p int) {
	fmt.Println("Leave()")
	fmt.Printf("\tbefore %v\n", er.seated)
	left, right := 0, len(er.seated)-1
	for left < right {
		mid := (left + right) / 2
		if er.seated[mid] == p {
			left = mid
			break
		}
		if er.seated[mid] > p {
			right = mid
		} else {
			left = mid + 1
		}
	}
	next := append([]int{}, er.seated[0:left]...)
	next = append(next, er.seated[left+1:]...)
	er.seated = next
	fmt.Printf("\tafter  %v\n\n", er.seated)
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Seat();
 * obj.Leave(p);
 */

// func main() {
// 	fmt.Printf("LeetCode 855. Exam Room ...\n\n")

// 	er := Constructor(10)
// 	er.Seat()
// 	er.Seat()
// 	er.Seat()
// 	er.Seat()
// 	er.Leave(4)
// 	er.Seat()

// 	// er := Constructor(4)
// 	// er.Seat()
// 	// er.Seat()
// 	// er.Seat()
// 	// er.Seat()
// 	// er.Leave(1)
// 	// er.Leave(3)
// 	// er.Seat()
// }
