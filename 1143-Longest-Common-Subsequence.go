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