func canJump(nums []int) bool {
	n := len(nums)

	dp := make([]bool, n)
	dp[n-1] = true
	for i := n - 2; i >= 0; i-- {
		for j := 0; j <= nums[i]; j++ {
			if i+j == n-1 || dp[i+j] {
				dp[i] = true
				break
			}
		}
	}

	return dp[0]
}