class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int ans = 0;
        vector<int> freq(26,0);
        for(auto it:letters){
            freq[it-'a']++;
        }
        for(int bitmask = 0;bitmask<(1 << n);bitmask++){
            vector<int> tmp(26, 0);
            for(int i=0;i<n;i++){
                if(bitmask & (1 << i)){
                    for(auto it:words[i])
                        tmp[it-'a']++;
                }
            }
            int cur = 0;
            for(int i=0;i<26;i++){
                if(freq[i] < tmp[i]){
                    cur = 0;
                    break;
                }
                cur += score[i]*tmp[i];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};