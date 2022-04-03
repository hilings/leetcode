package main

func isBipartite(graph [][]int) bool {
	qA, qB := []int{}, []int{}
	mapA, mapB := map[int]bool{}, map[int]bool{}

	for i, j, k := 0, 0, 0; i < len(qA) || j < len(qB) || k < len(graph); {
		// fmt.Printf("i = %d, j = %d\n", i, j)
		var cur int
		// var curFlag, targetFlag string
		var curMap, targetMap *map[int]bool
		var targetSet *[]int
		if i < len(qA) {
			cur = qA[i]
			// curFlag, targetFlag = "A", "B"
			curMap, targetMap = &mapA, &mapB
			targetSet = &qB
			i++
		} else if j < len(qB) {
			cur = qB[j]
			// curFlag, targetFlag = "B", "A"
			curMap, targetMap = &mapB, &mapA
			targetSet = &qA
			j++
		} else {
			if !mapA[k] && !mapB[k] {
				qA = append(qA, k)
				mapA[k] = true
				// fmt.Printf("\tadding %d to A\n", k)
			}
			k++
			continue
		}
		// fmt.Printf("\tchecking %d in %s\n", cur, curFlag)

		for _, v := range graph[cur] {
			if _, ok := (*curMap)[v]; ok {
				// fmt.Printf("\t%d already in %s\n", v, curFlag)
				return false // v already in curSet
			}
			if _, ok := (*targetMap)[v]; !ok {
				*targetSet = append(*targetSet, v) // adding v to targetSet
				(*targetMap)[v] = true
				// fmt.Printf("\tadding %d to %s\n", v, targetFlag)
			}
		}
		// fmt.Printf("\tsetA = %v, qB = %v\n", qA, qB)
	}
	return true
}

// func main() {
// 	fmt.Printf("LeetCode 785. Is Graph Bipartite? ...\n\n")

// 	type args struct {
// 		graph [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				graph: [][]int{
// 					{1, 2, 3},
// 					{0, 2},
// 					{0, 1, 3},
// 					{0, 2},
// 				},
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				graph: [][]int{
// 					{1, 3},
// 					{0, 2},
// 					{1, 3},
// 					{0, 2},
// 				},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				graph: [][]int{
// 					{},
// 					{2, 4, 6},
// 					{1, 4, 8, 9},
// 					{7, 8},
// 					{1, 2, 8, 9},
// 					{6, 9},
// 					{1, 5, 7, 8, 9},
// 					{3, 6, 9},
// 					{2, 3, 4, 6, 9},
// 					{2, 4, 5, 6, 7, 8},
// 				},
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				graph: [][]int{
// 					{}, {3}, {}, {1}, {},
// 				},
// 			},
// 			want: true,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := isBipartite(tt.args.graph)
// 		fmt.Printf("got = %v, want = %v\n", r, tt.want)
// 	}
// }
