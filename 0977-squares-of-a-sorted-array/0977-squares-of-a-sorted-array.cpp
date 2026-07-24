class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int siz = nums.size();
        vector<int> negativeArray;
        vector<int> positiveArray;
        for(int i=0; i<siz; i++) {
            if(nums[i] >= 0) {
            positiveArray.push_back (nums[i]);
            }
            else {
                negativeArray.push_back (nums[i]);
            }
        }
        if(negativeArray.size() == 0) {
            for(int i =0; i< siz; i++){
                nums[i] = nums[i] * nums[i];
            }
            return nums;
        }
        if(positiveArray.size() == 0) {
            for(int i=0; i< siz; i++) {
                nums[i]= nums[i] * nums[i];
            }
            reverse(nums.begin() , nums.end());
            return nums;
        }
        
        int i=0,j=0,k=0;
        int m = positiveArray.size();
        int n = negativeArray.size();
        vector<int> sortedArray(n+m);
        for(int i=0; i<n; i++) {
            negativeArray[i] = negativeArray[i] * negativeArray[i];
        }
             reverse(negativeArray.begin(), negativeArray.end());
             for(int i =0; i<m; i++) {
                positiveArray[i] = positiveArray[i] * positiveArray[i];
        }
        //SORTING THE BOTH ARRAY
        while(i<n && j<m) {
        if(negativeArray[i] <= positiveArray[j]) {
            sortedArray[k] = negativeArray[i];
            i++;
            k++;
        }
        else {
            sortedArray[k] = positiveArray[j];
            j++;
            k++;
        }
    }
    while(j<m) {
        sortedArray[k] =  positiveArray[j];
        k++;
        j++;
    }
    while(i<n) {
        sortedArray[k] = negativeArray[i];
        k++;
        i++;
    }
    
    return sortedArray;
    }
};