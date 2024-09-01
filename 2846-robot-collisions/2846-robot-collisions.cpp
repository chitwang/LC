struct robot{
    int position;
    int health;
    char dir;
    int index;
    robot(int p, int h, char d, int i) : position(p), health(h), dir(d), index(i) {};
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<robot> v;
        int n = positions.size();
        for(int i=0;i<n;i++){
            v.emplace_back(positions[i], healths[i], directions[i], i);
        }
        sort(v.begin(),v.end(), [](robot &a, robot &b){
            return a.position < b.position;
        });
        stack<robot> st;
        vector<robot> rem;
        for(int i=0;i<n;i++){
            if(v[i].dir == 'L'){
                while(!st.empty()){
                    auto r = st.top();
                    st.pop();
                    if(r.health > v[i].health){
                        r.health = r.health-1;
                        st.push(r);
                        break;
                    }
                    else if(v[i].health > r.health){
                        v[i].health = v[i].health-1;
                    }
                    else if(v[i].health  == r.health){
                        v[i].health = 0;
                        break;
                    }
                }
                if(st.empty() and v[i].health > 0){
                    rem.push_back(v[i]);
                }
            }
            else{
                st.push(v[i]);
            }
        }
        while(!st.empty()){
            rem.push_back(st.top());
            st.pop();
        }
        sort(rem.begin(), rem.end(), [](robot &a, robot &b){
            return a.index < b.index;
        });
        vector<int> ans;
        for(auto &it:rem){
            ans.push_back(it.health);
        }
        return ans;
    }
};