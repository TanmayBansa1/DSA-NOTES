class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        //another include exclude question but not
        //what we have to do is check each diff in the dp map, if it exists, overwrite if it doesnt user min ma logic

        //creating the dp array
        int n = nums.size();
        vector<unordered_map<int,int>> dp(nums.size()+1, 0);
        int maxo = 2;
        for(int i = 0; i<n; i++){
 		for(int j = 0; j<i; j++){
			
			int diff = nums[i] - nums[j];
			if(dp[j].count(diff)){
				dp[i][diff] = 1 + dp[j][diff];
			}else{
				dp[i][diff] = 2;
			}
			maxo= max(maxo, dp[i][diff]);
		}           
        }

	return maxo;

    }
};
