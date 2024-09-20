//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int f(int i,int j1,int j2,vector<vector<int>>& g,vector<vector<vector<int>>>&dp){
        int n=g.size();
        int m=g[0].size();
        if(i==n-1){
            return ((j1)==(j2))?g[i][j1]:g[i][j1]+g[i][j2];
        }
        
        
         int maxi=-1e9;
         if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        for(int c1=-1;c1<=1;c1++){
            for(int c2=-1;c2<=1;c2++){
                if(j1+c1>=0 && j2+c2>=0 && j1+c1<m && j2+c2<m){
                    
                    int tk=((j1)==(j2))?g[i][j1]+f(i+1,j1+c1,j2+c2,g,dp):g[i][j1]+g[i][j2]+f(i+1,j1+c1,j2+c2,g,dp);
                    maxi=max(maxi,tk);
                }
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& g) {
        // code here
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,g,dp);
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends