#include<bits/stdc++.h>

#define fill(arr,c) memset(arr,c,sizeof(arr))
#define perm(r) next_permutation(all(r))
//it gives bool value ans permute the string lexoggraphically
#define sortdesc greater<int>()
#define ll  int 
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
int up[200005][20];
vector<vector<ll>> tree;
vector<int> lvl;
void binary_lifting(int cur,int par)
{//os(cur);
if(cur==1)
lvl [ cur ]=0;
else
lvl [cur ] = lvl [par] +1 ;

	up[cur][0]=par;
	fo(i,19)
	{
		if(up[cur][i-1]!=-1)
		{
			up[cur][i]=up[up[cur][i-1]][i-1];
		}
		else
		up[cur][i]=-1;
	}
	for(auto i:tree[cur])
	{
		if(i!=par)
		{
			binary_lifting(i,cur);
		}
	}
}
int ans_query(int cur,int dis)
{int ans=cur;
	for(int i=19;i>=0;i--)
	{
		if(ans!=-1 && (dis&(1<<i)))
		{
		
		ans=up[ans][i];
	//	os(ans);
	}
	}
	return ans;
}
int find_Lca(int node1,int node2)
{
	int lv=min(lvl[node1],lvl[node2]);
	//os(lv);
	int l=0,r=lv;
	int ans=lv;
	int x=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
	//	os(mid);os(lvl[node1]-mid);os(lvl[node2]-mid);en;
		if(ans_query(node1,lvl[node1]-mid)==ans_query(node2,lvl[node2]-mid))
		{
			l=mid+1;
			if(x<mid)
			{
			//	os(mid);
				x=mid;
				ans=ans_query(node1,lvl[node1]-mid);
			}
		
		}
		else
		{
			r=mid-1;
			
		}
	}
	return ans;
}
int main()
{
fastio();
ll n,q;
cin>>n>>q;
tree.resize(n+1);
lvl.resize( n+1 );

fo(i,n-1)
{
	ll x;
	cin>>x;
	tree[x].in(i+1);
	tree[i+1].in(x);
}
memset(up,-1,sizeof(up));
binary_lifting(1,-1);
f(i,q)
{
	ll node1,node2;
	cin>>node1 >> node2;
	int ans=find_Lca(node1,node2);
	cout<<ans<<endl;
}
return 0;
}
//grAPH layering 
// knapsack
// dp //digitdp
//binary search
//dsu //square root decomposition //binary lifting 

// * int over/under flow?
// * modulo mistake (forgot? / incorrect for -ve?)
// * array bounds? 
// * variable uninitialized?
// * dont get stuck in one approach
// * can it be reduced? (to graph? to bsearch? to NP-hard?)
// * Is there any special constraint to be exploited?
// * special cases (n=0,1? division by 0 somewhere?)
// * review precision error? missing typecasts?
// *cin.ignore() before getline for whitespaces ignored due to cin
// *segtree //*fenwicktreee //*kmp 

// *docker exec -ti my_container sh -c "echo a && echo b"
