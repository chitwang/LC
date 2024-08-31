class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            make_set(i);
        }
    }
    void make_set(int v){
        this->parent[v] = v;
        this->size[v] = 1;
    }
    int find_sets(int a){
        if(a == parent[a]){
            return a;
        }
        return parent[a] = find_sets(parent[a]);
    }
    int get_size(int a){
        int y = find_sets(a);
        return size[y];
    }
    void union_sets(int a, int b){
        a = find_sets(a);
        b = find_sets(b);
        if(a != b){
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};


class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n+1);
        for(int i = threshold + 1; i <= n;i++){
            for(int j=i; j<=n;j += i){
                dsu.union_sets(i, j);
            }
        }
        vector<bool> ans;
        for(auto &q:queries){
            ans.push_back(dsu.find_sets(q[0]) == dsu.find_sets(q[1]));
        }
        return ans;
    }
};