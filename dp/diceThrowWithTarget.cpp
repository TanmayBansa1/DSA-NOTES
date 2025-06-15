class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
	
	 //base cases are a lot per say
	if(target == 0 && n == 0) return 1;
	 if(target <= 0) return 0;

	 if(n == 0) return 0;
	int ans = 0;
	 for(int i = 1; i<=k; i++){
		
//		 ans += numRollsToTarget(n-1,k,target -i);

	 }

//	 return ans;

	 //tabulation
	 vector<vector<int>> dp(n+1, vector<int> (target+1, 0));

	 dp[0][0] = 1;

	 for(int i =1; i<=n; i++){
		for(int j = 0; j<=target; j++){
			
			int ans =0;
			for(int l = 1; l<= k; l++){
				ans += dp[i-1][j-i];
			}
			dp[i][j] = ans;
		}
	 }

	 return dp[n][k];
    }
}
