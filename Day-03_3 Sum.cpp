class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //Brute force Approach - Use Three loops and set (for Unique elements)

        //Optimized Approach - O(n^2 logn)
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        int l,r;

        for(int i=0;i<nums.size()-2;i++){
            l = i+1;
            r = nums.size()-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    st.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[i] + nums[l] + nums[r] > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        for(auto triplets : st)
            ans.push_back(triplets);
        return ans;
    }
};