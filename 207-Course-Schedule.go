func canFinish(n int, prerequisites [][]int) bool {
	adj := make([][]int, n)
	courseCompletion := make([]int, n)

	for i := range prerequisites {
		adj[prerequisites[i][0]] = append(adj[prerequisites[i][0]], prerequisites[i][1])
	}

	for i := 0; i < n; i++ {
		if courseCompletion[i] == 0 && !helper(i, adj, courseCompletion) {
			return false

		}
	}

	return true

}

func helper(value int, adj [][]int, courseCompletion []int) bool {

	courseCompletion[value] = 1
	for _, neighbour := range adj[value] {
		if (courseCompletion[neighbour] == 1) || (courseCompletion[neighbour] == 0 && !helper(neighbour, adj, courseCompletion)) {
			return false
		}
	}
	courseCompletion[value] = 2
	return true
}