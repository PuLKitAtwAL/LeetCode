class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int minimum = INT_MAX;
        for (int x : nums) {
            sum = sum + x;
            minimum = min(minimum, x);
        }
        return sum - nums.size() * minimum;
    }
};