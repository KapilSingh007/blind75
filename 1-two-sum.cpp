// Solution 1 : better solution

vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }

        return {};
}


// solution 2: optimized soltion
vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[nums[0]];
        for (int i = 1; i < n; i++) {
            if(mp.find(target - nums[i]) != mp.end()){
                return {mp[target - nums[i]],i};
            }
            mp[nums[i]] = i;
        }

        return {};
}