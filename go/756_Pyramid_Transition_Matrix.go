package main

func pyramidTransition(bottom string, allowed []string) bool {
	mAllowed := map[string][]string{}
	for _, pattern := range allowed {
		prefix := pattern[:2] // two blocks as triangular base
		if _, ok := mAllowed[prefix]; !ok {
			mAllowed[prefix] = []string{}
		}
		mAllowed[prefix] = append(mAllowed[prefix], pattern[2:])
	}
	return f756(bottom, mAllowed, map[string]bool{})
}

func f756(bottom string, mAllowed map[string][]string, visited map[string]bool) bool {
	options := [][]string{} // options for each position for bottom-1 layer
	for i := 0; i < len(bottom)-1; i++ {
		base := bottom[i : i+2]
		// fmt.Printf("\t%s\n", base)
		tops, ok := mAllowed[base]
		if !ok { // no option for this base, return immediately
			// fmt.Printf("\tbase = %s, none allowed\n", base)
			return false
		}
		options = append(options, tops)
	}
	// fmt.Println(options)

	if len(bottom) == 2 && len(options) > 0 { // simplest case
		return true
	}

	for _, newBottom := range build(options) { // recursively build bottom-1 layer
		if v, ok := visited[newBottom]; ok && v == false {
			continue
		}
		if f756(newBottom, mAllowed, visited) { // any one works
			return true
		}
		visited[newBottom] = false
	}

	return false
}

func build(options [][]string) []string {
	if len(options) == 0 {
		return []string{""}
	}

	l := []string{}
	lSuffix := build(options[1:])
	for _, first := range options[0] {
		for _, rest := range lSuffix {
			l = append(l, first+rest)
		}
	}
	return l
}

// func main() {
// 	fmt.Printf("LeetCode 756. Pyramid Transition Matrix ...\n\n")

// 	type args struct {
// 		bottom  string
// 		allowed []string
// 	}
// 	tests := []struct {
// 		args args
// 		want bool
// 	}{
// 		{
// 			args: args{
// 				bottom: "BCD",
// 				allowed: []string{
// 					"BCC",
// 					"CDE",
// 					"CEA",
// 					"FFF",
// 				},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				bottom: "AAAA",
// 				allowed: []string{
// 					"AAB",
// 					"AAC",
// 					"BCD",
// 					"BBE",
// 					"DEF",
// 				},
// 			},
// 			want: true,
// 		},
// 		{
// 			args: args{
// 				bottom: "DAAAAD",
// 				allowed: []string{
// 					"DAD", "DAE", "DAB", "DAF", "DAC", "EAD", "EAE", "EAB", "EAF", "EAC", "BAD", "BAE", "BAB", "BAF", "BAC", "FAD", "FAE", "FAB", "FAF", "FAC", "CAD", "CAE", "CAB", "CAF", "CAC", "ADD", "ADE", "ADB", "ADF", "ADC", "AED", "AEE", "AEB", "AEF", "AEC", "ABD", "ABE", "ABB", "ABF", "ABC", "AFD", "AFE", "AFB", "AFF", "AFC", "ACD", "ACE", "ACB", "ACF", "ACC", "AAD", "AAE", "AAB", "AAF", "AAC", "AAA",
// 				},
// 			},
// 			want: true,
// 		},
// 	}

// 	for _, tt := range tests {
// 		r := pyramidTransition(tt.args.bottom, tt.args.allowed)
// 		fmt.Println(r)
// 	}
// }
