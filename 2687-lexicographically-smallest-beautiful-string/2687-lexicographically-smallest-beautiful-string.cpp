class Solution {
public:
    string smallestBeautifulString(string s, int K) {
        int n = s.length();
        string ans(n, 'a');
        bool f= false;
        char t='a';
        for(int i=0;i<K-1;i++) t++;
        // cout<<t<<endl;
        int k=-1;
        for(int i=n-1;i>=0;i--){
            if(f){
                ans[i]=s[i];
                continue;
            }
            char c= s[i];
            for(char j=c+1;j<=t;j++){
                bool f1 = false, f2 = false;
                if(i-2>=0){
                    if(s[i-2]!=j){
                        f2= true;
                    }
                }
                else f2 = true;
                if(i-1>=0){
                    if(s[i-1]!=j){
                        f1= true;
                    }
                }
                else f1= true;
                if(f1&&f2){
                    k=i;
                    ans[i]=j;
                    f= true;
                    break;
                }
            }
        }
        for(int i=k+1;i<=n;i++){
            char c ='a';
            for(char j=c;j<=t;j++){
                 bool f1 = false, f2 = false;
                if(i-2>=0){
                    if(ans[i-2]!=j){
                        f2= true;
                    }
                }
                else f2 = true;
                if(i-1>=0){
                    if(ans[i-1]!=j){
                        f1= true;
                    }
                }
                else f1= true;
                if(f1&&f2){
                    ans[i]=j;
                    break;
                }
            }
        }
        if(ans<=s) return "";
        return ans;
    }
};