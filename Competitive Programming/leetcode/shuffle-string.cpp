class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string answer(indices.size(),'a');
        for(int i=0;i<s.size();i++){
            answer[indices[i]] = s[i];
        }
        return answer;
    }
};