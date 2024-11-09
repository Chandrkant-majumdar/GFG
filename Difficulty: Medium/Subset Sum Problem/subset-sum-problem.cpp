//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool f(int i,int sum,vector<int>& arr,vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(i==0){
            return (sum==arr[i]);
            
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool tk=(sum>=arr[i])?f(i-1,sum-arr[i],arr,dp):0;
        bool nt=f(i-1,sum,arr,dp);
        
        return dp[i][sum]=tk|| nt;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends