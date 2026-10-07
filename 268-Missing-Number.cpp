int findUsingSort(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return n;
    }

    int findUsingSet(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (st.find(i) == st.end()) {
                return i;
            }
        }

        return n;
    }
    int missingNumber(vector<int>& nums) {
        return findUsingSort(nums);
        // return findUsingSet(nums);
        
    }