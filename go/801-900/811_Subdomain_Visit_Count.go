package main

import (
	"fmt"
	"strconv"
	"strings"
)

func subdomainVisits(cpdomains []string) []string {
	m := make(map[string]int)
	for _, s := range cpdomains {
		fields := strings.Split(s, " ")
		count, _ := strconv.Atoi(fields[0])
		subdomains := strings.Split(fields[1], ".")
		sub := ""
		for i := len(subdomains) - 1; i >= 0; i-- {
			if sub == "" {
				sub = subdomains[i]
			} else {
				sub = subdomains[i] + "." + sub
			}
			m[sub] += count
		}
	}

	r := []string{}
	for domain, count := range m {
		s := fmt.Sprintf("%d %s", count, domain)
		r = append(r, s)
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 811. Subdomain Visit Count ...\n\n")

// 	type args struct {
// 		cpdomains []string
// 	}
// 	tests := []struct {
// 		args args
// 		want []string
// 	}{
// 		{
// 			args: args{
// 				cpdomains: []string{
// 					"9001 discuss.leetcode.com",
// 				},
// 			},
// 			want: []string{
// 				"9001 leetcode.com",
// 				"9001 discuss.leetcode.com",
// 				"9001 com",
// 			},
// 		},
// 		{
// 			args: args{
// 				cpdomains: []string{
// 					"900 google.mail.com",
// 					"50 yahoo.com",
// 					"1 intel.mail.com",
// 					"5 wiki.org",
// 				},
// 			},
// 			want: []string{
// 				"901 mail.com",
// 				"50 yahoo.com",
// 				"900 google.mail.com",
// 				"5 wiki.org",
// 				"5 org",
// 				"1 intel.mail.com",
// 				"951 com",
// 			},
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := subdomainVisits(tt.args.cpdomains)
// 		fmt.Printf("got = %v, want = %v\n\n", r, tt.want)
// 	}
// }
