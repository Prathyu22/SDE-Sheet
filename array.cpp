//https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#

// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> sumset;
        
        //Traverse through array and store prefix sums.
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            //If prefix sum is 0 or already present in unordered_set ......
            if(sum == 0 || sumset.find(sum) != sumset.end())    return true;
            
            sumset.insert(sum);
        }
        
        return false;
        
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends