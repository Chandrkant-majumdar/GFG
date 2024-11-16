//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int node,vector<vector<int>>& adj,vector<int>&vis,vector<int>&ans){
        vis[node]=1;
       
        for(auto x:adj[node]){
            if(!vis[x]){
                dfs(x,adj,vis,ans);
            }
        }
         ans.push_back(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
          int n=adj.size();
        vector<int>vis(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,ans);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    vector<int> topologicalSort1(vector<vector<int>>& adj) {
        // Your code here
         int n=adj.size();
        vector<int>vis(n,0);
        vector<int>in(n,0);
        vector<int>ans;
        // vector<int>par(n,0);
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                in[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
                vis[i]=1;
                
            }
        }
         
       
        while(!q.empty()){
            auto node=q.front();
            q.pop();
           ans.push_back(node);
            for(auto x:adj[node]){
                if(!vis[x]){
                    
                    in[x]--;
                    if(in[x]==0){
                         q.push(x);
                         vis[x]=1;
                    }
                   
                }
                
            }
        }
           
    //   for(auto x:ans) cout<<x<<" ";
    //   cout<<endl;
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends