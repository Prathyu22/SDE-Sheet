//https://www.codingninjas.com/codestudio/problems/1112626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
/*
Find K-th Permutation Sequence
Problem Statement: Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) find the Kth permutation sequence.

For N = 3  the 3!  Permutation sequences in order would look like this:-



Note: 1<=K<=N! Hence for a given input its Kth permutation always exists

Examples:

Example 1:

Input: N = 3, K = 3
 
Output: “213”

Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 3 corresponds to the third sequence.

Example 2:

Input: N = 3, K = 5 

Result: “312”

Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 5 corresponds to the fifth sequence.
*/

#include <bits/stdc++.h>
using namespace std;

string kthPermutation(int n, int k) {
    // Write your code here. 
    int fact = 1;
    vector<int> num;
    for(int i=1; i<n; i++)
    {
        fact = fact * i;
        num.push_back(i);
    }
    num.push_back(n);
    string ans = "";
    k = k - 1;
    while(true)
    {
        ans = ans + to_string(num[k/fact]);
        num.erase(num.begin() + k/fact);
        if(num.size() == 0) break;
        k = k % fact;
        fact = fact / num.size();
    }
    return ans;
}
