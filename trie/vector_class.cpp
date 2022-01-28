class Trie {
private : 
    vector<vector<int>> trie;
        int node=0;
        vector<int> hotnode;
public:
    Trie() {
        trie.clear();
        hotnode.clear();
        node=0;
        trie.push_back(vector<int>(26,-1));
        hotnode.push_back(0);
    }
    
    void insert(string word) {
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(trie[cnt][word[i]-'a']==-1)
            {
                trie.push_back(vector<int>(26,-1));
                hotnode.push_back(0);
                trie[cnt][word[i]-'a']=++node;
            }
            cnt=trie[cnt][word[i]-'a'];
        }
        hotnode[cnt]=1;
    }
    
    bool search(string word) {
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(trie[cnt][word[i]-'a']==-1)
            {
               return false;
            }
            cnt=trie[cnt][word[i]-'a'];
        }
        if(hotnode[cnt]==1)
            return true;
        return false;
    }
    bool startsWith(string prefix) {
            int n=prefix.size();
            int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(trie[cnt][prefix[i]-'a']==-1)
            {
               return false;
            }
            cnt=trie[cnt][prefix[i]-'a'];
        }

            return true;
      
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
