class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //Brute Force Approach - O(n^2)
        
        /* vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}*/

        //Better Approach - Using Hashing - O(n), SC - O(n)

        /*
            vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}*/

        //Optimal Approach - Using two pointer - O(n) + O(n*logn), SC- O(1)

        /*
            string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}*/

        //TC - O(n*logn)
        
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


