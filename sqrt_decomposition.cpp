// block size
lint blk=1;

vector<lint> create_sqrt_array(vector<lint> arr)
{
    lint n=arr.size();
    blk=high(sqrt(n),1.00);
    vector<lint> sqrt_array(blk,0);
    for(lint i=0;i<n;i++)
    {
        sqrt_array[i/blk]=sqrt_array[i/blk]+arr[i];
    }
    return sqrt_array;
}

// l and r are 1 based indexing
// O(sqrt(n)) query
lint sqrt_query(vector<lint> &arr,vector<lint> &sqrt_array,lint l,lint r)
{
    l--;
    r--;
    lint ans=0;
    lint l_blk=l/blk;
    lint r_blk=r/blk;
    if(l_blk==r_blk)
    {
        for(lint i=l;i<=r;i++)
        {
            ans=ans+arr[i];
        }
        return ans;
    }
    for(lint i=l;i<=(l_blk+1)*blk-1;i++)
        ans=ans+arr[i];
    for(lint i=l_blk+1;i<=r_blk-1;i++)
        ans=ans+sqrt_array[i];
    for(lint i=r_blk*blk;i<=r;i++)
        ans=ans+arr[i];
    return ans;
}

// pos is 1 based indexing
void sqrt_update(vector<lint> &arr,vector<lint> &sqrt_array,lint pos,lint val)
{

    pos--;
    lint prev=arr[pos];
    arr[pos]=val;
    lint blk_no=pos/blk;


    // for range dependent operations , O(sqrt(n))
    // min, max

    // lint minn=inf;
    // for(lint i=blk_no*blk;i<=(blk_no+1)*blk-1;i++)
    //     minn=min(minn,arr[i]);
    // sqrt_array[blk_no]=minn;


    // for range independent operations
    // sum , O(1)

    sqrt_array[blk_no]=sqrt_array[blk_no]+(arr[pos]-prev);

}
