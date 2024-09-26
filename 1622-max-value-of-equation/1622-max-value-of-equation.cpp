class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        multiset<int, greater<int>> st;
        int n = points.size();
        int ptr2 = 1;
        int ans = -1e9;
        for(int i=0;i<n;i++){
            if(i>0) {
                if(st.count(points[i][0]+points[i][1]))
                    st.erase(st.find(points[i][0]+points[i][1]));
            }
            ptr2 = max(ptr2, i+1);
            while(ptr2 < n and points[ptr2][0] - points[i][0] <= k){
                st.insert(points[ptr2][1] + points[ptr2][0]);
                ptr2++;
            }
            if(st.size())
                ans = max(ans, points[i][1]-points[i][0] + *st.begin());
            // cout << st.size() << " " << ans << endl;
        }
        return ans;
    }
};