package main

type MyListNode struct {
	Key  int
	Val  int
	Prev *MyListNode
	Next *MyListNode
}

type LRUCache struct {
	Cap  int
	Mem  map[int]*MyListNode
	Head *MyListNode // newest
	Tail *MyListNode // oldest
}

func Constructor(capacity int) LRUCache {
	cache := LRUCache{
		Cap:  capacity,
		Mem:  map[int]*MyListNode{},
		Head: &MyListNode{},
		Tail: &MyListNode{},
	}
	cache.Head.Next = cache.Tail
	cache.Tail.Prev = cache.Head
	return cache
}

func (this *LRUCache) Get(key int) int {
	cur, ok := this.Mem[key]
	if !ok {
		return -1
	}

	// unlink from current position
	cur.Prev.Next = cur.Next
	cur.Next.Prev = cur.Prev

	// insert at head
	this.Head.Next.Prev = cur
	cur.Next = this.Head.Next
	this.Head.Next = cur
	cur.Prev = this.Head

	return cur.Val
}

func (this *LRUCache) Put(key int, value int) {
	cur, ok := this.Mem[key]
	if !ok && len(this.Mem) == this.Cap {
		cur = this.Tail.Prev
		delete(this.Mem, cur.Key) // evict from map
	}

	if cur != nil { // evict from link
		cur.Prev.Next = cur.Next
		cur.Next.Prev = cur.Prev
	}

	cur = &MyListNode{
		Key: key,
		Val: value,
	}
	this.Mem[key] = cur

	// insert at head
	this.Head.Next.Prev = cur
	cur.Next = this.Head.Next
	this.Head.Next = cur
	cur.Prev = this.Head
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

// func main() {
// 	fmt.Printf("LeetCode 146. LRU Cache ...\n\n")

// 	cache := Constructor(2)
// 	cache.Put(1, 1)
// 	cache.Put(2, 2)
// 	fmt.Println(cache.Get(1))
// 	cache.Put(3, 3)
// 	fmt.Println(cache.Get(2))
// 	cache.Put(4, 4)
// 	fmt.Println(cache.Get(1))
// 	fmt.Println(cache.Get(3))
// 	fmt.Println(cache.Get(4))
// }
