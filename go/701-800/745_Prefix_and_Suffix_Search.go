package main

import "fmt"

type Node struct {
	Next  map[rune]*Node
	Index int
}

type WordFilter struct {
	Root *Node
}

func Constructor(words []string) WordFilter {
	wf := WordFilter{
		Root: &Node{
			Next:  map[rune]*Node{},
			Index: -1,
		},
	}
	for index, word := range words {
		cur := wf.Root
		for _, c := range word {
			// fmt.Printf("%c ", c)
			if cur.Next[c] == nil {
				cur.Next[c] = &Node{
					Next:  map[rune]*Node{},
					Index: -1,
				}
			}
			cur = cur.Next[c] // proceed to next level Node for c
		}
		cur.Index = index // mark Node as end of a word
	}
	// traverse(wf.Root, "")
	return wf
}

func traverse(cur *Node, s string) { // print all words in dictionary
	if cur.Index != -1 {
		fmt.Printf("%d: %s\n", cur.Index, s)
	}
	for c, p := range cur.Next {
		traverse(p, s+string(c))
	}
}

func (this *WordFilter) F(prefix string, suffix string) int {
	cur := this.Root
	for _, c := range prefix {
		if cur.Next == nil || cur.Next[c] == nil {
			return -1
		}
		cur = cur.Next[c]
	}

	// cur is at the last char of prefix, all words from here downwards satisfy prefix
	return scan(cur, prefix, suffix, -1)
}

func scan(cur *Node, s string, suffix string, index int) int {
	max := index
	if cur.Index != -1 && s[len(s)-len(suffix):] == suffix && cur.Index > max {
		max = cur.Index
	}
	for c, p := range cur.Next {
		_index := scan(p, s+string(c), suffix, max)
		if _index > max {
			max = _index
		}
	}
	return max
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.F(prefix,suffix);
 */

// func main() {
// 	fmt.Printf("LeetCode 745. Prefix and Suffix Search ...\n\n")

// 	type args struct {
// 		words  []string
// 		prefix string
// 		suffix string
// 	}
// 	tests := []struct {
// 		args args
// 		want int
// 	}{
// 		{
// 			args: args{
// 				words: []string{
// 					"apple",
// 					"banana",
// 					"axxe",
// 				},
// 				prefix: "a",
// 				suffix: "e",
// 			},
// 			want: 0,
// 		},
// 	}
// 	for _, tt := range tests {
// 		wf := Constructor(tt.args.words)
// 		r := wf.F(tt.args.prefix, tt.args.suffix)
// 		fmt.Println(r)
// 	}
// }
