#include <bits/stdc++.h>
using namespace std;
const long  long int MAXN=1E6;
const long  long int MAXC=26;

long  long int trie[MAXN][MAXC];
long  long int nc=0,samepre[MAXN][MAXC];
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
void insert(const string s)
{
   long  long  int cnt=0;
    for (long  long int i=0;i<s.size();i++)
    {
        if(trie[cnt][s[i]-'a']==-1)
        trie[cnt][s[i]-'a']=++nc;
        samepre[cnt][s[i]-'a']++;
        cnt=trie[cnt][s[i]-'a'];
    }
}
long  long int count(const string s)
{
   long  long int cnt=0;
  long  long  int ans=0;
 for (long  long int i=0;i<s.size();i++)
 {ans=samepre[cnt][s[i]-'a'];
          cnt=trie[cnt][s[i]-'a'];
          if(cnt==-1)
          return 0;
 }
 return ans;
}
int main()
{
  long  long int n;
   cin>>n;
   init();
   for(long  long int i=0;i<n;i++)
   {
       string a,b;
       cin>>a>>b;
       if(a=="add")
       {
          insert(b) ;
 
      }
      else
      {
          cout<<count(b)<<endl;
      }
      
   }

    return 0;
}



