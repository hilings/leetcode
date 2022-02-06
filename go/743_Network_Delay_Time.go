package main

func networkDelayTime(times [][]int, n int, k int) int {
	m := map[int]map[int]int{} // 2d map for times
	for _, v := range times {
		if len(m[v[0]]) == 0 {
			m[v[0]] = map[int]int{}
		}
		m[v[0]][v[1]] = v[2] // m[source][target] = time
	}
	// fmt.Println(m)

	r := map[int]int{} // time for each node to receive signal
	for i := 1; i <= n; i++ {
		r[i] = -1 // r[target] = total time from source
	}
	r[k] = 0

	todo := []int{k} // queue to process
	for len(todo) > 0 {
		source := todo[0]
		todo = todo[1:]
		for target, time := range m[source] {
			t := r[source] + time
			if r[target] == -1 || t < r[target] {
				r[target] = t
				todo = append(todo, target)
			}
		}
	}

	max := 0
	for _, t := range r {
		if t == -1 { // not reachable
			return -1
		}
		if t > max {
			max = t
		}
	}
	return max
}

// func main() {
// 	fmt.Printf("LeetCode 743. Network Delay Time ...\n\n")

// 	type args struct {
// 		times [][]int
// 		n     int
// 		k     int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				times: [][]int{
// 					{2, 1, 1},
// 					{2, 3, 1},
// 					{3, 4, 1},
// 				},
// 				n: 4,
// 				k: 2,
// 			},
// 			want: 2,
// 		},
// 		{
// 			args: args{
// 				times: [][]int{
// 					{1, 2, 1},
// 				},
// 				n: 2,
// 				k: 1,
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				times: [][]int{
// 					{1, 2, 1},
// 				},
// 				n: 2,
// 				k: 2,
// 			},
// 			want: -1,
// 		},
// 		{
// 			args: args{
// 				times: [][]int{
// 					{1, 2, 1},
// 					{2, 1, 3},
// 				},
// 				n: 2,
// 				k: 2,
// 			},
// 			want: 3,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := networkDelayTime(tt.args.times, tt.args.n, tt.args.k)
// 		fmt.Printf("got = %d\t\twanted = %d\n\n", r, tt.want)
// 	}

// }
