class Solution {
public:
    void solve(vector<int>& cookies, int k, vector<int> distributed, int &ans, int start){

	//base case
	if(start == cookies.size()){
		int maxi = INT_MIN;
		for(int i = 0; i<k; i++){
			maxi = max(maxi, distributed[i]);
		}
		ans = min(ans,maxi);
		return;
	}

	//k options
	for(int i = 0; i<k; i++){
		distributed[i] += cookies[start];
		solve(cookies,k,distributed,ans,start+1);
		distributed[i] -= cookies[start];
		if(distributed[i] == 0) break;
	}
    }	
    int distributeCookies(vector<int>& cookies, int k) {
        

        //sounds like a dp question

        //at every index we have k options find the answer for all options and then rteturn the min
	//
	
	vector<int> distributed(k,0);
	int ans = 0;
	solve(cookies,k,distributed,ans);
	return ans;
    }
};
