class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>lexo(n+1);
        lexo[0] = "00";
        for(int i = 1 ;i <= n;i++){
            lexo[i] = to_string(i);
        }
        sort(lexo.begin() , lexo.end());
        vector<int>result;
        for(int i = 1;i <= n;i++){
            result.push_back(stoi(lexo[i]));
        }

        return result;
    }
};