#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int i, int n, int prev){
        //base case
        if(i >= n){
            return 0;
        }
        int inc = 0;
        if(nums[i] > prev){
            inc = 1 + solve(nums, i+1, n, nums[i]);
        }
        int exc = solve(nums, i+1, n, prev);

        return max(inc, exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        //include / exclude
        // return solve(nums, 0, nums.size(), INT_MIN);


        //trying
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i = 1; i<nums.size(); i++){

            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int lowerBound = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[lowerBound] = nums[i];

            }
        }

        return ans.size();
    }
};