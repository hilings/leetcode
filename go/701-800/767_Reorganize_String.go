package main

import (
	"fmt"
	"sort"
)

func reorganizeString(s string) string {
	bitmap := make([]int, 26, 26) // count each letter
	for _, c := range s {
		bitmap[c-'a']++
	}
	// fmt.Println(bitmap)

	bitmap2 := [][]int{}
	for i, count := range bitmap {
		if count == 0 {
			continue
		}
		bitmap2 = append(bitmap2, []int{i, count})
	}
	sort.Slice(bitmap2, func(i, j int) bool { // sort by letter count desc
		return bitmap2[i][1] > bitmap2[j][1]
	})
	// fmt.Println(bitmap2)

	r := ""
	for i := 1; i < len(bitmap2) && bitmap2[0][1] > 0; { // separate most letter with rest letters
		r += fmt.Sprintf("%c%c", 'a'+bitmap2[0][0], 'a'+bitmap2[i][0])
		bitmap2[0][1]--
		bitmap2[i][1]--
		if bitmap2[i][1] == 0 {
			i++
		}
	}
	if bitmap2[0][1] > 1 { // most letter more than half, impossible
		return ""
	}
	if bitmap2[0][1] == 1 { // append the last one
		return r + fmt.Sprintf("%c", 'a'+bitmap2[0][0])
	}

	for i := 1; i < len(bitmap2); i++ { // insert the rest letters
		if bitmap2[i][1] == 0 {
			continue
		}
		s := ""
		j := 0
		for k := 0; k < bitmap2[i][1]; k++ {
			s += fmt.Sprintf("%c%c", r[j], 'a'+bitmap2[i][0])
			j++
		}
		r = s + r[j:]
	}

	return r
}

// func main() {
// 	fmt.Printf("LeetCode 767. Reorganize String ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				s: "aab",
// 			},
// 			want: "aba",
// 		},
// 		{
// 			args: args{
// 				s: "aaab",
// 			},
// 			want: "",
// 		},
// 		{
// 			args: args{
// 				s: "vvvlo",
// 			},
// 			want: "vlvov",
// 		},
// 		{
// 			args: args{
// 				s: "aaaaabbbcccde",
// 			},
// 			want: "aedcbababacac",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := reorganizeString(tt.args.s)
// 		fmt.Println(r)
// 	}
// }
