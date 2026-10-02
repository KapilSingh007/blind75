// Solution 1 : better solution

int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        sort(nums.begin(), nums.end());

        int res = 0, i = 1, temp = 1;

        while (i < n) {
            if (nums[i] == nums[i - 1] + 1) {
                temp++;
            } else if (nums[i] != nums[i - 1]) {
                res = max(res, temp);
                temp = 1;
            }
            i++;
        }

        res = max(res, temp);

        return res;
}


// solution 2: optimized soltion

int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }

        unordered_set<int> mp(nums.begin(),nums.end());
        int res = 1, temp = 1;

        for (int i : mp) {
            if (mp.find(i - 1) == mp.end()) {
                temp = 1;
                int j = i + 1;
                while (mp.find(j) != mp.end()) {
                    temp++;
                    j++;
                }
                res = max(res, temp);
            }
        }

        return res;
    }