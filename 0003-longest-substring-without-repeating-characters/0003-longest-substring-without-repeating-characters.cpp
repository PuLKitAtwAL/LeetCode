class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int res = INT_MIN;
        unordered_map<char,int>f;
        for(int high = 0; high < s.size(); high++) {
            f[s[high]]++;
            int len = high - low + 1;
            while(f.size() < len) {
                f[s[low]]--;
                if(f[s[low]] == 0) {
                    f.erase(s[low]);
                }
                low++;
                len = high - low + 1;
            }
            len = high - low + 1;
            res = max(res , len);
        }
        if(res==INT_MIN){
            return 0;
        }
        return res;
    }
};