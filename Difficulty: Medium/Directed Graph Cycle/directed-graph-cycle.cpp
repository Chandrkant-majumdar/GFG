//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,int par,vector<int>adj[],vector<int>&vis,vector<int>&pas){
        vis[node]=1;
        pas[node]=1;
        for(auto nbr:adj[node]){
            if(!vis[nbr]){
                if(dfs(nbr,node,adj,vis,pas)) return true;
            }
            else if(pas[nbr]){
                return true;
            }
        }
        
        pas[node]=0;
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // 1.using Dfs
        // vector<int>vis(V,0),pas(V,0);
        
       
        
        // for(int i=0;i<V;i++){
        //     if(!vis[i] ){
        //         if(dfs(i,-1,adj,vis,pas)) return true;
        //     }
        // }
        // return false;
        
       // Using Topo sort
       vector<int>vis(V,0),id(V,0);
       for(int i=0;i<V;i++){
           for(auto x:adj[i]){
               id[x]++;
           }
       }
       queue<int>q;
       for(int i=0;i<V;i++){
           if(id[i]==0){
               q.push(i);
           }
       }
       vector<int>ans;
       while(!q.empty()){
           int node=q.front();
           ans.push_back(node);
           q.pop();
           for(auto nbr:adj[node]){
               id[nbr]--;
               if(id[nbr]==0){
                   q.push(nbr);
               }
           }
       }
       
       if(ans.size()==V) return false;
       
       return true;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends