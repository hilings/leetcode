package main

import "fmt"

func containVirus(isInfected [][]int) int {
	// fmt.Println("\ncontainVirus..............................................\n")
	m, n := len(isInfected), len(isInfected[0])
	mInfectedRegions := map[string][][]int{}         // origin -> region as cell slice
	mThreatingCells := map[string]map[string][]int{} // origin -> cellKey -> cell
	d := [][]int{
		{-1, 0}, // up
		{0, -1}, // left
		{0, 1},  // right
		{1, 0},  // down
	}
	mWallNeeded := map[string]int{} // origin -> wall needed to block this region starting from origin
	target := ""
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if isInfected[i][j] != 1 {
				continue
			}
			isInfected[i][j] = 2 // visited
			region := [][]int{   // one infected region originate from i,j
				{i, j},
			}
			wallNeeded := 0 // number of cells to be infected the following night
			threatingCells := map[string][]int{}

			for k := 0; k < len(region); k++ { // spread through the whole contaminated region
				cell := region[k]
				// fmt.Printf("@ %v\n", cell)
				for _, move := range d {
					_cell := []int{cell[0] + move[0], cell[1] + move[1]} // adjacent cell
					if _cell[0] < 0 || _cell[0] == m || _cell[1] < 0 || _cell[1] == n || isInfected[_cell[0]][_cell[1]] >= 2 {
						continue // out of range | visited | blocked
					}
					if isInfected[_cell[0]][_cell[1]] == 1 {
						isInfected[_cell[0]][_cell[1]] = 2 // visited
						region = append(region, _cell)
						// fmt.Printf("\t+ %v\n", _cell)
					} else if isInfected[_cell[0]][_cell[1]] == 0 {
						wallNeeded++
						key := fmt.Sprintf("%d-%d", _cell[0], _cell[1])
						threatingCells[key] = _cell
						// fmt.Printf("\t%v | %v\n", cell, _cell)
					}
				}
			}

			origin := fmt.Sprintf("%d-%d", i, j)
			mInfectedRegions[origin] = region
			mThreatingCells[origin] = threatingCells
			mWallNeeded[origin] = wallNeeded

			if target == "" || len(threatingCells) > len(mThreatingCells[target]) {
				target = origin
			}

			// fmt.Printf("origin = %s\n", origin)
			// fmt.Printf("region = (%d) .   %v\n", len(region), region)
			// fmt.Printf("threating = (%d)    %v\n", len(threatingCells), threatingCells)
			// fmt.Printf("wallNeeded = %d\n\n", wallNeeded)
		}
	}

	if len(mWallNeeded) == 0 { // end of action
		return 0
	}

	// quarantine target region
	for _, cell := range mInfectedRegions[target] {
		isInfected[cell[0]][cell[1]] = 3 // blocked
	}
	// spread over night
	for k, m := range mThreatingCells {
		if k == target {
			continue
		}
		for _, c := range m {
			isInfected[c[0]][c[1]] = 1
		}
	}
	// reset visited
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if isInfected[i][j] == 2 {
				isInfected[i][j] = 1
			}
		}
	}

	// fmt.Printf("target = %s\nthreating = %d\nwallNeed = %d\n", target, len(mThreatingCells[target]), mWallNeeded[target])
	// for _, l := range isInfected {
	// 	fmt.Println(l)
	// }

	return mWallNeeded[target] + containVirus(isInfected)
}

// func main() {
// 	fmt.Printf("LeetCode 749. Contain Virus ...\n\n")

// 	type args struct {
// 		isInfected [][]int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				isInfected: [][]int{
// 					{0, 1, 0, 0, 0, 0, 0, 1},
// 					{0, 1, 0, 0, 0, 0, 0, 1},
// 					{0, 0, 0, 0, 0, 0, 0, 1},
// 					{0, 0, 0, 0, 0, 0, 0, 0},
// 				},
// 			},
// 			want: 10,
// 		},
// 		{
// 			args: args{
// 				isInfected: [][]int{
// 					{1, 1, 1},
// 					{1, 0, 1},
// 					{1, 1, 1},
// 				},
// 			},
// 			want: 4,
// 		},
// 		{
// 			args: args{
// 				isInfected: [][]int{
// 					{1, 1, 1, 0, 0, 0, 0, 0, 0},
// 					{1, 0, 1, 0, 1, 1, 1, 1, 1},
// 					{1, 1, 1, 0, 0, 0, 0, 0, 0},
// 				},
// 			},
// 			want: 13,
// 		},
// 		{
// 			args: args{
// 				isInfected: [][]int{
// 					{0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
// 					{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0},
// 					{0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0},
// 					{0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
// 					{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
// 					{1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
// 					{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
// 					{0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0},
// 					{1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0},
// 					{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0},
// 					{0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
// 					{0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0},
// 					{1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1},
// 					{0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
// 					{0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0},
// 					{1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
// 					{1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
// 					{1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1},
// 					{0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
// 					{0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
// 				},
// 			},
// 			want: 129,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := containVirus(tt.args.isInfected)
// 		fmt.Println(r)
// 	}

// }
