class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

       //Brute Force Method

       /* int maxl = 0;
        for(int i=0;i<nums.size();i++){
            int currSum = 0;
            for(int j=i;j<nums.size();j++){
                currSum += nums[j];
                if(currSum % k == 0){
                    maxl++;
                }
            }
        }

        return maxl; */


        //Optimized Approach - using Hashing

        unordered_map<int,int> mpp;
        int ans = 0;
        int sum = 0;
        int rem = 0;
        mpp[rem]++;           // Initializes the map with the remainder 0 having a count of 1. 
                              // This is to handle the case where a subarray itself is divisible by k right from the start.

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            rem = sum % k;
            if(rem<0){         //Adjusts the remainder to handle negative values. If rem is negative, adding k makes it positive.
                rem += k;
            }
            if(mpp.find(rem) != mpp.end()){
                ans += mpp[rem];
            }
            mpp[rem]++;
        }
        return ans;
    }
};