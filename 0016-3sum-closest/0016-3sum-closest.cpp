class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        int resS = 0;
        for (int i =0; i<nums.size()-2; i++) {
            if(i>0 && nums[i] == nums [i-1])
            continue;
            int left = i+1;
            int right = nums.size()-1;

            while( left < right ) {
                int s =  nums[i] + nums[left] + nums[right] ;
                int diff = abs(s - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    resS = s;
                }

                if(s == target)
                return s;
                else if(s < target)
                left ++;
                else
                right --;
            }
        }
        return resS;
    }
};