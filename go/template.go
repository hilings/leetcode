package main

import (
	"fmt"
)

func main() {
	fmt.Printf("LeetCode XXX. ABCDEFG ...\n\n")

	type args struct {
	}
	tests := []struct {
		args args
		want int
	}{
		{
			args: args{},
			want: 0,
		},
	}
	for _, tt := range tests {
		r := tt.args
		fmt.Println(r)
	}
}
