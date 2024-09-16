//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Dis{
    vector<int>par,size;
    public:
    Dis(int n){
        par.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            size[i]=1;
        }
    }
    int findP(int node){
        if(node==par[node]) return node;
        
        return par[node]=findP(par[node]);
    }
    void U(int u,int v){
        int up=findP(u);
        int vp=findP(v);
        if(up==vp) return;
        
        if(size[u]<size[v]){
            size[v]+=size[u];
            par[up]=vp;
        }
        else{
            size[u]+=size[v];
            par[vp]=up;
        }
    }
};
class Solution
{
	public:
	int spanningTree(int V, vector<vector<int>> adj[]){
	    Dis ds(V);
	    vector<pair<int,pair<int,int>>>edges;
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            int u=i;
	            int v=x[0];
	            int w=x[1];
	            edges.push_back({w,{u,v}});
	        }
	    }
	    int ans=0;
	    sort(edges.begin(),edges.end());
	    for(auto x:edges){
	        int u=x.second.first;
	        int v=x.second.second;
	        int w=x.first;
	        if(ds.findP(u)!=ds.findP(v)){
	            ds.U(u,v);
	            ans+=w;
	        }
	    }
	    return ans;
	    
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    // int spanningTree1(int V, vector<vector<int>> adj[])
    // {
        // code here
        // int 
        // vector<pair<int,int>>adjN[V];
        // for(int i=0;i<V;i++){
        //     for(auto x:adj[i]){
        //         int u=x[0];
        //         int v=x[1];
        //         int w=x[2];
        //         adjN[u].push_back({v,w});
        //          adjN[v].push_back({u,w});
        //     }
        // }
    //     int sum=0;
    //     vector<int>vis(V,0);
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //     pq.push({0,0});
    //     while(!pq.empty()){
    //         int ms=pq.top().first;
    //         int node=pq.top().second;
    //         pq.pop();
    //         if(vis[node]) continue;
    //         vis[node]=1;
    //         sum+=ms;
    //         for(ato nbr:adj[node]){
    //             // int u=nbr[0];
    //             int v=nbr[0];
    //             int w=nbr[1];
    //             if(!vis[v])
    //             pq.push({w,v});
    //         }
    //     }
        
    //     return sum;
    // }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends