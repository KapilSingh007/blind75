solution1: brute force
int maxProduct(vector<int>& nums) {
        int res = INT_MIN, temp = 1, n = nums.size();

        for (int i = 0; i < n; i++) {
            temp = 1;
            for (int j = i; j < n; j++) {
                temp = temp * nums[j];
                res = max(res, temp);
            }
        }

        return res;
    }

solution2: better solution
int n = nums.size(), res = nums[0], pre = 1, suf = 1;
        vector<int> prefix(n, 0), suffix(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                pre *= nums[i];
                prefix[i] = pre;
            } else {
                pre = 1;
            }

            if (nums[n - 1 - i] != 0) {
                suf *= nums[n - 1 - i];
                suffix[n - 1 - i] = suf;
            } else {
                suf = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            res = max({res, prefix[i], suffix[n - 1 - i]});

            if (nums[i] <= 0) {
                res = max({res, prefix[i - 1], suffix[n - i]});
            }
    }
        return res;