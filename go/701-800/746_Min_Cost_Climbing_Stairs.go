package main

func minCostClimbingStairs(cost []int) int {
	dp := []int{
		0, 0,
	}
	for i := 2; i <= len(cost); i++ {
		dp = append(dp, min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]))
	}
	return dp[len(cost)]
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

// func main() {
// 	fmt.Printf("LeetCode 746. Min Cost Climbing Stairs ...\n\n")

// 	type args struct {
// 		cost []int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				cost: []int{
// 					10, 15, 20,
// 				},
// 			},
// 			want: 15,
// 		},
// 		{
// 			args: args{
// 				cost: []int{
// 					1, 100, 1, 1, 1, 100, 1, 1, 100, 1,
// 				},
// 			},
// 			want: 6,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := minCostClimbingStairs(tt.args.cost)
// 		fmt.Println(r)
// 	}
// }
