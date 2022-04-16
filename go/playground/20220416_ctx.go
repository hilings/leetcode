package main

import (
	"context"
	"fmt"
)

type key int

const (
	_ key = iota
	k1
	k2
)

func main() {
	fmt.Printf("playground, context ...\n\n")

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
		fmt.Printf("got = %v, want = %v\n", r, tt.want)
	}

	ctx := context.Background()

	type metadata map[string][]string
	mtd := map[string][]string{
		"paxID": {"5678"},
	}
	ctx = context.WithValue(ctx, k1, mtd)

	mtd2 := metadata{
		"paxID": {"5678"},
	}
	ctx = context.WithValue(ctx, k2, mtd2)

	meta, ok := ctx.Value(k1).(metadata)
	if !ok {
		fmt.Println("assert to metadata failed")
	} else {
		fmt.Printf("assert to metadata OK, meta = %v\n", meta)
	}

	meta2, ok := ctx.Value(k2).(metadata)
	if !ok {
		fmt.Println("assert to metadata failed")
	} else {
		fmt.Printf("assert to metadata OK, meta2 = %v\n", meta2)
	}

	meta, ok = ctx.Value(k1).(map[string][]string)
	if !ok {
		fmt.Println("assert to metadata failed")
	} else {
		fmt.Printf("assert to metadata OK, meta = %v\n", meta)
	}
}
