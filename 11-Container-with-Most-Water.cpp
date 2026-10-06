// Solution 1 : brute force (it will thorw time limit exceed)

int maxArea(vector<int>& height) {
int n = height.size(), res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, min(height[i], height[j]) * (j - i));
            }
        }

        return res;
    }

// solution 2: optimized solution
int maxArea(vector<int>& height) {

        int n = height.size(), res = 0, i = 0, j = n - 1;

        while (i < j) {
            res = max(res, min(height[j], height[i]) * (j - i));

            height[i] < height[j] ? i++ : j--;
        }
        return res;
    }