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


    // method2: optimized

    void twoSum(int target, vector<int>& nums, int n, int index,
                vector<vector<int>>& res) {

        int i = index, j = n - 1;
        while (i < j) {
            if (nums[i] + nums[j] == target) {

                while (i < j && nums[i] == nums[i + 1]) {
                    i++;
                }

                while (i < j && nums[j] == nums[j - 1]) {
                    j--;
                }
                res.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            } else if (nums[i] + nums[j] > target) {
                j--;
            } else {
                i++;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        // nums[i] + nums[j] + nums[k] = 0;
        // nums[j] + nums[j] = -nums[i]
        for (int i = 0; i <= n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            twoSum(-nums[i], nums, n, i + 1, res);
        }

        return res;
    }