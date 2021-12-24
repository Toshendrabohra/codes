// mos algorithm for calculating distinct elements in given range
// frequency array
lint hash1[1000005];

// block size
lint blk=1;

// query structure
struct query{
    lint l;
    lint r;
    lint idx;
};

// optimised sorting for mos algo
// odd even variations
bool compare(query p,query q) 
{
    if(p.l/blk!=q.l/blk)
        return p.l<q.l;
    return (p.l/blk&1)?(p.r<q.r):(p.r>q.r);
}

void add(lint &c,vector<lint> &arr,lint pos)
{
    if(hash1[arr[pos]]==0)
        c++;
    hash1[arr[pos]]++;
}

void del(lint &c,vector<lint> &arr,lint pos)
{
    hash1[arr[pos]]--;
    if(hash1[arr[pos]]==0)
        c--;
}

lint get(lint c,vector<lint> &arr)
{
    return c;
}

// offline queries without updates
// O((n+q)*sqrt(n)*f), where f is complexity of operations of ds 
// Q array should contain 0 based indexing queries
vector<lint> mos_algo(vector<query> Q,vector<lint> arr)
{
    blk=high(sqrt(arr.size()),1.00);
    sort(Q.begin(),Q.end(),compare);
    vector<lint> ans(Q.size());
    lint c=0; // mantain required ds
    lint l=0;
    lint r=-1;
    for(query q:Q)
    {
        while(l>q.l)
        {
            l--;
            add(c,arr,l);
        }
        while(r<q.r)
        {
            r++;
            add(c,arr,r);
        }
        while(l<q.l)
        {
            del(c,arr,l);
            l++;
        }
        while(r>q.r)
        {
            del(c,arr,r);
            r--;
        }
        ans[q.idx]=get(c,arr);
    }
    return ans;
}
