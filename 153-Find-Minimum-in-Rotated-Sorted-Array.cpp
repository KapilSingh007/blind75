int findMin(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1, mid;

        while (i <= j) {
            mid = (i + j) / 2;

            if (nums[i] <= nums[j]) {
                return nums[i];
            }

            if (nums[mid] > nums[j]) {
                i = mid+1;
            } else {
                j = mid;
            }
        }

        return 0;
    }