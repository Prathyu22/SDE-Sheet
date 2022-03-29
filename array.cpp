//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1


// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        sort(arr, arr+n);
        
        int minele = arr[0];
        int maxele = arr[n-1];
        int diff = maxele - minele;
        
        for(int i=0; i<n; i++)
        {
            maxele = max(arr[n-1]-k, arr[i-1]+k);
            minele = min(arr[0]+k, arr[i]-k);
            
            if(minele < 0)
             continue;
            
            diff = min(diff, maxele - minele);
        }
        
        return diff;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends