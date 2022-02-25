package main

import "fmt"

func minSwapsCouples(row []int) int {
	mID2Seat := map[int]int{} // map id -> seat
	for seat, id := range row {
		mID2Seat[id] = seat
	}

	count := 0
	for i := 0; i < len(row); i += 2 {
		left, right := row[i], row[i+1]
		fmt.Printf("%d %d\tleft = %d, right = %d\n", i, i+1, left, right)
		if left/2 == right/2 { // already paired
			fmt.Printf("\talready paired\n")
			continue
		}

		leftCouple := left ^ 1
		leftCoupleSeat := mID2Seat[leftCouple]
		fmt.Printf("\tleftCouple = %d, seat = %d, swap\n", leftCouple, leftCoupleSeat)
		row[i+1], row[leftCoupleSeat] = row[leftCoupleSeat], row[i+1] // swap
		mID2Seat[leftCouple], mID2Seat[right] = i+1, leftCoupleSeat   // update map id -> seat
		count++
	}
	return count
}

// func main() {
// 	fmt.Printf("LeetCode 765. Couples Holding Hands ...\n\n")

// 	type args struct {
// 		row []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				row: []int{0, 2, 1, 3},
// 			},
// 			want: 1,
// 		},
// 		{
// 			args: args{
// 				row: []int{3, 2, 0, 1},
// 			},
// 			want: 0,
// 		},
// 		{
// 			args: args{
// 				row: []int{0, 3, 2, 5, 4, 7, 1, 6},
// 			},
// 			want: 3,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := minSwapsCouples(tt.args.row)
// 		fmt.Println(r)
// 	}
// }
