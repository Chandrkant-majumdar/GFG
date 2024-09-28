//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int f(int i,int k, vector<int>& arr,vector<int>&dp){
        
        if(i>=arr.size()) return 1e9;
         if(i==arr.size()-1) return 0;
         if(dp[i]!=-1) return dp[i];
       int ans=1e9;
       for( int j=1;j<=k;j++){
           int t=abs(arr[i]-arr[i+j])+f(i+j,k,arr,dp);
           ans=min(ans,t);
       }
       return dp[i]=ans;
   }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int>dp(arr.size(),-1);
        return f(0,k,arr,dp);
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
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends