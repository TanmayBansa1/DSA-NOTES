class Solution{
	public:
	int solve(vector<int> &a, int k){

		int mini = INT_MAX;
		int i =0;
		int j = k-1;

		while(j < a.size()){
			mini = min(mini,a[j]-a[i]);
			i++;
			j++;
		}

		return mini;
	}

}
