class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minEnding = nums[0];
        int maxEnding = nums[0];
        int ans = nums[0];

        for ( int i = 1; i < nums.size(); i++) {
            int v1 = nums[i];
            int v2 = minEnding * nums[i];
            int v3 = maxEnding * nums[i];

            minEnding = min(v1, min(v2, v3));
            maxEnding = max(v1, max(v2, v3));
            ans = max(ans, max(minEnding, maxEnding));
        }
        return ans;
    }
};