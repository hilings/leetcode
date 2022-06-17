package main

// [08:01] Biplab Patra
//     You have n processes forming a rooted tree structure. You are given two integer arrays pid and ppid, where pid[i] is the ID of the ith process and ppid[i] is the ID of the ith process's parent process.
// Each process has only one parent process but may have multiple children processes. Only one process has ppid[i] = 0, which means this process has no parent process (the root of the tree).
// When a process is killed, all of its children processes will also be killed.
// Given an integer kill representing the ID of a process you want to kill, return a list of the IDs of the processes that will be killed. You may return the answer in any order.

// func main() {
// 	fmt.Printf("delete subtree, with Microsoft R2 ...\n\n")

// 	pid := []int{1, 3, 10, 5}
// 	ppid := []int{3, 0, 5, 3}
// 	kill := 3

// 	r := killProcess(pid, ppid, kill)
// 	fmt.Println(r)
// }

func killProcess(pid []int, ppid []int, kill int) []int {
	mapChildren := map[int][]int{}
	for i := 0; i < len(pid); i++ {
		child, parent := pid[i], ppid[i]
		if _, ok := mapChildren[parent]; !ok {
			mapChildren[parent] = []int{}
		}
		mapChildren[parent] = append(mapChildren[parent], child)
	}

	res := []int{}
	q := []int{kill}
	for i := 0; i < len(q); i++ {
		cur := q[i]
		res = append(res, cur)
		q = append(q, mapChildren[cur]...)
	}

	return res
}

/*

old DB -> new DB

assuming both SQL

snapshot of old DB, at some timepoint t0

record AOF append of file t0 ~ t1

import snapshot into new DB  t1

replay AOF to new DB until there is no gap between old and new DB

after replaying AOF is done, then new DB is "ready"

when new DB is ready

on APP side, start double write

*/
