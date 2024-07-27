class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();

        for(int i=0;i<size;i++){
            while(nums[i] != nums[nums[i] - 1]){
                swap(nums[i],nums[nums[i] - 1]);
            }
        }

        vector<int> duplicates;

        for(int i=0;i<size;i++){
            if(nums[i] != i+1){
                duplicates.push_back(nums[i]);
            }
        }
        return duplicates;
    }
};