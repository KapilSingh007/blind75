// Solution 1 :

bool helper(string& s, int& n, int i, unordered_set<string> st,
                vector<int>& dp) {
        if (dp[i] != -1) {
            return dp[i];
        }
        if (st.find(s.substr(i)) != st.end()) {
            return dp[i] = true;
        }
        bool found = false;
        int j = 0;
        while (i + j < n) {
            string word1 = s.substr(i, j + 1);

            if (st.find(word1) != st.end()) {
                found = found || helper(s, n, i + j + 1, st, dp);
            }
            j++;
        }

        return dp[i] = found;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);
        return helper(s, n, 0, st, dp);
    }