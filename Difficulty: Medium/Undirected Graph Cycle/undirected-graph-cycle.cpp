//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // Method 1 (using BFS)
    bool bfs(int V,vector<int>adj[],vector<int>&vis){
         // Code here
        // vector<int>vis(V,0);
        queue<pair<int,int>>q;
        q.push({V,-1});
        vis[V]=1;
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto nbr:adj[node]){
                if(!vis[nbr]){
                    vis[nbr]=1;
                    q.push({nbr,node});
                }else if(nbr!=par){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(bfs(i,adj,vis))
               return true;
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
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends