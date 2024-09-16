//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int i,int j,vector<vector<int>>& m,vector<vector<int>>&dp){
        int n=m.size();
        if(i==n-1){
            int t=INT_MIN;
            for(int k=0;k<=2;k++){
                if(j!=k)
                t=max(t,m[n-1][k]);
            }
            return t;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=0;k<=2;k++){
                if(j!=k){
                    ans=max(ans,m[i][k]+f(i+1,k,m,dp));
                }
                // t=max(t,m[n-1][k]);
            }
            return  dp[i][j]=ans;
        
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        int ans=INT_MIN;
        int m=arr[0].size();
        for(int i=0;i<=2;i++){
            vector<vector<int>>dp(n,vector<int>(m,-1));
            ans=max(ans,f(0,i,arr,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends