// recursion and memo
func lengthOfLIS(nums []int) int {
	n := len(nums)
	last := -1

	dp := make([][]int, n+1)

	for i := range dp {
		dp[i] = make([]int, n+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	return helper(nums, n, 0, last, dp)
}
func helper(nums []int, n int, i int, last int, dp [][]int) int {

	if i == n {
		return 0
	}

	if dp[i+1][last+1] != -1 {
		return dp[i+1][last+1]
	}
	var res1 int
	var res2 int
	res1 = helper(nums, n, i+1, last, dp)
	if last == -1 || nums[i] > nums[last] {
		res2 = 1 + helper(nums, n, i+1, i, dp)
	}
	dp[i+1][last+1] = max(res1, res2)
	// return max(res1, res2)
	return dp[i+1][last+1]
}