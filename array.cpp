//https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        int temp[n];
        int j = 0;
        
        // Storing positive numbers into temp array
        for(int i=0; i<n; i++)
        {
            if(arr[i]>0)
            {
                temp[j++] = arr[i];
            }
        }
        
        if(j==n||j==0)
        {
            return;
        }
        
        
        // Storing negative numbers into temp array
        for(int i=0; i<n; i++)
        {
            if(arr[i]<0)
            {
                temp[j++] = arr[i];
            }
        }
        
        //Copying contents of temp array to original array.
        memcpy(arr, temp, sizeof(temp));
        
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends