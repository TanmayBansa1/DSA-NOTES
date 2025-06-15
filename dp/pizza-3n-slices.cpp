class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        
        //so at every step you loose 3 slices, so you can perform n picks


        //so basically house robbery
        
	    //tabulation
	int n = slices.size();
	vector<vector<int>> dp1(n+1,vector<int> (n/3+1,0));

	vector<vector<int>> dp2(n+1,vector<int> (n/3+1,0));


	for(int i = n-2; i>=0; i--){
		for(int j =1; j<=n/3; j++){
			
			//inc
			int inc =0;
			if(i+2 <= n+1 && j-1 >= 0){
				inc = slices[i]+dp1[i+2][j-1];

			}
			int exc = dp1[i+1][j];

			dp1[i][j] = max(inc, exc);

		}

	} 

	int ans1 = dp1[0][n/3];

	for(int i = n-1; i>=1; i--){
		for(int j =1; j<=n/3; j++){
			
			//inc
			int inc =0;
			if(i+2 <= n+1 && j-1 >= 0){
				inc = slices[i]+dp2[i+2][j-1];

			}
			int exc = dp2[i+1][j];

			dp2[i][j] = max(inc, exc);

		}

	} 

	int ans2 = dp2[0][n/3];

	return max(ans1, ans2);


    }
};
