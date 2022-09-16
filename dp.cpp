//https://www.codingninjas.com/codestudio/problems/house-robber_839733?leftPanelTab=1

#include <bits/stdc++.h> 

long long int maximumNonAdjacentSum(vector<int> &nums){
    long long int n = nums.size();
    long long int prev = nums[0];
    long long int prev2 = 0;
    for(int i=1; i<n; i++){
        long long int pick = nums[i];
        if(i > 1) pick += prev2;
        long long int not_pick = 0 + prev;
        long long int curr = max(pick, not_pick);   
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    long long int n = valueInHouse.size();
    vector<int> temp1, temp2;
    if(n == 1) return valueInHouse[0];
    
    for(int i=0; i<n; i++){
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }
    
    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}