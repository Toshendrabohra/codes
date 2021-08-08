#include<bits/stdc++.h>

#define fill(arr,c) memset(arr,c,sizeof(arr))
#define perm(r) next_permutation(all(r))
//it gives bool value ans permute the string lexoggraphically
#define sortdesc greater<int>()
#define ll long long int 
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
using namespace std;

void fastio()
{
    	ios::sync_with_stdio(0);
cin.tie(0);

}
ll parent[(ll)1e5+7];
ll size[(ll)1e5+7];
ll cnt=0;
ll mod=(ll)1e9+7;
int findset(ll a)
{
	if(parent[a]==a)
	return a;
	return parent[a]=findset(parent[a]);
}
void makeunion(ll a,ll b)
{
	a=findset(a);
	b=findset(b);
	if(a!=b)
	{
	
	if(a<b)
	{
		swap(a,b);
	}
	cnt--;
	size[a]+=size[b];
	parent[b]=a;
}
}
int main()
{
fastio();
ll n,k;
cin>>n>>k;
cnt=n;
ll a,b;
fo(i,n)
{
parent[i]=i;
size[i]=1;
}
f(i,k)
{
	cin>>a>>b;
	while(a<b)
	{
		makeunion(a,b);
		a++;
		b--;
	}
}
ll ans=1;
f(i,cnt)
{
	ans=(ans*26)%mod;
}
//os(cnt);
o(ans);
return 0;
}
