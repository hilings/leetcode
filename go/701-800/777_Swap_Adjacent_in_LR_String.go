package main

func canTransform(start string, end string) bool {
	for i, j := 0, 0; i < len(start) || j < len(end); {
		for i < len(start) && start[i] == 'X' { // find next R or L
			i++
		}
		for j < len(end) && end[j] == 'X' { // find next R or L
			j++
		}

		if i == len(start) && j == len(end) {
			return true
		}
		if i == len(start) || j == len(end) || start[i] != end[j] { // doesn't match
			return false
		}

		if start[i] == 'R' && i > j { // R in start must be on left side of R in end
			return false
		}
		if start[i] == 'L' && i < j { // L in start must be on right side of L in end
			return false
		}
		// match so far
		i++
		j++
	}

	return true
}

// func main() {
// 	fmt.Printf("LeetCode 777. Swap Adjacent in LR String ...\n\n")

// 	type args struct {
// 		start string
// 		end   string
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				start: "RXXLRXRXL",
// 				end:   "XRLXXRRLX",
// 			},
// 			want: false,
// 		},
// 		{
// 			args: args{
// 				start: "X",
// 				end:   "L",
// 			},
// 			want: false,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := canTransform(tt.args.start, tt.args.end)
// 		fmt.Println(r)
// 	}
// }
