class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end());
        sort(verticalCut.begin(),verticalCut.end());      
        int h=1,v=1;
        long long cost = 0;
        m-=2;n-=2;
        while(m >=0 and n >= 0){
            if(horizontalCut[m] > verticalCut[n]){
                cost += horizontalCut[m]*v;
                h++;
                m--;
            }
            else{
                cost += verticalCut[n]*h;
                v++;
                n--;
            }
        }
        while(m >= 0){
            cost += horizontalCut[m]*v;
                h++;
                m--;
        }
        while(n >= 0){
            cost += verticalCut[n]*h;
                v++;
                n--;
        }
        return cost;
    }
};