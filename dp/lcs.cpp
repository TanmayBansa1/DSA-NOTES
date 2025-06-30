class Solution {
public:
    int solve(string text1, string text2, int i, int j) {

        // base case

        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }

        // case 1

        if (text1[i] == text2[i]) {

            return 1 + solve(text1, text2, i + 1, j + 1);
        }

        return max(solve(text1, text2, i + 1, j),
                   solve(text1, text2, i, j + 1));
    }
    int longestCommonSubsequence(string text1, string text2) {

        // well sounds easy
        //

        // return solve(text1, text2, 0);

        // tabulation
        //
        //

        vector<int> next(text2.size() + 1, 0);

        vector<int> curr(text2.size() + 1, 0);

        for (int i = text1.size() - 1; i >= 0; i--) {

            for (int j = text2.size() - 1; j >= 0; j--) {

                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }

            next = curr;
        }

        return next[0];
    }
}
;

