//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& e){
        // code here
        vector<pair<int,int>>adj[N];
        vector<int>dis(N,1e9);
        for(auto x:e){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
            }
            set<pair<int,int>>s;
            dis[0]=0;
            s.insert({0,0});
            while(!s.empty()){
                auto it=*s.begin();
                int d=it.first;
                int node=it.second;
                s.erase(it);
                for(auto it:adj[node]){
                    int v=it.first;
                    int w=it.second;
                    if(d+w<dis[v]){
                     dis[v]=d+w;
                     s.insert({dis[v],v});
                    }
                }
            }
            
            for(auto &x:dis){
                if(x==1e9){
                    x=-1;
                }
            }
            return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends