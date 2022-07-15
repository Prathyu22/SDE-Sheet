//https://practice.geeksforgeeks.org/problems/find-the-median0527/1#

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    // Code here.
		    sort(v.begin(),v.end());
		    int n = v.size();
		    int i = 0;
		    int j = n-1;
		    float median;
		    int mid = (i+j)/2;
		    
		    if(n%2 == 0)
		    {
		        median = (v[mid]+v[mid+1])/2;
		        return median;
		    }
		    else
		    {
		        return v[mid];
		    }
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends