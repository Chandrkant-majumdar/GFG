//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int f(int i,int j,vector<int>& h,vector<int>&dp){
    //   if(i>=n) return 0;
    int n=h.size();
       if(i>=n-1) return 0;
       
       if(dp[i]!=-1) return dp[i];
       int ans=INT_MAX;
       for(int k=1;k<=j;k++){
           if(i+k<n){
               ans=min(ans,abs(h[i]-h[i+k])+f(i+k,j,h,dp));
           }
       }
       return dp[i]=ans;
   }
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n=arr.size();
        vector<int>dp(n,-1);
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
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends