class Solution {
public:
    int solveTab(vector<vector<int>>& cuboids){
	
	    //create a dp array of n+1 * n+1
	    //but we could replace that with a curr and prev setup
	    //
	    int n = cuboids.size();
	    vector<int> curr(n, 0);
	   
	    vector<int> next(n, 0);

	    for(int i = n-1; i>=0; i--){
		
		    for(int j = i-1; j>=-1; j--){

			//incl
			int inc = 0;
			if(j == -1 || (cuboids[i][2] >= cuboids[j][2] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][0] >=cuboids[j][0])){
				inc = cuboids[i][2] + next[i+1];

			}

			int exc = next[j];

			curr[j+1] = max(exc, inc);

		    }

		    next = curr;


	    }
	    return next[0];

    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //


        //quite basic actually not that hard
        //sort all individual boxes
        for(auto x:cuboids){
            sort(x.begin(), x.end());
        }

        //sort the cuboids table according to the first dimension, consider it width and the last dimension as height

        sort(cuboids.begin(), cuboids.end());

        //now just apply LIS to height
	return solveTab(cuboids);
	
	
    }
};
