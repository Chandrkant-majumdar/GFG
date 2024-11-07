//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int f(int i,vector<int>& h,vector<int>&dp){
         
         if(i==0) return 0;
         
         if(i<0) return 1e9;
         
         if(dp[i]!=-1) return dp[i];
         
         int os=(i-1>=0)?abs(h[i]-h[i-1])+f(i-1,h,dp):1e9;
         int ts=(i-2>=0)?abs(h[i]-h[i-2])+f(i-2,h,dp):1e9;
         
         return dp[i]=min(os,ts);
     }
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        vector<int>dp(n,-1);
        return f(n-1,h,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends