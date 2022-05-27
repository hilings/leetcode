package main

// func rand10() int {
// 	const k = 7
// 	a, b := rand7(), rand7()
// 	n := k*(a-1) + b // 1 ~ 49
// 	if n > 40 {      // 41 ~ 49
// 		return rand10()
// 	}
// 	return (n-1)%10 + 1 // 1 ~ 40
// }

// func main() {
// 	fmt.Printf("LeetCode 470. Implement Rand10() Using Rand7() ...\n\n")

// 	type args struct {
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := rand10()
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
