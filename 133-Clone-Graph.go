/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

func cloneGraph(node *Node) *Node {
	if node == nil {
		return nil
	}

	var mp map[*Node]*Node = map[*Node]*Node{}

	q := []*Node{}
	q = append(q, node)

	res := &Node{Val: node.Val}
	mp[node] = res
	var currNode *Node

	for len(q) > 0 {
		currNode = q[0]
		q = q[1:]

		cloneNode, exist := mp[currNode]

		if !exist {
			cloneNode = &Node{Val: currNode.Val}
			mp[currNode] = cloneNode
		}

		for _, neighbour := range currNode.Neighbors {
			cloneNeighbour, exist := mp[neighbour]
			if !exist {
				q = append(q, neighbour)
				cloneNeighbour = &Node{Val: neighbour.Val}
				mp[neighbour] = cloneNeighbour
			}

			cloneNode.Neighbors = append(cloneNode.Neighbors, cloneNeighbour)
		}
	}

	return res
}