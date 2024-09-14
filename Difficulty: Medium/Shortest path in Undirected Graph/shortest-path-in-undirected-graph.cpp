//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& e, int N,int M, int src){
        // code here
        vector<int>adj[N];
        for(auto x:e){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        vector<int>d(N,1e9),vis(N,0);
        d[src]=0;
        vis[src]=1;
        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            for(auto x:adj[node]){
                if(!vis[x] &&( dis+1<d[x])){
                    vis[x]=1;
                    d[x]=dis+1;
                    q.push({x,d[x]});
                }
            }
        }
        for(auto &x:d){
            if(x==1e9){
                x=-1;
            }
        }
        return d;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends