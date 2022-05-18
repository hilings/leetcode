package main

import (
	"strings"
)

func findString(src string, pattern string, ignoreCase bool) int {
	if ignoreCase {
		src = strings.ToLower(src)
		pattern = strings.ToLower(pattern)
	}
	for i := 0; i < len(src); i++ {
		found := true
		for j := 0; j < len(pattern); j++ {
			if i+j >= len(src) {
				return -1
			}
			if src[i+j] == pattern[j] {
				continue
			}
			found = false
			break
		}
		if found {
			return i
		}

	}
	return -1
}

func toLower(src string) string {
	r := ""

	for _, c := range src {
		if c >= 'A' && c <= 'Z' {
			c = c - 'A' + 'a'
			r += string(c)
		} else {
			r += string(c)
		}
	}

	return r
}

type ListNode struct {
	Val  int
	Next *ListNode
}

type Queue struct {
	Head *ListNode
	Tail *ListNode
	Len  int
}

func initQ() *Queue {
	newNode := &ListNode{}
	newQueue := &Queue{
		Head: newNode,
		Tail: newNode,
	}
	return newQueue
}

func push(head *ListNode, val int) (*ListNode, *ListNode) {
	p := head
	for p.Next != nil {
		p = p.Next
	}
	newNode := &ListNode{
		Val: val,
	}
	p.Next = newNode
	return head, newNode
}

func pushQ(q *Queue, val int) *Queue {
	// q.Head, q.Tail = push(q.Head, val)
	newNode := &ListNode{
		Val: val,
	}
	q.Tail.Next = newNode
	q.Tail = q.Tail.Next
	q.Len++

	return q
}

func popQ(q *Queue) int {
	if q.Len == 0 {
		return 0
	}

	val := q.Head.Next.Val
	q.Head.Next = q.Head.Next.Next
	q.Len--
	if q.Len == 0 {
		q.Tail = q.Head
	}
	return val
}

func pop(head *ListNode) (*ListNode, int) {
	if head == nil {
		return nil, 0
	}
	val := head.Val
	head = head.Next

	return head, val
}

// func main() {
// 	fmt.Printf("Microsoft Queue by Linked List ...\n\n")

// 	type args struct {
// 		src     string
// 		pattern string
// 		ignored bool
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				src:     "abc",
// 				pattern: "bc",
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				src:     "abc",
// 				pattern: "dc",
// 			},
// 			want: -1,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := findString(tt.args.src, tt.args.pattern, tt.args.ignored)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
