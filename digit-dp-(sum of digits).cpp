#include<bits/stdc++.h>

#define fill(arr,c) memset(arr,c,sizeof(arr))
#define perm(r) next_permutation(all(r))
//it gives bool value ans permute the string lexoggraphically
#define sortdesc greater<int>()
#define ll long long   int 
//std::setfill('0') << std::setw(5) << 25; it adds leaing zeroes;
#define f(i,a) for(ll i=0;i<a;i++)
#define fo(i,a) for(ll i=1;i<=a;i++)
#define foo(i,x,n,c) for(ll i=x;i<n;i+=c)
#define foi(i,x,n,c) for(ll i=x;i>=n;i+=c)
#define fauto(i,m) for(auto i:m)
#define forall(a) for( auto itr=a.begin();itr!=a.end();itr++)
#define ld long double
#define in push_back
#define vl vector<ll >
#define o(a) cout<<a
#define os(a) cout<<a<<" "
#define en cout<<"\n";
#define testcase ll t ;cin>>t; while(t--)
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define sz(a)  (a).size()
#define prec(n) fixed<<setprecision(n)
#define mp make_pair
#define bitcount  __builtin_popcountll
#define imin o("imin");en;
//for interactive use endl after every output and fflush(stdout) after every input//
//  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

void fastio()
{
    	ios::sync_with_stdio(0);
cin.tie(0);

}
ll dp[19][170][2];
int sum(string b)
{
 long long  	int ans=0;
	f(i,sz(b))
	ans+=b[i]-'0';
	return ans;
}
ll cnt(int b)
{
 long long  	int n=0;
	while(b)
	{
		n++;
		b/=10;
	}
	return n;
}
 long long  int sumofdigits( long long  int n,string s, long long  int bound, long long  int sum)
{if(sum<0)
	return 0;

	else if(n==0 && sum==0)
	return 1;
	else if(n==0)
	return 0;
else 	if(dp[n][sum][bound]!=-1)
	return dp[n][sum][bound];
	else
	{
	 long long  	int ub=bound?s[sz(s)-n]-'0':9 ;
	 long long  	int ans=0;
		for(int i=0;i<=ub;i++)
		{
			ans+=sumofdigits(n-1,s,bound&(i==ub),sum-i);
		}
		dp[n][sum][bound]=ans;
	//	os(ans);os(sum);os(n);os(bound);en;
		return ans;
	}
}
int main()
{
fastio();
while(1)
{
	ll a,b;
	cin>>a>>b;
	
	if(a==-1 || b==-1)
	break;
	if(a>0)
	a--;
for(int i=0;i<19;i++)
			for(int j=0;j<170;j++)
				for(int k=0;k<2;k++)
					dp[i][j][k] = -1;
	ll n=cnt(b);
;
 long long  	int ans=0;
	for( long long  int i=0;i<=cnt(b)*9;i++)
	{  
	 ans+=sumofdigits(n,to_string(b),1,i)*i;  	
//os(i);	 os(dp[n][i][1]);;en;
	}
		for(int i=0;i<19;i++)
			for(int j=0;j<170;j++)
				for(int k=0;k<2;k++)
					dp[i][j][k] = -1;
//	sumofdigits(cnt(a),to_string(a),1,cnt(a)*9);
//	
	for( long long  int i=0;i<=cnt(a)*9;i++)
	{  
	 ans-=sumofdigits(cnt(a),to_string(a),1,i)*i;  	
	}
	o(ans);
	en;
		
}
return 0;
}
//grAPH layering 
// knapsack
// dp
//binary search
//dsu //square root decomposition //binary lifting 
