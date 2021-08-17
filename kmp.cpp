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
//  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

void fastio()
{
    	ios::sync_with_stdio(0);
cin.tie(0);

}
vector<int> kmptable(string s)
{
 int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main()
{
//fastio();

ll n;
cin>>n;
string a,b;
cin>>a>>b;
b+=b.substr(0,n-1);
//os(b);
ll cnt=0;ll ans=0;
int x=0;
vector<int> table=kmptable(a);

f(i,sz(b))
{//os(x);
//os(table[i%n]);
		if(cnt<x)
		{
			cnt=x;
			ans=i-x;
			//os(i);os('a');
		}
while(b[i]!=a[x] && x!=0)
		{
			x=table[x-1];
		}
	
	if(b[i]==a[x])
	{
		x++;
	}

	
	
	
}
		if(cnt<x)
		{
			cnt=x;
			ans=n-(x-1);
			//os(i);os('a');
		}

os(ans);//os(cnt);
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
