class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        this->parent = vector<int> (n, -1);
        this->size = vector<int> (n,0);
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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU dsu(n);
        DSU tmp(n);
        for(int i=0;i<n;i++){
            dsu.make_set(i);
            tmp.make_set(i);
        }
        vector<bool> ans;
        for(auto &req : requests){
            tmp.union_sets(req[0], req[1]);
            bool flag = false;
            for(auto &res:restrictions){
                if(tmp.find_sets(res[0]) == tmp.find_sets(res[1])){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans.push_back(false);
                tmp = dsu;
            }
            else{
                ans.push_back(true);
                dsu.union_sets(req[0], req[1]);
            }
        }
        return ans;
    }
};