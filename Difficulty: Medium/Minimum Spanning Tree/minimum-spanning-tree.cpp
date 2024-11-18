//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Dis{
    vector<int>size,par;
    public:
    Dis(int n){
        size.resize(n+1);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            size[i]=1;
        }
    }
    int findP(int node){
        if(node==par[node]) return node;
        
        return par[node]=findP(par[node]);
    }
    
    void uni(int u,int v){
        int u_p=findP(u);
        int v_p=findP(v);
        if(u_p==v_p) return;
        if(size[u_p]>size[v_p]){
            size[u_p]+=size[v_p];
            par[v_p]=u_p;
        }else{
            size[v_p]+=size[u_p];
            par[u_p]=v_p;
        }
    }
    
    
};

class Solution
{
	public:
	
	
	 int spanningTree(int V, vector<vector<int>> adj[]){
	     vector<pair<int,pair<int,int>>>e;
	     for(int i=0;i<V;i++){
	         for(auto ed:adj[i]){
	             int v=ed[0];
	             int w=ed[1];
	             e.push_back({w,{i,v}});
	         }
	     }
	     sort(e.begin(),e.end());
	      Dis d(V);
	     int sum=0;
	     for(auto x:e){
	         int wt=x.first;
	         int u=x.second.first;
	         int v=x.second.second;
	         if(d.findP(u)!=d.findP(v)){
	             sum+=wt;
	             d.uni(u,v);
	         }
	         
	     }
	     return sum;
	 }
	
	//prims
    int spanningTree1(int V, vector<vector<int>> adj[])
    {
        // code here
            
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(V,0);
        // vis[0]=1;
        int sum=0;
        vector<int>e;
        while(!pq.empty()){
            auto t=pq.top();
            int cost=t.first;
            pq.pop();
         
            int node=t.second;
            if(vis[node]) continue;
            vis[node]=1;
            e.push_back(node);
               sum+=cost;
            for(auto nbr:adj[node]){
                int wt=nbr[1];
                int v=nbr[0];
                
                // if(!vis[nbr])
                if(!vis[v]){
                     
                     pq.push({wt,v});
                }
               
            }
        }
        for(auto x:e){
            cout<<x<<" ";
        }
        cout<<endl;
        return sum;
    }
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
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends