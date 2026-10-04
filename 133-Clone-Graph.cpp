// Solution 1 :

Node* cloneGraph(Node* node) {

        if(!node){
            return nullptr;
        }
        queue<Node*> q;
        unordered_map<int,Node*> mp;
        unordered_map<int, unordered_set<int>> st;
        Node *curr, *ptr;
        q.push(node);

        while (!q.empty()) {
            curr = q.front();
            q.pop();

            if (mp.find(curr->val) == mp.end()) {
                Node* newNode = new Node(curr->val);
                mp[newNode->val] = newNode;
            }

            for (Node* it : curr->neighbors) {

                if (mp.find(it->val) == mp.end()) {
                    Node* newNode = new Node(it->val);
                    mp[newNode->val] = newNode;
                    q.push(it);
                }

                if (st.find(curr->val) == st.end() ||
                    st[curr->val].find(it->val) == st[curr->val].end())
                    mp[curr->val]->neighbors.push_back(mp[it->val]);
                    st[curr->val].insert(it->val);
            }
        }

        return mp[node->val];
    }