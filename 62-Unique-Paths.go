func uniquePaths(m int, n int) int {
	dp := make([][]int, m)

	for i := range dp {
		dp[i] = make([]int, n)
		dp[i][0] = 1
	}

	for i := range dp[0] {
		dp[0][i] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			dp[i][j] = dp[i-1][j] + dp[i][j-1]
		}
	}
	return dp[m-1][n-1]
}

// recursion and dp
func uniquePaths(m int, n int) int {
	dp := make([][]int, m)

	for i := range dp {
		dp[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	return helper(m, n, 0, 0, &dp)

}

func helper(m int, n int, i int, j int, dp *[][]int) int {
	if i == m-1 || j == n-1 {
		return 1
	}

	if (*dp)[i][j] != -1 {
		return (*dp)[i][j]
	}
	// right
	var right int

	if j+1 < n {
		right = helper(m, n, i, j+1, dp)
	}

	// down
	var down int
	if i+1 < m {
		down = helper(m, n, i+1, j, dp)
	}

	(*dp)[i][j] = down + right
	return (*dp)[i][j]

}