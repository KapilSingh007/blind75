func rob(nums []int) int {
    
    n := len(nums)
    // var res int;
    dp := make([]int, n)

    for i:=range dp{
        dp[i] = -1
    }
    return helper(nums,n, 0,dp)
}

func helper(nums []int, n int, i int, dp []int) int {
    if i >= n {
        // *res = max(*res, sum)
        return 0
    }

    if dp[i] != -1 {
        return dp[i]
    }

    // take 
    take := nums[i] + helper(nums,n, i+2,dp)

    //notTake
    notTake := helper(nums, n, i+1,dp);

    dp[i] =  max(take, notTake);
    return dp[i]
}