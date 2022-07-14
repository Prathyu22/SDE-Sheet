//https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here  
        int min_len = n;
        int sum = 0;
        int i = 0, j = 0;
        
        for(j=0; j<n; j++)
        {
            sum = sum + arr[j];
            while(sum > x)
            {
                min_len = min(min_len, j-i+1);
                sum = sum - arr[i++];
            }
        }
        return min_len;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends