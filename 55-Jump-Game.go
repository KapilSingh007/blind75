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

// recursion and dp

// func canJump(nums []int) bool {
// 	n := len(nums)

// 	dp := make([]bool, n)
//     dp[n-1] = true
// 	for i := n - 2; i >= 0; i-- {
// 		for j := 0; j <= nums[i]; j++ {
// 			if i+j == n-1 || dp[i+j] {
// 				dp[i] = true
//                 break
// 			}
// 		}
// 	}

//     return dp[0]
// }

func canJump(nums []int) bool {
	n := len(nums)

	dp := make([]int, n)

	for i := range dp {
		dp[i] = -1
	}
	return helper(nums, n, 0, dp)
}

func helper(nums []int, n int, i int, dp []int) bool {
	if i >= n-1 {
		return true
	}

	if dp[i] != -1 {
		return dp[i] == 1
	}

	dp[i] = 0
	for j := nums[i]; j > 0; j-- {
		if helper(nums, n, i+j, dp) {
			dp[i] = 1
			// return true
			break
		}
	}

	return dp[i] == 1
	// return false
}