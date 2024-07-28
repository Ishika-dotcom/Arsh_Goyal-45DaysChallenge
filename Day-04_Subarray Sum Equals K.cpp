class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        //Brute forch Approach - O(n^2)

        /*
        int n = nums.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];

                if(sum == k){
                    cnt++;
                }
            }
        }
        return cnt;
        */

        //Optimized Approach - O(n)

        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int preSum = 0;
        int cnt = 0;

        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            int remove = preSum - k;
            cnt += mpp[remove];
            mpp[preSum] += 1;
        }
        return cnt;
    }
};