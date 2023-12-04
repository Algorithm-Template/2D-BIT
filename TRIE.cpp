struct TRIE {
    vector<int>t;
    int cnt;
    TRIE() {
        t.resize(26, -1);
        cnt=0;
    }
    int &operator[](int x) {
        return t[x-'a'];
    }
};
vector<TRIE> trie(1);
void insert(string &s) {
    int root =0;
    for(char &x: s) {
        if(trie[root][x]==-1) trie[root][x] = trie.size(), trie.emplace_back();
        root = trie[root][x];
        trie[root].cnt++;
    }
}
int similiraty(string &s) {
    int root = 0, res=0;
    for(char &x: s) {
        if(trie[root][x]==-1) break;
        root=trie[root][x];
        res+=trie[root].cnt;
    }
    return res;
}
