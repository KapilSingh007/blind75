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

    