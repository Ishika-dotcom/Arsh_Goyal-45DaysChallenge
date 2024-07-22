class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       vector<pair<int, int>> num_pairs;
        for (int i = 0; i < nums.size(); ++i) {
            num_pairs.push_back({nums[i], i});
        }

        // Sort the vector based on the values
        sort(num_pairs.begin(), num_pairs.end());

        // Use two pointers to find the target sum
        int l = 0;
        int r = num_pairs.size() - 1;

        while (l < r) {
            int sum = num_pairs[l].first + num_pairs[r].first;
            if (sum == target) {
                // Return the original indices
                return {num_pairs[l].second, num_pairs[r].second};
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }

        // Return an empty vector if no solution is found
        return {};
    }
};


//Use hashing for O(n) TC