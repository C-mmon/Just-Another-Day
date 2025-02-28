class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        
        // DP table where dp[i][j] stores the length of LCS of str1[0...i-1] and str2[0...j-1]
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        // Compute the length of the Longest Common Subsequence (LCS)
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1[i - 1] == str2[j - 1]) {  
                    dp[i][j] = 1 + dp[i - 1][j - 1];  // Matching characters contribute to LCS
                } else {  
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Take the maximum LCS so far
                }
            }
        }

        // Construct the Shortest Common Supersequence (SCS) using backtracking
        int i = len1, j = len2;
        string supersequence;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {  // If characters match, include them in result
                supersequence.push_back(str1[i - 1]);
                i--;
                j--;
            } 
            else if (dp[i - 1][j] >= dp[i][j - 1]) {  
                // If moving up maintains LCS length, include str1[i-1] in the result
                supersequence.push_back(str1[i - 1]);
                i--;
            } 
            else {  
                // Otherwise, moving left is better, so include str2[j-1]
                supersequence.push_back(str2[j - 1]);
                j--;
            }
        }

        // Append any remaining characters from str1 or str2
        while (i > 0) {
            supersequence.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            supersequence.push_back(str2[j - 1]);
            j--;
        }

        // Reverse the string since we built it backwards
        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }
};
