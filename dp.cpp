//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

#include <bits/stdc++.h> 
/* ---------------- Recursion ---------------------- */
/*int func(int n, vector<int>& nums){
    //Base cases.
    if(n == 0) return nums[n];
    if(n < 0) return 0;
    
    int pick = nums[n] + func(n - 2, nums);
    int not_pick = 0 + func(n-1, nums);
    
    return max(pick, not_pick);
}*/

/* ---------------------- Memoization ------------------ */
/*int func(int n, vector<int>& nums, vector<int>& dp){
    //Base cases.
    if(n == 0) return nums[n];
    if(n < 0) return 0;
    
    if(dp[n] != -1) return dp[n];
    int pick = nums[n] + func(n - 2, nums, dp);
    int not_pick = 0 + func(n-1, nums, dp);
    
    return dp[n] = max(pick, not_pick);
}*/

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    /* ---------------- Recursion ---------------------- */
    int n = nums.size();
    /* return func(n-1, nums); */
/* ---------------------- Memoization ------------------ */
    /*vector<int> dp(n, -1);
    return func(n-1, nums, dp);*/
    
/* --- Tabulation with space optimization TC = O(n) and SC = o(1) --- */
    int prev = nums[0];
    int prev2 = 0;
    
    for(int i=1; i<n; i++){
        int pick = nums[i];
        if(i > 1) pick += prev2;
        
        int not_pick = 0 + prev;
        
        int curr = max(pick, not_pick);
        
        prev2 = prev;
        prev = curr;
    }
    return prev;
    
}