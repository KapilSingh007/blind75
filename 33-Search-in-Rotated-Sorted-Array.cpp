int search(vector<int>& nums, int target) {
        int n = nums.size(), i = 0, j = n - 1, mid;

        while (i <= j) {
            mid = (i + j) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[i] <= nums[mid] &&
                (target >= nums[i] && target < nums[mid])) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return -1;
    }