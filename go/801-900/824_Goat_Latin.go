package main

import (
	"strings"
)

func toGoatLatin(sentence string) string {
	r := ""
	words := strings.Split(sentence, " ")
	for i, word := range words {
		w := ""
		if beginWithVowel(word) {
			w = word + "ma"
		} else {
			w = word[1:] + word[:1] + "ma"
		}
		for j := 0; j <= i; j++ {
			w += "a"
		}
		r += w + " "
	}

	return r[:len(r)-1]
}

func beginWithVowel(word string) bool {
	word = strings.ToLower(word)
	if word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' {
		return true
	}
	return false
}

// func main() {
// 	fmt.Printf("LeetCode 824. Goat Latin ...\n\n")

// 	type args struct {
// 		sentence string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				sentence: "I speak Goat Latin",
// 			},
// 			want: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa",
// 		},
// 		{
// 			args: args{
// 				sentence: "The quick brown fox jumped over the lazy dog",
// 			},
// 			want: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa",
// 		},
// 		{
// 			args: args{
// 				sentence: "Each word consists of lowercase and uppercase letters only",
// 			},
// 			want: "Eachmaa ordwmaaa onsistscmaaaa ofmaaaaa owercaselmaaaaaa andmaaaaaaa uppercasemaaaaaaaa etterslmaaaaaaaaa onlymaaaaaaaaaa",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := toGoatLatin(tt.args.sentence)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
