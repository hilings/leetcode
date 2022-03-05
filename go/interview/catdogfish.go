package main

import (
	"fmt"
	"sync"
)

func catdogfish() {

	chCat := make(chan struct{}, 1)
	chCat <- struct{}{}
	chDog := make(chan struct{})
	chFish := make(chan struct{})

	wg := &sync.WaitGroup{}
	wg.Add(3)

	go cat(chCat, chDog, wg)
	go dog(chDog, chFish, wg)
	go fish(chFish, chCat, wg)

	wg.Wait()

	return
}

func cat(ch chan struct{}, chnext chan struct{}, wg *sync.WaitGroup) {
	fmt.Println("cat start")
	for i := 0; i < 10; i++ {
		<-ch
		fmt.Printf("%d\tcat\n", i)
		chnext <- struct{}{}
	}
	wg.Done()
	return
}

func dog(ch chan struct{}, chnext chan struct{}, wg *sync.WaitGroup) {
	fmt.Println("dog start")
	for i := 0; i < 10; i++ {
		<-ch
		fmt.Printf("%d\t\tdog\n", i)
		chnext <- struct{}{}
	}
	wg.Done()
	return
}

func fish(ch chan struct{}, chnext chan struct{}, wg *sync.WaitGroup) {
	fmt.Println("fish start")
	for i := 0; i < 10; i++ {
		<-ch
		fmt.Printf("%d\t\t\tfish\n", i)
		chnext <- struct{}{}
	}
	wg.Done()
	return
}

// func main() {
// 	fmt.Printf("cat dog fish ...\n\n")

// 	catdogfish()

// }
