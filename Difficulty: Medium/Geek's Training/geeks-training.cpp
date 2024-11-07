//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int day,int act,vector<vector<int>>& arr,vector<vector<int>>&dp){
        int n=arr.size();
        if(day==n-1){
            int ans=-1e9;
            for(int i=0;i<3;i++){
                if(act!=i)
                ans=max(ans,arr[day][i]);
            }
            
            return ans;
            
        }
        
        if(dp[day][act]!=-1) return dp[day][act];
        
        int ans=-1e9;
        for(int i=0;i<3;i++){
            if(i!=act){
                int t=arr[day][i]+f(day+1,i,arr,dp);
                ans=max(ans,t);
            }
        }
        return dp[day][act]=ans;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        
        int ans=-1e9;
        vector<vector<int>>dp(n,vector<int>(3,-1));
        for(int i=0;i<3;i++){
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
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends