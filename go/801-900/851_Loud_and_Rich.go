package main

func loudAndRich2(richer [][]int, quiet []int) []int {
	mRicherlist := map[int][]int{}
	for _, pair := range richer {
		richer, cur := pair[0], pair[1]
		if _, ok := mRicherlist[cur]; !ok {
			mRicherlist[cur] = []int{}
		}
		mRicherlist[cur] = append(mRicherlist[cur], richer)
	}

	r := make([]int, len(quiet))
	for i := 0; i < len(quiet); i++ {
		r[i] = -1
	}
	for i := 0; i < len(quiet); i++ {
		dfs851(mRicherlist, quiet, i, &r)
	}
	return r
}

func dfs851(mRicherList map[int][]int, quiet []int, i int, r *[]int) int {
	if (*r)[i] >= 0 {
		return (*r)[i]
	}
	(*r)[i] = i
	for _, richer := range mRicherList[i] {
		richerQuietnessIndex := dfs851(mRicherList, quiet, richer, r)
		if quiet[(*r)[i]] > quiet[richerQuietnessIndex] {
			(*r)[i] = richerQuietnessIndex
		}
	}
	return (*r)[i]
}

func loudAndRich(richer [][]int, quiet []int) []int {
	mRicherList := map[int][]int{}
	for _, pair := range richer {
		richer, cur := pair[0], pair[1] // richer > cur
		if _, ok := mRicherList[cur]; !ok {
			mRicherList[cur] = []int{}
		}
		mRicherList[cur] = append(mRicherList[cur], richer)
	}

	queue := []int{}
	todo := map[int]bool{}
	r := make([]int, len(quiet))
	for i := 0; i < len(quiet); i++ {
		r[i] = i
		if _, ok := mRicherList[i]; !ok {
			queue = append(queue, i)
		} else {
			todo[i] = true
		}
	}

	for k := 0; k < len(queue); k++ {
		cur := queue[k]
		for _, richer := range mRicherList[cur] {
			if quiet[r[richer]] < quiet[r[cur]] {
				r[cur] = r[richer]
			}
		}

		// refresh queue
		for i := range todo {
			countReadyRicher := 0
			for _, richer := range mRicherList[i] {
				if !todo[richer] {
					countReadyRicher++
				}
			}
			if countReadyRicher == len(mRicherList[i]) {
				queue = append(queue, i)
				delete(todo, i)
			}
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 851. Loud and Rich ...\n\n")

// 	type args struct {
// 		richer [][]int
// 		quiet  []int
// 	}
// 	tests := []struct {
// 		args args
// 		want []int
// 	}{
// 		{
// 			args: args{
// 				richer: [][]int{
// 					{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3},
// 				},
// 				quiet: []int{3, 2, 5, 4, 6, 1, 7, 0},
// 			},
// 			want: []int{5, 5, 2, 5, 4, 5, 6, 7},
// 		},
// 		{
// 			args: args{
// 				richer: [][]int{},
// 				quiet:  []int{0},
// 			},
// 			want: []int{0},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := loudAndRich(tt.args.richer, tt.args.quiet)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)

// 		r = loudAndRich2(tt.args.richer, tt.args.quiet)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
