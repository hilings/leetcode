package main

func nextGreatestLetter(letters []byte, target byte) byte {
	for _, c := range letters {
		if c > target {
			return c
		}
	}
	return letters[0]
}

// func main() {
// 	fmt.Printf("LeetCode 744. Find Smallest Letter Greater Than Target ...\n\n")

// 	type args struct {
// 		letters []byte
// 		target  byte
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				letters: []byte{'c', 'f', 'j'},
// 				target:  'a',
// 			},
// 			want: 'c',
// 		},
// 		{
// 			args: args{
// 				letters: []byte{'c', 'f', 'j'},
// 				target:  'c',
// 			},
// 			want: 'f',
// 		},
// 		{
// 			args: args{
// 				letters: []byte{'c', 'f', 'j'},
// 				target:  'd',
// 			},
// 			want: 'f',
// 		},
// 		{
// 			args: args{
// 				letters: []byte{'c', 'f', 'j'},
// 				target:  'j',
// 			},
// 			want: 'c',
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := nextGreatestLetter(tt.args.letters, tt.args.target)
// 		fmt.Printf("%c\n", r)
// 	}
// }
