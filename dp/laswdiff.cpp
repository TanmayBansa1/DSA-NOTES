class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        //same question but fixed difference
        int n = arr.size();
        vector<int> dp(n+1, 2);
        int ans = 2;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){

                if(arr[i] - arr[j] == difference){
                    dp[i] = dp[j]+1;
                }
                ans = max(ans, dp[i]);
            }
        }

        return ans-1;
    }
};
