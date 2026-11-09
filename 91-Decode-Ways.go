// recursion and memoization
func numDecodings(s string) int {
	n := len(s)
	dp := make([]int, n)

	for i := range dp {
		dp[i] = -1
	}
	return helper(s, n, 0, dp)
}

func helper(s string, n int, i int, dp []int) int {

	if i >= n {
		return 1
	}

	if s[i] == '0' {
		return 0
	}

	if dp[i] != -1 {
		return dp[i]
	}

	var res2 int
	res1 := helper(s, n, i+1, dp)

	if (i+1 < n) && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
		res2 = helper(s, n, i+2, dp)
	}

	dp[i] = res1 + res2
	return dp[i]

}

// bottom up
func numDecodings(s string) int {
	n := len(s)
	dp := make([]int, n+1)

	dp[n] = 1

	for i := n - 1; i >= 0; i-- {
		if s[i] == '0' {
			dp[i] = 0
		} else {
			dp[i] = dp[i+1]
			if i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
				dp[i] += dp[i+2]
			}
		}
	}
	return dp[0]
}