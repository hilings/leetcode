package main

import (
	"sort"
)

func maxProfitAssignment(difficulty []int, profit []int, worker []int) int {
	n := len(difficulty)
	data := make([][]int, n, n)
	for i := 0; i < n; i++ {
		data[i] = []int{difficulty[i], profit[i]}
	}

	sort.Slice(data, func(i, j int) bool { // ascend by difficulty, then descend by profit
		return data[i][0] < data[j][0] || (data[i][0] == data[j][0] && data[i][1] > data[j][1])
	})
	sort.Ints(worker) // ascend by ability

	r := 0
	best, index := 0, 0
	for k := 0; k < len(worker); k++ {
		cap := worker[k]
		for ; index < n && cap >= data[index][0]; index++ {
			if data[index][1] > best {
				best = data[index][1]
			}
		}
		r += best
	}
	return r
}

func maxProfitAssignment0(difficulty []int, profit []int, worker []int) int {
	n := len(difficulty)
	data := make([][]int, n, n)
	for i := 0; i < n; i++ {
		data[i] = []int{difficulty[i], profit[i]}
	}
	// fmt.Println(data)

	sort.Slice(data, func(i, j int) bool { // ascend by difficulty, then descend by profit
		return data[i][0] < data[j][0] || (data[i][0] == data[j][0] && data[i][1] > data[j][1])
	})
	sort.Ints(worker) // ascend by ability

	for i := 1; i < n; i++ {
		if data[i-1][1] > data[i][1] {
			data[i][1] = data[i-1][1]
		}
	}

	r := 0
	for k := 0; k < len(worker); k++ {
		cap := worker[k]
		// fmt.Printf("cap = %d\n", cap)
		i, j := 0, n-1
		for i < j { // binary search first difficulty >= cap
			// fmt.Printf("\t%d %d\n", i, j)
			mid := (i + j) / 2
			if cap <= data[mid][0] {
				j = mid
			} else {
				i = mid + 1
			}
		}
		// fmt.Printf("\t\t%d %d\n", i, j)
		if cap < data[i][0] {
			i--
		}
		if i >= 0 {
			// fmt.Printf("\tprofit = %d\n", data[i][1])
			r += data[i][1]
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 826. Most Profit Assigning Work ...\n\n")

// 	type args struct {
// 		difficulty []int
// 		profit     []int
// 		worker     []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				difficulty: []int{2, 4, 6, 8, 10},
// 				profit:     []int{10, 20, 30, 40, 50},
// 				worker:     []int{4, 5, 6, 7},
// 			},
// 			want: 100,
// 		},
// 		{
// 			args: args{
// 				difficulty: []int{85, 47, 57},
// 				profit:     []int{24, 66, 99},
// 				worker:     []int{40, 25, 25},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				difficulty: []int{23, 30, 35, 35, 43, 46, 47, 81, 83, 98},
// 				profit:     []int{8, 11, 11, 20, 33, 37, 60, 72, 87, 95},
// 				worker:     []int{95, 46, 47, 97, 11, 35, 99, 56, 41, 92},
// 				//   87 +37 +60 +87 + 0 +20 +95 +60 +20 +87
// 			},
// 			want: 553,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := maxProfitAssignment(tt.args.difficulty, tt.args.profit, tt.args.worker)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = maxProfitAssignment(tt.args.difficulty, tt.args.profit, tt.args.worker)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
