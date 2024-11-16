//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<vector<int>>& adj,vector<int>&vis,stack<int>&t){
	    vis[node]=1;
	  
	    for(auto x:adj[node]){
	        if(!vis[x]){
	            dfs(x,adj,vis,t);
	        }
	    }
	      t.push(node);
	}
		void dfs1(int node,vector<int> adj[],vector<int>&vis){
	    vis[node]=1;
	  
	    for(auto x:adj[node]){
	        if(!vis[x]){
	            dfs1(x,adj,vis);
	        }
	    }
	      
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {  
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int>adjR[V];
        
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                adjR[x].push_back(i);
                // cout<<x<<" "<<i<<endl;
            }
        }
        vector<int>vis1(V,0);
        int ans=0;
        while(!st.empty()){
            int node =st.top();
            st.pop();
           
                if(!vis1[node]){
                    ans++;
                    dfs1(node,adjR,vis1);
                }
            }
            
        
        return ans;
        
        
        
        
        //code here
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends