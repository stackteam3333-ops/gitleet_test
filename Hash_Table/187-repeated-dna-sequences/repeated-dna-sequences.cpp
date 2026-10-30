class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> z;
        if(s.length()>10){
            unordered_map<string,int> e;
            for(int i=0;i<=s.length()-10;i++){
                string a = s.substr(i,10);
                if(e[a]==1) z.push_back(a);
                e[a]++;
            }
        }
        return z;
    }
};