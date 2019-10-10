class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<vector<int>> ans;
        while (i < n-1) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int tempsum = nums[i] + nums[l] + nums[r];
                if (tempsum < 0) {
                    l++;
                } else if (tempsum > 0) {
                    r--;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r and nums[l] == nums[l+1]) {
                        l++;
                    }
                    while (l < r and nums[r] == nums[r-1]) {
                        r--;
                    }
                    l++;
                    r--;
                }
            }
            while (i < n-1 and nums[i] == nums[i+1]) {
                i++;
            }
            i++;
        }
        return ans;
    }
};