package main

func countPrimeSetBits(left int, right int) int {
	bitmapPrime := 0b10100010100010101100	// 2,3,5,7,11,13,17,19 bit set
	count := 0
	for i := left; i <= right; i++ {
		nBits := 0
		for n := i; n > 0; n /= 2 {
			nBits += n % 2
		}
		if (bitmapPrime >> nBits ) & 1 == 1 {
			count++
		}
	}
	return count
}

// func main() {
// 	fmt.Printf("LeetCode 762. Prime Number of Set Bits in Binary Representation ...\n\n")

// 	type args struct {
// 		left  int
// 		right int
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				left:  6,
// 				right: 10,
// 			},
// 			want: 4,
// 		},
// 		{
// 			args: args{
// 				left:  10,
// 				right: 15,
// 			},
// 			want: 5,
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := countPrimeSetBits(tt.args.left, tt.args.right)
// 		fmt.Println(r)
// 	}

// }