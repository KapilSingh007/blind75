vector<int> productExceptSelf(vector<int>& nums) {
        // all value
        // all zeero except any one index
        // all zero
        int n = nums.size(), cnt = 0, prod = 1;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0) {
                cnt++;
                if (cnt > 1) {
                    return res;
                }
            } else {
                prod = prod * nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (cnt == 1) {
                if (nums[i] == 0) {
                    res[i] = prod;
                    break;
                }
            } else {
                res[i] = prod / nums[i];
            }
        }

        return res;
    }