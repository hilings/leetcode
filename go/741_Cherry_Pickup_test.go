package main

import "testing"

func Test_cherryPickup(t *testing.T) {
	type args struct {
		grid [][]int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			args: args{
				grid: [][]int{
					{0, 1, -1},
					{1, 0, -1},
					{1, 1, 1},
				},
			},
			want: 5,
		},
		{
			args: args{
				grid: [][]int{
					{1, 1, -1},
					{1, -1, 1},
					{-1, 1, 1},
				},
			},
			want: 0,
		},
		{
			args: args{
				grid: [][]int{
					{1, 1, 1, 1, 0, 0, 0},
					{0, 0, 0, 1, 0, 0, 0},
					{0, 0, 0, 1, 0, 0, 1},
					{1, 0, 0, 1, 0, 0, 0},
					{0, 0, 0, 1, 0, 0, 0},
					{0, 0, 0, 1, 0, 0, 0},
					{0, 0, 0, 1, 1, 1, 1},
				},
			},
			want: 15,
		},
		{
			args: args{
				grid: [][]int{
					{1, 1, -1, 1, 1},
					{1, 1, 1, 1, 1},
					{-1, 1, 1, -1, -1},
					{0, 1, 1, -1, 0},
					{1, 0, -1, 1, 0},
				},
			},
			want: 0,
		},
		{
			args: args{
				grid: [][]int{
					{1},
				},
			},
			want: 1,
		},
		{
			args: args{
				grid: [][]int{
					{1, 1, 1, 1, -1, -1, -1, 1, 0, 0},
					{1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
					{0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
					{1, 1, 0, 1, 1, 1, 0, -1, 1, 1},
					{0, 0, 0, 0, 1, -1, 0, 0, 1, -1},
					{1, 0, 1, 1, 1, 0, 0, -1, 1, 0},
					{1, 1, 0, 1, 0, 0, 1, 0, 1, -1},
					{1, -1, 0, 1, 0, 0, 0, 1, -1, 1},
					{1, 0, -1, 0, -1, 0, 0, 1, 0, 0},
					{0, 0, -1, 0, 1, 0, 1, 0, 0, 1},
				},
			},
			want: 22,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := cherryPickup2(tt.args.grid); got != tt.want {
				t.Errorf("cherryPickup() = %v, want %v", got, tt.want)
			}
		})
	}
}
