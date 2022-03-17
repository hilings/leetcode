package main

import (
	"context"
	"fmt"
	"sync"
	"time"
)

func goroutine() {
	ctx := context.Background()
	ctx, cancelFn := context.WithTimeout(ctx, 2*time.Second)
	defer cancelFn()

	wg := &sync.WaitGroup{}
	wg.Add(1)
	go f1(ctx, wg)

	fmt.Println("sleep for 5 seconds ...")
	time.Sleep(5 * time.Second)
	// wg.Wait()

}

func f1(ctx context.Context, wg *sync.WaitGroup) {
	for i := 0; i < 5; i++ {
		select {
		case <-ctx.Done():
			fmt.Printf("\tctx timeout\n")
			return
		default:
			fmt.Printf("\trunning ... %d\n", i)
		}
		time.Sleep(1 * time.Second)
	}
	wg.Done()
}

// func main() {
// 	fmt.Printf("test for ctx timeout ...\n\n")

// 	goroutine()
// }
