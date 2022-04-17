package main

func asteroidCollision(asteroids []int) []int {
	r := []int{}
	for _, a := range asteroids {
		if len(r) == 0 || r[len(r)-1] < 0 || a > 0 {
			r = append(r, a)
			continue
		}

		// r[-1] > 0, a < 0, collide
		for len(r) > 0 && r[len(r)-1] > 0 {
			if r[len(r)-1] > -a { // negative explode
				a = 0
				break
			}
			if r[len(r)-1] == -a { // both explode
				r = r[:len(r)-1]
				a = 0
				break
			}

			r = r[:len(r)-1] // positive explode
		}
		if a < 0 {
			r = append(r, a)
		}
	}
	return r
}

// func main() {
// 	fmt.Printf("LeetCode 735. Asteroid Collision ...\n\n")

// 	asteroids := []int{
// 		// 5, 10, -5, // 5,10
// 		8, -8, //
// 		-1, 10, 2, -5, // 10
// 	}

// 	r := asteroidCollision(asteroids)
// 	fmt.Println(r)

// }
