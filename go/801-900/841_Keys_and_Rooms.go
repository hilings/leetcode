package main

func canVisitAllRooms(rooms [][]int) bool {
	visited := map[int]bool{}
	q := []int{0}
	for i := 0; i < len(q); i++ {
		k := q[i]
		if _, ok := visited[k]; ok {
			continue
		}
		// fmt.Printf("\ttodo = %v, visiting = %d\n", q, k)
		visited[k] = true
		for _, next := range rooms[k] {
			if _, ok := visited[next]; ok {
				continue
			}
			q = append(q, next)
			// fmt.Printf("\t\tappending = %d\n", next)
		}
	}
	// fmt.Printf("\ttodo = %v, visited = %v\n", q, visited)
	return len(visited) == len(rooms)
}

// func main() {
// 	fmt.Printf("LeetCode 841. Keys and Rooms ...\n\n")

// 	type args struct {
// 		rooms [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				rooms: [][]int{
// 					{1},
// 					{2},
// 					{3},
// 					{},
// 				},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				rooms: [][]int{
// 					{1, 3},
// 					{3, 0, 1},
// 					{2},
// 					{0},
// 				},
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := canVisitAllRooms(tt.args.rooms)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
