
// solution 1: optimized solution
int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0, j = 0, res = 0;

        unordered_map<char, int> mp;

        while (i < n) {
            mp[s[i]]++;

            while (mp[s[i]] > 1) {
                mp[s[j++]]--;
            }

            res = max(res, i - j + 1);
            i++;
        }

        return res;
    }