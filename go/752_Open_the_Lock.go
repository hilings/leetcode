package main

import "fmt"

func openLock(deadends []string, target string) int {
	dp := map[string]int{
		"0000": 0,
	}
	for _, deadend := range deadends {
		dp[deadend] = -1
	}

	if dp["0000"] == -1 {
		return -1
	}
	if target == "0000" {
		return 0
	}

	q := []string{"0000"}
	for i := 0; i < len(q); i++ {
		todo := q[i]
		// fmt.Printf("%s\n", todo)
		nextList := nextList(todo)
		for _, next := range nextList {
			// fmt.Printf("\t%s", next)
			if _, ok := dp[next]; ok {
				// fmt.Printf("\tupdated or deadend\n")
				continue
			}
			dp[next] = dp[todo] + 1
			if next == target {
				return dp[next]
			}
			// fmt.Printf("\tappending\n")
			q = append(q, next)
		}
	}
	return -1
}

func nextList(target string) []string {
	l := []string{}
	for wheel := range []int{0, 1, 2, 3} {
		for _, step := range []int{1, -1} {
			digit := (int(target[wheel]-'0') + step + 10) % 10
			next := target[:wheel] + fmt.Sprintf("%c", '0'+digit) + target[wheel+1:]
			l = append(l, next)
		}
	}
	// fmt.Printf("%s -> %v\n", target, l)
	return l
}

// func main() {
// 	fmt.Printf("LeetCode 752. Open the Lock ...\n\n")

// 	type args struct {
// 		deadends []string
// 		target   string
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				deadends: []string{"0201", "0101", "0102", "1212", "2002"},
// 				target:   "0202",
// 			},
// 			want: 6,
// 		},
// 		{
// 			args: args{
// 				deadends: []string{"8888"},
// 				target:   "0009",
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				deadends: []string{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"},
// 				target:   "8888",
// 			},
// 			want: -1,
// 		},
// 		{
// 			args: args{
// 				deadends: []string{"0000"},
// 				target:   "8888",
// 			},
// 			want: -1,
// 		},
// 		{
// 			args: args{
// 				deadends: []string{"0201", "0101", "0102", "1212", "2002"},
// 				target:   "0000",
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := openLock(tt.args.deadends, tt.args.target)
// 		fmt.Println(r)
// 	}
// }
