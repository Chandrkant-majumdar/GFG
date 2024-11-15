//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,int p,vector<vector<int>> &adj,vector<int>&vis,vector<int>&par){
        vis[node]=1;
        par[node]=1;
        for(auto x:adj[node]){
            if(!vis[x]){
                if(dfs(x,node,adj,vis,par)) return true;
            }else if(par[x]) return true;
        }
        par[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
         int n=adj.size();
        vector<int>vis(n,0);
        vector<int>par(n,0);
         for(int i=0;i<n;i++){
             if(!vis[i]){
                 if(dfs(i,-1,adj,vis,par)) return true;
             }
         }
         
         return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends