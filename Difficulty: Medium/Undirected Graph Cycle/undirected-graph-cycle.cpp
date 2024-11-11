//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool helper()
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                 q.push({i,-1});
        vis[i]=1;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int node=t.first;
            int par=t.second;
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push({x,node});
                }
                else if(x!=par){
                    return true;
                }
            }
        }
            }
        }
       
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends