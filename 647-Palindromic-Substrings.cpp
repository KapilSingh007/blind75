// Solution 1 :

bool checkPalindrom(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) {
            return dp[i][j] = true;
        }

        return dp[i][j] = s[i] == s[j] && checkPalindrom(s, i + 1, j - 1, dp);
    }
    int countSubstrings(string s) {

        int n = s.size(), count = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkPalindrom(s, i, j, dp)) {
                    count++;
                }
            }
        }

        return count;
}