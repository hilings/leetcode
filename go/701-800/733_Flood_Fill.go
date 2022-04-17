package main

func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	if len(image) == 0 || len(image[0]) == 0 {
		return image
	}

	visited := map[int]bool{}
	dfs(image, sr, sc, image[sr][sc], newColor, visited)

	return image
}

func dfs(image [][]int, i int, j int, originalColor int, newColor int, visited map[int]bool) {
	m, n := len(image), len(image[0])
	if i < 0 || i >= m || j < 0 || j >= n || visited[i*n+j] || image[i][j] != originalColor {
		return
	}

	image[i][j] = newColor
	visited[i*n+j] = true

	d := [][]int{
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1},
	}
	for _, dd := range d {
		dfs(image, i+dd[0], j+dd[1], originalColor, newColor, visited)
	}
}

func floodFill2(image [][]int, sr int, sc int, newColor int) [][]int {
	if len(image) == 0 || len(image[0]) == 0 {
		return image
	}

	m, n := len(image), len(image[0])
	originalColor := image[sr][sc]

	visited := map[int]bool{}
	q := [][]int{{sr, sc}}
	for cur := 0; cur < len(q); cur++ {
		i, j := q[cur][0], q[cur][1]
		visited[i*n+j] = true
		image[i][j] = newColor

		d := [][]int{
			{-1, 0},
			{1, 0},
			{0, -1},
			{0, 1},
		}
		for _, dd := range d {
			ii, jj := i+dd[0], j+dd[1]
			if ii < 0 || ii >= m || jj < 0 || jj >= n || visited[ii*n+jj] || image[ii][jj] != originalColor {
				continue
			}
			q = append(q, []int{ii, jj})
		}
	}

	return image
}

// func main() {
// 	fmt.Println("LeetCode 733. Flood Fill, Go ...")

// 	image := [][]int{
// 		{1, 1, 1},
// 		{1, 1, 0},
// 		{1, 0, 1},
// 	}
// 	sr := 1
// 	sc := 1
// 	newColor := 2

// 	r := floodFill(image, sr, sc, newColor)

// 	for _, l := range r {
// 		for _, v := range l {
// 			fmt.Printf("%d ", v)
// 		}
// 		fmt.Println()
// 	}

// }
