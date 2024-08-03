class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for(int i = nums.size() - 2;i >= 0;i--){
            if(i + nums[i] >= goal){              //currpos + maximum jump >= goal
                goal = i;
            }
        }

        return goal == 0;           //checks if true or not
    }
};

// TC - O(n)