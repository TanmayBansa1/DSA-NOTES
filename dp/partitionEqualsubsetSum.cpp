class Solution {
public:

    bool solve(vector<int> &nums, int index, int n, vector<int> path1, vector<int> path2){

	//base case
	if(index >= n){
		return checkSum(path1, path2);
	}
		//3d dp jaa ri hai so no
		//can do bitmasking but no
		//[O

	//inc
	bool inc = solve(nums, index+1, n,path1+nums[index], path2-nums[index]);

	//exc
	
	bool exc = solve(nums, index+1, n, path1, path2);

	return inc || exc;

    }
    bool optimal(vector<int> &nums){
	int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int n : nums) {
            for (int i = target; i >= n; i--) {
                if (dp[i]) continue;
                if (dp[i - n]) dp[i] = true;
                if (dp[target]) return true;
            }
        }

        return false; 


    }
    bool canPartition(vector<int>& nums) {
 	//can useinclude exclude with 2 sets
	//basically include 1 element, addit to set 1 and the remaining in set 2
	//check sum 1 & 2, if equal return 1 else return 0
	//
	int sum = 0;
	for(auto x:nums){
		sum += x;
	}
	return solve(nums, 0, nums.size(), 0,sum );
    }
};
