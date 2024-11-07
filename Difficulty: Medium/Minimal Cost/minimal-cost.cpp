//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int i,int k,vector<int>& h,vector<int>& dp){
        int n=h.size();
        // if(i>=n) 1e9;
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1e9;
        for(int j=i+1;j<=i+k;j++){
            int cost=(j<n)?abs(h[i]-h[j])+f(j,k,h,dp):1e9;
            ans=min(cost,ans);
        }
        return dp[i]=ans;
        
    }
    int minimizeCost(int k, vector<int>& h) {
        // Code here
        int n=h.size();
        vector<int>dp(n,-1);
        return f(0,k,h,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends