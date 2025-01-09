class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for(int i = 0; i < words.size(); i++){
            if(words[i].size() < pref.size()) continue;
            else if(contain(words[i], pref)) count++;
        }

        return count;
    }

    bool contain(string str1, string pre){
        for(int i = 0; i < pre.size(); i++){
            if(str1[i] != pre[i]) return false;
        }

        return true;
    }
};