// bottom up approach
func longestCommonSubsequence(text1 string, text2 string) int {

	n := len(text1)
	m := len(text2)

	dp := make([][]int, m+1)

	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for i := 0; i <= n; i++ {
		dp[0][i] = 0
	}

	for i := 0; i <= m; i++ {
		dp[i][0] = 0
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if text1[j-1] == text2[i-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}

	return dp[m][n]
}

// recursion and memorization
func longestCommonSubsequence(text1 string, text2 string) int {

	n := len(text1)
	m := len(text2)

	dp := make([][]int, m)

	for i := range dp {
		dp[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = -1
		}

	}
	return helper(text1, text2, 0, 0, n, m, dp)
}

func helper(text1 string, text2 string, i int, j int, n int, m int, dp [][]int) int {
	if i == m || j == n {
		return 0
	}

	if dp[i][j] != -1 {
		return dp[i][j]
	}

	if text1[j] == text2[i] {
		dp[i][j] = 1 + helper(text1, text2, i+1, j+1, n, m, dp)
		return dp[i][j]
	}

	dp[i][j] = max(helper(text1, text2, i+1, j, n, m, dp), helper(text1, text2, i, j+1, n, m, dp))
	return dp[i][j]
}