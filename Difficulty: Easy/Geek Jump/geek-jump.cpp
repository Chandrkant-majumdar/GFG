//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     
     int f(int i,int n,vector<int>&h,vector<int>&dp){
        //  if(prev==-1) return h[0];
         if(i>=n) return 0;
          if(i==n-1) return 0;
          if(dp[i]!=-1) return dp[i];
         int tk=abs(h[i+1]-h[i])+f(i+1,n,h,dp);
         int nt=INT_MAX;
         if(i+2<n)
          nt=abs(h[i+2]-h[i])+f(i+2,n,h,dp);
         return dp[i]=min(tk,nt);
     }
    int minimumEnergy(vector<int>& g, int n) {
        // Code here
        vector<int>dp(n,-1);
        return f(0,n,g,dp);
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
    }
    return 0;
}
// } Driver Code Ends