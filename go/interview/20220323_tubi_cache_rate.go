package main

// func main() {
// 	fmt.Printf("Tubi R1 ...\n\n")

// 	file, err := os.Open("/Users/hang.zhang/Downloads/snippet.log.txt")
// 	if err != nil {
// 		log.Fatal(err)
// 	}

// 	// mapMovieHit := map[string]int{}
// 	// mapMovieMiss := map[string]int{}
// 	mapMovie := map[string][]int{}

// 	scanner := bufio.NewScanner(file)
// 	// countHit, countMiss := 0, 0
// 	for scanner.Scan() {
// 		row := scanner.Text()

// 		cols := strings.Split(row, " ")
// 		hom := cols[6]
// 		if hom == "s-port" {
// 			continue
// 		}
// 		url := cols[9]
// 		paths := strings.Split(url, "/")
// 		movieID := ""
// 		if len(paths) >= 2 {
// 			movieID = paths[len(paths)-2]
// 		}

// 		// fmt.Printf("movieID: %s, hit or miss: %s\n", movieID, hom)

// 		if _, ok := mapMovie[movieID]; !ok {
// 			mapMovie[movieID] = []int{0, 0} // [hit, miss]
// 		}

// 		if strings.Contains(hom, "HIT") {
// 			// mapMovieHit[movieID]++
// 			mapMovie[movieID][0]++
// 		} else if strings.Contains(hom, "MISS") {
// 			// mapMovieMiss[movieID]++
// 			mapMovie[movieID][1]++
// 		} else {
// 			fmt.Println("unknown")
// 		}
// 	}

// 	// fmt.Printf("hit = %d, miss = %d\n", countHit, countMiss)
// 	// fmt.Println(mapMovieHit)
// 	// fmt.Println(mapMovieMiss)
// 	fmt.Println(mapMovie)

// 	type Movie struct {
// 		ID   string
// 		Rate float64
// 	}
// 	sliceMovieRate := []Movie{}
// 	for movieID, counts := range mapMovie {
// 		rate := float64(counts[0]) / float64(counts[0]+counts[1])
// 		fmt.Printf("movieID: %s, hit = %d, miss = %d, hitRate: %f\n", movieID, counts[0], counts[1], rate)
// 		sliceMovieRate = append(sliceMovieRate, Movie{ID: movieID, Rate: rate})
// 	}

// 	sort.Slice(sliceMovieRate, func(i, j int) bool {
// 		return sliceMovieRate[i].Rate > sliceMovieRate[j].Rate
// 	})

// 	for _, row := range sliceMovieRate {
// 		fmt.Println(row)
// 	}

// 	fmt.Printf("num of movies: %d\n", len(mapMovie))

// }
