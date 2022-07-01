// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int mod = 1e9+7;
    
    vector<vector<int>> metrixm(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        vector<vector<int>> ans(a.size(), vector<int> (b[0].size()));
        
        for( int i = 0; i < a.size(); i++)
        {
            for( int j = 0; j < b[0].size(); j++)
            {
                long long int cnt = 0;
                for( int k = 0; k < a[0].size(); k++)
                {
                    cnt = (cnt + ((long long int)a[i][k]*b[k][j])%mod)%mod;
                }
                ans[i][j] = cnt;
            }
        }
        
        return ans;
    }
    vector<vector<int>> power(vector<vector<int>> &cons, int p)
    {
        if(p == 1)
        return cons;
        
        vector<vector<int>> res = power(cons, p/2);
        
        res = metrixm(res,res);
        
        if(p%2)
        res = metrixm(res, cons);
        
        return res;
    }
    int FindNthTerm(long long int n) {
        // Code here
        if(n<=1)
        return 1;
        
        vector<vector<int>> f1, cons;
        f1.push_back({1});f1.push_back({1});
        cons.push_back({1,1});
        cons.push_back({1,0});
        
        vector<vector<int>> res = power(cons, n-1);
        vector<vector<int>> ans = metrixm(res,f1);
        
        return ans[0][0];
    }
};
        
                
  
  
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
