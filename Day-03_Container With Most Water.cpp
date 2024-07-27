class Solution {
public:
    int maxArea(vector<int>& height) {
        //Brute Force Approach - O(n^2)

       /* int mx = INT_MIN;

        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                int water = (j-i) * min(height[i],height[j]);
                mx = max(mx,water);
            }
        }

        return mx;
        */

        

        //Optimized Approach - O(n)

        int start = 0;
        int end = height.size()-1;
        int area;
        int maxarea = 0;

        while(start < end){
            area = min(height[start],height[end]) * (end-start);
            if(area > maxarea){
                maxarea = area;
            }

            if(min(height[start],height[end]) == height[start]){
                start++;
            }
            else{
                end--;
            }
        }
        return maxarea;
        
    }
};