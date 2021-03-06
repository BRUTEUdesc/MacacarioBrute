struct rollback_dsu{
    struct change{ int node, old_size;};
    stack<change> changes;
    vector<int> parent, size;
    int number_of_sets;
    
    rollback_dsu(int n){
        size.resize(n+5, 1);
        number_of_sets = n;
        for(int i = 0; i < n+5; ++i) parent.push_back(i);
    }
    
    int get(int a){ return (a == parent[a])? a: get(parent[a]);}
    bool same(int a, int b){ return get(a) == get(b);}
    void checkpoint(){ changes.push({-2, 0});}
    
    void join(int a, int b){
        a = get(a); b = get(b);
        if(a == b){ changes.push({-1, -1}); return;}
        if(size[a] > size[b]) swap(a, b);
        changes.push({a, size[b]});
        parent[a] = b;
        size[b] += size[a];
        --number_of_sets;
    }
    
    void rollback(int qnt = 1<<31){
        for(int i = 0; i < qnt; ++i){
            auto ch = changes.top();
            changes.pop();
            if(ch.node == -1) continue;
            if(ch.node == -2){
                if(qnt == 1<<31) break; 
                --i; continue;
            }
            size[parent[ch.node]] = ch.old_size;
            parent[ch.node] = ch.node;
            ++number_of_sets;
        }
    }
};
