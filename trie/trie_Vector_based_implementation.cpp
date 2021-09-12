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
ll M =1e9+7;
ll mod( ll m ,ll mod = M) {
   m %= mod;
   return (m + mod) % mod;
}
 const long  long int MAXN=1E6;
const long  long int MAXC=26;

vector<vector<int>> trie (1,vector<int > (26,-1));
vector<vector<int>>samepre (1,vector<int > (26,0));
int  nc=0;
void init()
{
    for(long  long int i=0;i<MAXN;i++)
    {
        for (long  long int j=0;j<MAXC;j++)
        {
            trie[i][j]=-1;
             samepre[i][j]=0;
        }
       
    }
}
int ans=0;
void insert(string s,string ss,int k)
{
	int cnt=0;
	int wgth=0;
	for(int i=0;i<s.size();i++)
	{
		wgth+=s[i]-'0';
		if(wgth>k)
		break;
		if(trie[cnt][ss[i]-'a']==-1)
		{
			trie.push_back(vector<int > (26,-1));	samepre.push_back(vector<int > (26,0));
			trie[cnt][ss[i]-'a']=++nc;
		}
				if(samepre[cnt][ss[i]-'a']==0)
				{
					ans++;
					samepre[cnt][ss[i]-'a']=1;
				}
		cnt=trie[cnt][ss[i]-'a'];
		
	}
}
int main()
{
fastio();
string s,ss;
cin>>s;
//init();
ss=s;
string f;
cin>>f;
ll k;
cin>>k;
set<ll> se;
f(i,sz(s))
{
	s[i]=1-(f[s[i]-'a']-'0')+'0';
}

//os(ss);
string feed,bound;
f(i,sz(s))
{
	//os(s[i]);
feed+=ss[sz(ss)-i-1];
bound+=s[sz(ss)-i-1];
reverse(all(feed));
reverse(all(bound));
//cout<<feed<<" "<<bound<<endl;
insert(bound,feed,k);
reverse(all(feed));
reverse(all(bound));
}
o(ans);

return 0;
}
//grAPH layering 
// knapsack
// dp //digitdp
//binary search
//dsu //square root decomposition //binary lifting 
// lca can be found using binary search and binary lifing
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
