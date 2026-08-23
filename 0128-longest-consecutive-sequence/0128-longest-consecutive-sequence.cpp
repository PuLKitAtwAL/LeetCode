class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin(), nums.end());
        int res = INT_MIN;
        for(auto n : numSet) {
            if(numSet.find(n - 1) == numSet.end()){
        int len = 1;
        while(numSet.find(n + len) != numSet.end()) {
            len++;
        }
        res = max(res, len);
        }
    }
    if(res == INT_MIN) {
        return 0;
    }
    return res;
    }
};