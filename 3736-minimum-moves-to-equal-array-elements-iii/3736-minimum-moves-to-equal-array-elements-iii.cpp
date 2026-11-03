class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = nums[0];
        long long sum = 0;
        for (int x : nums) {
            max_val = max(max_val, x);
            sum += x;
        }
        return (long long)nums.size() * max_val - sum;
    }
};