//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&m){
	    // Code here
	    int n=m.size();
	   // int m=ma[0].size();
	   for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	           if(m[i][j]==-1){
	               m[i][j]=1e8;
	           }
	       }
	   }
	   
	   for(int k=0;k<n;k++){
	       for(int i=0;i<n;i++){
	           for(int j=0;j<n;j++){
	               
	               m[i][j]=min(m[i][k]+m[k][j],m[i][j]);
	               
	           }
	       }
	   }
	   for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	           if(m[i][j]==1e8){
	               m[i][j]=-1;
	           }
	       }
	   }
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends