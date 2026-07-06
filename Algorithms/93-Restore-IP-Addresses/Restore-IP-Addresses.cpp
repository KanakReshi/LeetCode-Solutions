class Solution {
    int comas = 0;
public:
    bool isValid(string& s, int start, int end) {
        if (start > end || end >= s.size())
            return false;

        if (end - start + 1 > 3)
            return false;

        if (s[start] == '0' && start != end)
            return false;

        int num = 0;
        for (int i = start; i <= end; i++)
            num = num * 10 + (s[i] - '0');

        return num <= 255;
    }

    void create(string& s, int start, int end, string& temp, vector<string>& result,int &comas) {
        if(comas > 3){
            return;
        }
         if (end == s.size()) {
            if (comas == 3 && isValid(s, start, end - 1))
                result.push_back(temp);
            return;
        }
        if (isValid(s, start, end)) {
            temp.push_back(s[end]);
            temp.push_back('.');
            comas++;
            create(s, end + 1, end + 1, temp, result,comas);
            comas--;
            temp.pop_back();
            temp.pop_back();
            temp.push_back(s[end]);
            create(s, start, end + 1, temp, result,comas);
            temp.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string temp;
        int comas = 0;
        create(s, 0, 0, temp, result,comas);
        return result;
    }
};