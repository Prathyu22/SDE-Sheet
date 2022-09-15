//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0

/*int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    /* 
    //DYNAMIC PROGRAMMING WITH TC = O(N) AND SC = O(N).
    vector<int> dp(n, -1);
    int fs, ss = 1001;
    dp[0] = 0;
    for(int i=1; i<=n-1; i++){
        fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        if(i > 1)
            ss = dp[i-2] + abs(heights[i] - heights[i-2]);
       dp[i] = min(fs, ss);
    }
    return dp[n-1]; */
    
    // DP with TC = O(N) and SC = O(1)
    
    /*
    int prev1 = 0;
    int prev2 = 0;
    int fs, ss = 1001;
    for(int i=1; i<=n-1; i++){
        fs = prev1 + abs(heights[i] - heights[i-1]);
        if(i > 1)
            ss = prev2 + abs(heights[i] - heights[i-2]);
        int curr = min(fs, ss);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
} 
*/