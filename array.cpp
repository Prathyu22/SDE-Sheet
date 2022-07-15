//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#

// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complete the function
        int total = 0; // no. of elements <= K
        int swap_count = 0;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] <= k)
              total++;
        }
        
        // first sliding window
        for(int i=0; i<total; i++)
        {
            if(arr[i] > k)
              swap_count++;
        }
        
        //leaving one element from left and 
        //adding one element in the right part like a sliding window.
        int i = 0;
        int j = total;
        int min_swaps = swap_count; // "min" holds min no. of swaps.
        while(j<n)
        {
            if(arr[i] > k)
              swap_count--;
            
            if(arr[j] > k)
              swap_count++;
            
            min_swaps = min(min_swaps,swap_count);
            
            i++;
            j++;
        }
        return min_swaps;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends