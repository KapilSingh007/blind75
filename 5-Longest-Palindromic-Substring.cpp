// solution 1: optimized solution
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