class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i : nums) {
            mp[i]++;
        }
        vector<vector<int>>buckets(nums.size()+1);
        for(auto& [i,count] : mp) {
            buckets[count].push_back(i);
        }
        vector<int>result;
        for(int j = nums.size(); j>=1 && result.size() < k; j--) {
            for(int i : buckets[j]) {
                result.push_back(i);
                if(result.size()==k) break;
            }
        }
        return result;
    }
};