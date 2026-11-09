func combinationSum(c []int, t int) [][]int {
	n := len(c)
	var res [][]int = [][]int{}
	var temp []int

	helper(c, t, n, 0, temp, &res)

	return res
}

func helper(c []int, t int, n int, i int, temp []int, res *[][]int) {
	if i == n {
		return
	}
	if t == 0 {
		combination := make([]int, len(temp))
		copy(combination, temp)
		*res = append(*res, combination)
		return
	}

	helper(c, t, n, i+1, temp, res)
	if c[i] <= t {
		temp = append(temp, c[i])
		helper(c, t-c[i], n, i, temp, res)
		temp = temp[:len(temp)-1]
	}

}