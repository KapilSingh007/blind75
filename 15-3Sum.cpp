method1: brute force but little better version
vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> mp;
        set<vector<int>> res;

        for (int i = 0; i <= n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            mp.clear();
            mp[nums[i + 1]] = i + 1;
            for (int j = i + 2; j < n; j++) {
                if (mp.find(-nums[i] - nums[j]) != mp.end()) {
                    res.insert({-nums[i] - nums[j], nums[j], nums[i]});
                }

                mp[nums[j]] = j;
            }
        }
        vector<vector<int>> st(res.begin(), res.end());
        return st;
    }