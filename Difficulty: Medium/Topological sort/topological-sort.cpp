//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&st){
	    vis[node]=1;
	    for(auto x:adj[node]){
	        if(!vis[x]){
	            dfs(x,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    // 1.dfs
	   // vector<int>vis(V,0);
	   // stack<int>st;
	   // for(int i=0;i<V;i++){
	   //     if(!vis[i]){
	   //         dfs(i,vis,adj,st);
	   //     }
	   // }
	    
	   //vector<int>ans;
	   //while(!st.empty()){
	   //    ans.push_back(st.top());
	   //    st.pop();
	   //}
	   //return ans;
	   
	   // 2.bfs
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
	       q.pop();
	       ans.push_back(node);
	       for(auto nbr:adj[node]){
	           id[nbr]--;
	           if(id[nbr]==0){
	               q.push(nbr);
	           }
	       }
	   }
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
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
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

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends