package main

import (
	"strings"
	"unicode"
)

func maskPII(s string) string {
	if index := strings.Index(s, "@"); index != -1 { // email
		name := strings.ToLower(s[:index])
		name = name[:1] + "*****" + name[len(name)-1:]
		domain := strings.ToLower(s[index+1:])
		return name + "@" + domain
	}

	// phone
	phone := ""
	for _, c := range s {
		if unicode.IsDigit(c) {
			phone += string(c)
		}
	}
	countryCode := ""
	for i := 0; i < len(phone)-10; i++ {
		countryCode += "*"
	}
	if len(countryCode) > 0 {
		countryCode = "+" + countryCode + "-"
	}
	return countryCode + "***-***-" + phone[len(phone)-4:]
}

// func main() {
// 	fmt.Printf("LeetCode 831. Masking Personal Information ...\n\n")

// 	type args struct {
// 		s string
// 	}
// 	tests := []struct {
// 		args args
// 		want string
// 	}{
// 		{
// 			args: args{
// 				s: "LeetCode@LeetCode.com",
// 			},
// 			want: "l*****e@leetcode.com",
// 		},
// 		{
// 			args: args{
// 				s: "AB@qq.com",
// 			},
// 			want: "a*****b@qq.com",
// 		},
// 		{
// 			args: args{
// 				s: "1(234)567-890",
// 			},
// 			want: "***-***-7890",
// 		},
// 	}
// 	for _, tt := range tests {
// 		r := maskPII(tt.args.s)
// 		fmt.Printf("got  = %v\nwant = %v\n\n", r, tt.want)
// 	}
// }
