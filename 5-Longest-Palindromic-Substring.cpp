// Solution 1 : better solution
bool checkPalindrom(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }

        return true;
    }
    string longestPalindrome(string s) {

        int n = s.size();
        string res, temp;

        for (int i = 0; i < n; i++) {
            temp = s[i];
            for (int j = i + 1; j < n; j++) {
                if (checkPalindrom(s, i, j) && temp.size() < j - i + 1) {
                    temp = s.substr(i, j - i + 1);
                }
            }

            if (res.size() < temp.size()) {
                res = temp;
            }
        }

        return res;
    }


// solution 1: optimized solution
    bool checkPalindromRecursive(string& s, int i, int j,
                                 vector<vector<int>>& dp) {

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if (i >= j) {
            return dp[i][j] = true;
        }

        if (s[i] != s[j]) {
            return dp[i][j] = false;
        }

        return dp[i][j] = checkPalindromRecursive(s, ++i, --j, dp);
    }

    string longestPalindrome(string s) {

        int n = s.size();
        string res = "", temp;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            temp = s[i];
            for (int j = i; j < n; j++) {
                if (checkPalindromRecursive(s, i, j, dp) &&
                    temp.size() < j - i + 1) {
                    temp = s.substr(i, j - i + 1);
                }
            }

            if (res.size() < temp.size()) {
                res = temp;
            }
        }

        return res;
    }