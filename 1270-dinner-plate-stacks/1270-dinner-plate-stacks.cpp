class DinnerPlates {
public:
    vector<stack<int>> v;
    set<int> left, right;
    int cap; 
    DinnerPlates(int capacity) {
        this->cap = capacity;
    }
    
    void push(int val) {
        if(left.empty()){
            stack<int> st;
            st.push(val);
            v.push_back(st);
            if(st.size() < cap){
                left.insert(v.size() - 1);
            }
            right.insert(v.size() - 1);
        }
        else{
            int tp = *left.begin();
            v[tp].push(val);
            if(v[tp].size() == cap){
                left.erase(tp);
            }
            right.insert(tp);
        }
    }
    
    int pop() {
        if(right.empty())
            return -1;
        int tp = *right.rbegin();
        int res = v[tp].top();
        v[tp].pop();
        if(v[tp].empty()){
            right.erase(tp);
        }
        left.insert(tp);
        return res;
    }
    
    int popAtStack(int index) {
        if(index > v.size() || v[index].empty())
            return -1;
        int res = v[index].top();
        v[index].pop();
        if (v[index].empty()){
            right.erase(index);
        }
        left.insert(index);
        return res;

    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */